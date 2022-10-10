/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 00:45:35 by fwong             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/10 12:54:30 by fwong            ###   ########.fr       */
=======
/*   Updated: 2022/10/08 19:52:34 by fwong            ###   ########.fr       */
>>>>>>> 47ec1a1f232ae3a2daa9167478b2df4869676cb8
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	print_err(char *file)
{
	ft_putstr_fd(file, 2);
	perror(" ");
	return (-1);
}

void	ft_check_if_cmd_exist(char *path_cmd, char	**cmd)
{
	if (!path_cmd)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putstr_fd(cmd[0], 2);
		write(2, "\n", 1);
		free_paths(cmd);
		exit(1);
	}
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	if (!paths)
		return ;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}
