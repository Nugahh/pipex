/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:35:49 by fwong             #+#    #+#             */
/*   Updated: 2022/10/05 15:26:02 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec_fcmd(t_data data, int fd_pipe, char **cmd, char *file, char **path)
{
	int		fd_stdin;

	fd_stdin = dup(STDIN_FILENO);
	dup2(fd_pipe[1], STDOUT_FILENO);
	dup2(data.infile, STDIN_FILENO);
	close(pfd[0]);
	close(pfd[1]);
	if (execve(check_cmd(path, cmd[0]), cmd, NULL) == -1)
		perror("fcmd err: ");
	/* dup2(fd_stdin, STDIN_FILENO);
	close(fd);
	close(fd_stdin);
	exit(EXIT_SUCCESS); */
}

void	exec_lcmd(t_data data, int fd_pipe, char **cmd, char *file, char **path)
{
	int		fd_stdout;

	fd_stdout = dup(STDOUT_FILENO);
	dup2(fd_pipe[0], STDIN_FILENO);
	dup2(data.outfile, STDOUT_FILENO);
	close(pfd[0]);
	close(pfd[1]);
	if (execve(cat_cmd(path, cmd[0]), cmd, NULL);
/* 	dup2(fd_stdout, STDOUT_FILENO);
	close(fd);
	close(fd_stdout);
	exit(EXIT_SUCCESS); */
}

void	pipex(char **av, char **path)
{
	pid_t	pid;
	pid_t	pid2;
	int		fd_pipe[2];
	int		status;

	if (pipe(fd_pipe) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (perror("Fork : "));
	else if (pid == 0)
		exec_fcmd(t_data data, fd_pipe, ft_split(av[2], ' '), av[1], path);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("Fork : "));
	else if (pid2 == 0)
		exec_lcmd(t_data data, fd_pipe, ft_split(av[3], ' '), av[4], path);
	close(fd_pipe[1]);
	close(fd_pipe[0]);
	waitpid(&status);
}

int	main(int argc, char **argv, char **ev)
{
	t_data	data;
	char	**path;

	if (ac = 5)
	{
		init_struct(&data, argv);
		path = get_env_path(ev);
		if (check_file(av[1], 0) == -1)
			return (1);
		else if (check_file(av[4], 1) == -1)
			return (1);
		pipex(av, path);
		freetab(path);
	}
	else
		return (ft_putstr_fd("Not enough, or too many arguments\n", 2), 1);
	return (0);
}