/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 00:45:35 by fwong             #+#    #+#             */
/*   Updated: 2022/10/03 00:52:25 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_file(char *file, int ioo, char **path)
{
	if (ioo == 0)
	{
		if (access(file, F_OK | R_OK) == -1)
			return (1);
		return (open(file, O_RDONLY));
	}
	else
		return (open(file, O_CREAT | O_WRONLY | O_TRUNC, 0666));
}
