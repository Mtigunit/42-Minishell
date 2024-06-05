/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 02:27:56 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"

char	**ft_strsenv(const char *name)
{
	int			i;
	int			j;
	char		**env;

	env = ft_getenviron();
	if (!env || !name)
		return (NULL);
	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && (env[i][j] != '=') && (env[i][j] == name[j]))
			j++;
		if (((env[i][j] == '\0') || (env[i][j] == '=')) && (name[j] == 0))
			return (env + i);
		i++;
	}
	return (NULL);
}
