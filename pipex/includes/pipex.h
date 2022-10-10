/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:42:20 by fwong             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/10 12:42:07 by fwong            ###   ########.fr       */
=======
/*   Updated: 2022/10/08 19:52:39 by fwong            ###   ########.fr       */
>>>>>>> 47ec1a1f232ae3a2daa9167478b2df4869676cb8
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"

// PATH and cmd
char		**get_path_and_split(char **envp);
char		*check_cmd(char	*cmd, char **paths);

// exec
void		exec_fcmd(int *fd_pipe, char **cmd, char *file, char **paths);
void		exec_lcmd(int *fd_pipe, char **cmd, char *file, char **paths);
void		pipex(char **argv, char **paths);

// utils
int			check_file(char *file, int ioo);
int			print_err(char *file);
void	ft_check_if_cmd_exist(char *path_cmd, char	**cmd);
void		free_paths(char **paths);

#endif