/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:42:20 by fwong             #+#    #+#             */
/*   Updated: 2022/10/05 15:39:07 by fwong            ###   ########.fr       */
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

# define P_IN 0;
# define P_OUT 1;

typedef struct s_data
{
	int		infile;
	int		outfile;
	int		status;
}	t_data;

// PATH and cmd
static char	**get_path_and_split(char **envp)
static char	**add_slash(char **path)
char		*check_cmd(char	*cmd, char **paths)


#endif