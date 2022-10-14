/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:42:20 by fwong             #+#    #+#             */
/*   Updated: 2022/10/14 03:42:22 by fwong            ###   ########.fr       */
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

typedef struct s_data
{
	char	**envp;
	int		fd_pipe[2];
}	t_data;

// PATH and cmd
char		**get_path_and_split(char **envp);
char		*check_cmd(char	*cmd, char **paths);

// exec
void		exec_fcmd(t_data *data, char **cmd, char *file, char **paths);
void		exec_lcmd(t_data *data, char **cmd, char *file, char **paths);
void		pipex(t_data *data, char **argv, char **paths);

// utils
int			check_file(char *file, int ioo);
void	ft_print_cmd_error2(char *path_cmd, char **paths, char **cmd);
void		ft_print_cmd_error(int ioo, char *path_cmd, char **paths,
				char **cmd);
void		ft_check_if_cmd_exist(char *path_cmd, char	**cmd);
void		free_paths(char **paths);

#endif