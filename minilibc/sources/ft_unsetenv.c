/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:10:08 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"

int	ft_unsetenv(const char *name)
{
	char	**env;
	char	**envp;
	char	**new_env;
	char	*value;

	env = ft_getenviron();
	if (!env || !name || !*name)
		return (-1);
	envp = ft_strsenv(name);
	if (envp)
	{
		value = envp[0];
		envp[0] = NULL;
		new_env = ft_strsjoin(env, envp + 1);
		envp[0] = value;
		if (!new_env)
			return (-1);
		ft_strsfree(env);
		ft_setenviron(new_env);
	}
	return (0);
}
