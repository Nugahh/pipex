/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 00:45:35 by fwong             #+#    #+#             */
/*   Updated: 2022/10/05 15:33:58 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_file(t_data *data, char *file, int ioo)
{
	if (ioo == 0)
	{
		if (access(file, F_OK | R_OK) == -1)
			return (1);
		return (open(file, O_RDONLY));
	}
	else
		return (data->outfile = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0666));
}

int	print_err(char *file, char **path)
{
	ft_putstr_fd("./pipex : ", 2);
	ft_putstr_fd(file, 2);
	perror(" ");
	freetab(path);
	return (-1);
}

void	freetab(char **output)
{
	int	i;

	i = 0;
	if (!output)
		return ;
	while (output[i])
	{
		free(output[i]);
		++i;
	}
	free(output);
}

void	init_struct(t_data *data, char **argv)
{
	data->infile = open(argv[1], O_RDONLY);
	if (data->infile == -1)
		print_error();
	/* data->outfile = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (data->outfile == -1)
		print_error(); */
}