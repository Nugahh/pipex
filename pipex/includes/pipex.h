/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:42:20 by fwong             #+#    #+#             */
/*   Updated: 2022/10/07 16:02:50 by fwong            ###   ########.fr       */
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
void		free_paths(char **paths);

#endif