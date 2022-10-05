/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:47:41 by fwong             #+#    #+#             */
/*   Updated: 2022/10/05 15:43:10 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**get_path_and_split(char **envp)
{
	char	*path;
	char	**paths;
	int		i;

	i = 0;
	path = NULL;
	while (envp[i] != NULL && envp[i][0] != '\0')
	{
		path = ft_strnstr(envp[i], "PATH=", 5);
		if (path)
		{
			path = ft_substr(path, 5, ft_strlen(path) - 5);
			break ;
		}
		i++;
	}
	paths = ft_split(path, ':');
	if (path)
		free(path);
	return (paths);
}

static char	**add_slash(char **paths)
{
	int		i;
	
	i = -1;
	while (paths[++i])
		paths[i] = ft_strjoin(paths[i], "/");
	return (paths);
}

char	*check_cmd(char	*cmd, char **paths)
{
	char	*cmd_path;
	int		i;

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
	paths = add_slash(paths);
	i = -1;
	while (paths[++i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
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
	tab = split_and_add_slash(test);
	for (int i = 0; tab[i]; i++)
		printf("tab[i] = %s\n", tab[i]);
} */