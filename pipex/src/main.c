/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:35:49 by fwong             #+#    #+#             */
/*   Updated: 2022/10/06 20:54:32 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec_fcmd(int *fd_pipe, char **cmd, char *file, char **paths)
{
	int	infile;

	infile = check_file(file, 0);
	dup2(fd_pipe[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	// close(infile);
	if (execve(check_cmd(cmd[0], paths), cmd, NULL) == -1)
		perror("fcmd err: ");
}

void	exec_lcmd(int *fd_pipe, char **cmd, char *file, char **paths)
{
	int	outfile;

	outfile = check_file(file, 1);
	dup2(fd_pipe[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	// close(outfile);
	if (execve(check_cmd(cmd[0], paths), cmd, NULL) == -1)
		perror("lcmd err: ");
}

void	pipex(char **argv, char **paths)
{
	pid_t	pid;
	pid_t	pid2;
	int		fd_pipe[2];
	int		status;

	if (pipe(fd_pipe) == -1)
		return;
	pid = fork();
	if (pid == -1)
		return (perror("Fork : "));
	else if (pid == 0)
		exec_fcmd(fd_pipe, ft_split(argv[2], ' '),argv[1],  paths);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("Fork : "));
	else if (pid2 == 0)
		exec_lcmd(fd_pipe, ft_split(argv[3], ' '),argv[4], paths);
	close(fd_pipe[1]);
	close(fd_pipe[0]);
	waitpid(pid, &status, 0);
	waitpid(pid2, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;

	if (argc == 5)
	{
		paths = get_path_and_split(envp);
		if (check_file(argv[1], 0) == -1)
			return (1);
		else if (check_file(argv[4], 1) == -1)
			return (1);
		pipex(argv, paths);
		freetab(paths);
	}
	else
		return (ft_putstr_fd("Not enough, or too many arguments\n", 2), 1);
	return (0);
}