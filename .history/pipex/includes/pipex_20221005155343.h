/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:42:20 by fwong             #+#    #+#             */
/*   Updated: 2022/10/05 15:53:42 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include ""
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

typedef struct s_data
{
	int		infile;
	int		outfile;
}	t_data;

// PATH and cmd
static char	**get_path_and_split(char **envp);
static char	**add_slash(char **path);
char		*check_cmd(char	*cmd, char **paths);

// exec
void		exec_fcmd(t_data data, int fd_pipe, char **cmd, char **path);
void		exec_lcmd(t_data data, int fd_pipe, char **cmd, char **path);
void		pipex(char **av, char **path);

#endif