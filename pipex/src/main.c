/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:35:49 by fwong             #+#    #+#             */
/*   Updated: 2022/11/03 19:31:29 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	first_cmd(t_data *data, char **cmd, char *file, char **paths)
{
	int		infile;
	char	*path_cmd;

	infile = open(file, O_RDONLY);
	if (infile < 0)
	{
		close(data->fd_pipe[0]);
		close(data->fd_pipe[1]);
		ft_print_cmd_error(infile, NULL, paths, cmd);
	}
	dup2(data->fd_pipe[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(data->fd_pipe[0]);
	close(data->fd_pipe[1]);
	close(infile);
	path_cmd = check_cmd(cmd[0], paths);
	if (!path_cmd)
		ft_print_cmd_error(infile, path_cmd, paths, cmd);
	if (execve(path_cmd, cmd, data->envp) == -1)
		perror("First cmd error ");
}

void	second_cmd(t_data *data, char **cmd, char *file, char **paths)
{
	int		outfile;
	char	*path_cmd;

	outfile = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (outfile < 0)
	{
		close(data->fd_pipe[0]);
		close(data->fd_pipe[1]);
		ft_print_cmd_error2(outfile, NULL, paths, cmd);
	}
	dup2(data->fd_pipe[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(data->fd_pipe[0]);
	close(data->fd_pipe[1]);
	close(outfile);
	path_cmd = check_cmd(cmd[0], paths);
	if (!path_cmd)
		ft_print_cmd_error2(outfile, path_cmd, paths, cmd);
	if (execve(path_cmd, cmd, data->envp) == -1)
		perror("Second cmd error ");
}

void	pipex(t_data *data, char **argv, char **paths)
{
	pid_t	pid;
	pid_t	pid2;
	int		status;

	if (pipe(data->fd_pipe) == -1)
		return (perror(" "));
	pid = fork();
	if (pid == -1)
		return (perror("Fork "));
	else if (pid == 0)
		first_cmd(data, ft_split(argv[2], ' '), argv[1], paths);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("Fork "));
	else if (pid2 == 0)
		second_cmd(data, ft_split(argv[3], ' '), argv[4], paths);
	close(data->fd_pipe[1]);
	close(data->fd_pipe[0]);
	wait(&status);
	wait(&status);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	**paths;

	if (argc == 5)
	{
		data.envp = envp;
		paths = get_path_and_split(envp);
		pipex(&data, argv, paths);
		free_paths(paths);
	}
	else if (argc > 5)
		return (ft_putstr_fd("Too many arguments\n", 2), 1);
	else if (argc < 5)
		return (ft_putstr_fd("Not enough arguments\n", 2), 1);
	return (0);
}
