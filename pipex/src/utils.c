/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 00:45:35 by fwong             #+#    #+#             */
/*   Updated: 2022/10/30 19:19:15 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_print_cmd_error(int ioo, char *path_cmd, char **paths, char **cmd)
{
	if (ioo < 0)
	{
		free_paths(cmd);
		free_paths(paths);
		perror("Infile: ");
		exit(0);
	}
	if (!path_cmd)
	{
		free_paths(paths);
		free_paths(cmd);
		perror("First cmd error: ");
		exit(0);
	}
}

void	ft_print_cmd_error2(int ioo, char *path_cmd, char **paths, char **cmd)
{
	if (ioo < 0)
	{
		free_paths(cmd);
		free_paths(paths);
		perror("Outfile: ");
		exit(0);
	}
	if (!path_cmd)
	{
		free_paths(paths);
		free_paths(cmd);
		perror("Second cmd error: ");
		exit(0);
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
