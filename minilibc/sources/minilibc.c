/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:42:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

t_minilibc	*__minilibc(int argc, char **argv, char **env, int request)
{
	static t_minilibc	__table;

	if (request == MINILIBC_REQUEST_INIT)
	{
		__table.argc = argc;
		__table.argv = argv;
		if (env)
		{
			if (__table.env)
			{
				write(2, "error: already initialized!\n", 28);
				exit(1);
			}
			__table.env = ft_strsdup(env);
			if (!__table.env)
			{
				write(2, "error: minilibc could not be initialized.\n", 42);
				return ((t_minilibc *)0);
			}
		}
	}
	else if (request == MINILIBC_REQUEST_FINI)
		return (ft_strsfree(__table.env), __table.env = NULL, &__table);
	return (&__table);
}

__attribute__ ((constructor)) void	init(void)
{
	pid_t		pid;

	pid = fork();
	if (pid < 0)
	{
		ft_putstr_fd("error: fork() < 0\n", 2);
		ft_exit(1);
	}
	else if (pid == 0)
		ft_exit(0);
	else
	{
		pid = wait(&pid);
		__minilibc(0, NULL, NULL, MINILIBC_REQUEST_INIT)->pid = pid - 1;
	}
}
