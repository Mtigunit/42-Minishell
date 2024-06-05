/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:42:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include <stdlib.h>

char	*ft_getenvpair(const char *name, const char *value)
{
	int		j;
	char	*newnode;

	if (!name)
		return ((char *)0);
	j = 0;
	while ((name[j] != '\0') && (name[j] != '='))
		j++;
	if (value)
	{
		newnode = malloc(j + 1 + ft_strlen(value) + 1);
		ft_strncpy(newnode, name, j);
		newnode[j] = '=';
		ft_strcpy(newnode + j + 1, value);
	}
	else
		newnode = ft_strndup(name, j);
	return (newnode);
}

int	ft_envequals(const char *s1, const char *s2)
{
	int	j;

	if (!s1 || !s2)
		return (0);
	j = 0;
	while ((s1[j] != '\0') && (s1[j] != '=') && s2[j] == s1[j])
		j++;
	return ((j > 0)
		&& ((s1[j] == '\0') || (s1[j] == '='))
		&& ((s2[j] == '\0') || (s2[j] == '=')));
}

int	ft_addenv(char *name, char *value)
{
	char	**env;
	char	**new_env;
	char	*newnode;

	env = ft_getenviron();
	if (!env || !name || !*name || *name == '=')
		return (-1);
	newnode = ft_getenvpair(name, value);
	if (!newnode)
		return (-1);
	new_env = ft_strsjoin(env, (char *[]){newnode, NULL});
	if (!new_env)
		return (free(newnode), -1);
	return (ft_strsfree(env), ft_setenviron(new_env), free(newnode), -1);
}

int	ft_setenv(char *name, char *value, int overwrite)
{
	int		i;
	char	**env;
	char	*newnode;

	env = ft_getenviron();
	if (!env || !name || !*name || *name == '=')
		return (-1);
	i = 0;
	while (env[i])
	{
		if (ft_envequals(name, env[i]))
		{
			if (overwrite == 0)
				return (0);
			newnode = ft_getenvpair(name, value);
			if (!newnode)
				return (-1);
			return (free(env[i]), env[i] = newnode, 0);
		}
		i++;
	}
	return (ft_addenv(name, value));
}
