/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:42:20 by fwong             #+#    #+#             */
/*   Updated: 2022/10/02 23:44:35 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

char	*cat_cmd(char **path, char *cmd);

char	**get_path(char **ev);

int		check_file(char *file, int ioo, char **path);
int		print_err(char *file, char **path);

void	exec_fcmd(int *pfd, char **cmd, char *file, char **path);
void	exec_lcmd(int *pfd, char **cmd, char *file, char **path);
void	freetab(char **output);
void	pipex(char **av, char **path);

#endif