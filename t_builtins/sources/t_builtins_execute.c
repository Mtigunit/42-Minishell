/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_builtins_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:43:38 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_builtins.h"
#include "minilibc.h"

int	t_builtins_execute(int *status, char **argv, char **env)
{
	int	argc;

	if (!argv || !argv[0] || !status)
		return (0);
	argc = 0;
	while (argv[argc])
		argc++;
	if (ft_strcmp("echo", argv[0]) == 0)
		*status = 256 * t_builtins_echo(argc, argv, env);
	else if (ft_strcmp("pwd", argv[0]) == 0)
		*status = 256 * t_builtins_pwd(argc, argv, env);
	else if (ft_strcmp("env", argv[0]) == 0)
		*status = 256 * t_builtins_env(argc, argv, env);
	else if (ft_strcmp("unset", argv[0]) == 0)
		*status = 256 * t_builtins_unset(argc, argv, env);
	else if (ft_strcmp("cd", argv[0]) == 0)
		*status = 256 * t_builtins_cd(argc, argv, env);
	else if (ft_strcmp("exit", argv[0]) == 0)
		*status = 256 * t_builtins_exit(argc, argv, env);
	else if (ft_strcmp("export", argv[0]) == 0)
		*status = 256 * t_builtins_export(argc, argv);
	else
		return (0);
	return (1);
}
