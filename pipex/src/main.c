/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:35:49 by fwong             #+#    #+#             */
/*   Updated: 2022/10/03 00:55:07 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int argc, char **argv, char **envp)
{
    char *options[3] = {"ls", "-la", NULL};

    (void)argc;
    (void)argv;
    execve("/usr/bin/ls", options, envp);
    return (0);
}