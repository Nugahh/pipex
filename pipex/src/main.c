/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:35:49 by fwong             #+#    #+#             */
/*   Updated: 2022/10/10 19:12:56 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	first_cmd(int *fd_pipe, char **cmd, char *file, char **paths)
{
	int	infile;
	char	*path_cmd;

	infile = open(file, O_RDONLY);
	if (infile < 0)
	{
		free_paths(cmd);
		free_paths(paths);
		perror("Infile: ");
		exit(0);
	}
	dup2(fd_pipe[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	path_cmd = check_cmd(cmd[0], paths);
	if (!path_cmd)
	{
		free_paths(paths);
		free_paths(cmd);
		exit(0);
	}
	if (execve(path_cmd, cmd, NULL) == -1)
		perror("First cmd error ");
}

void	second_cmd(int *fd_pipe, char **cmd, char *file, char **paths)
{
	int		outfile;
	char	*path_cmd;

	outfile = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	dup2(fd_pipe[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	path_cmd = check_cmd(cmd[0], paths);
	if (!path_cmd)
	{
		free_paths(paths);
		free_paths(cmd);
		exit(0);
	}
	if (execve(path_cmd, cmd, NULL) == -1)
		perror("Second cmd error ");
}

void	pipex(char **argv, char **paths)
{
	pid_t	pid;
	pid_t	pid2;
	int		fd_pipe[2];
	int		status;

	if (pipe(fd_pipe) == -1)
		return (perror(" "));
	pid = fork();
	if (pid == -1)
		return (perror("Fork "));
	else if (pid == 0)
		first_cmd(fd_pipe, ft_split(argv[2], ' '), argv[1], paths);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("Fork "));
	else if (pid2 == 0)
		second_cmd(fd_pipe, ft_split(argv[3], ' '), argv[4], paths);
	close(fd_pipe[1]);
	close(fd_pipe[0]);
	wait(&status);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;

	if (argc == 5)
	{
		paths = get_path_and_split(envp);
	
		pipex(argv, paths);
		free_paths(paths);
	}
	else
		return (ft_putstr_fd("Not enough, or too many arguments\n", 2), 1);
	return (0);
}
