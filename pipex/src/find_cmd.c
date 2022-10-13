/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:47:41 by fwong             #+#    #+#             */
/*   Updated: 2022/10/13 19:54:36 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_path_and_split(char **envp)
{
	int		i;
	char	*path;
	char	**paths;

	i = -1;
	path = NULL;
	while (envp[++i] && !path)
		path = ft_strnstr(envp[i], "PATH=", 5);
	if (path)
		path = ft_substr(path, 5, ft_strlen(path) - 5);
	paths = ft_split(path, ':');
	if (path)
		free(path);
	return (paths);
}

char	*check_cmd(char	*cmd, char **paths)
{
	int		i;
	char	*cmd_path;
	char	*tmp;

	i = -1;
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (NULL);
}
