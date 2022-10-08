/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:47:41 by fwong             #+#    #+#             */
/*   Updated: 2022/10/08 19:43:07 by fwong            ###   ########.fr       */
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
	while (cmd[++i])
	{
		if (cmd[i] == '/')
		{
			if (access(cmd, F_OK | X_OK) == 0)
				return (cmd);
			return (NULL);
		}
	}
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

/* int	main()
{
	char *test = "/home/nugah/.local/bin:/usr/local/sbin:/usr/local/bin";
	char **tab = malloc(sizeof(char *) * 1000);
	tab = ft_split(test, ':');
	char *tmp;
	// check_cmd("cat", tab);
	for (int i = 0; tab[i]; i++)
	{
		tmp = ft_strjoin(tab[i], "/");
		tab[i] = ft_strjoin(tmp, "cat");
		free(tmp);
		printf("tab[i] = %s\n", tab[i]);
	}
} */