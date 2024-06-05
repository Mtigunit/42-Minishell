/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_builtins_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:22:09 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include "t_builtins.h"

int	t_builtins_env(
	__attribute__ ((unused)) int	argc,
	__attribute__ ((unused)) char	**argv,
	char							**env
)
{
	int	i;
	int	j;

	if (argc != 1)
	{
		ft_putendl_fd("env with no options or arguments", 2);
		return (1);
	}
	i = 0;
	while (env[i])
	{
		j = ft_varlen(env[i]);
		if (j > 0 && env[i][j] == '=')
			ft_putendl_fd(env[i], 1);
		i++;
	}
	return (0);
}
