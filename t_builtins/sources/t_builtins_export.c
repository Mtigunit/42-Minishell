/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_builtins_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:22:02 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_builtins.h"
#include "minilibc.h"
#include "t_errorhandler.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_isvalid_identifier(const char *str)
{
	int	len;

	len = ft_varlen(str);
	if (len < 1)
		return (0);
	return ((str[len] == '\0') || (str[len] == '='));
}

static inline int	t_builtins_putexports(char **env)
{
	int	i;
	int	j;

	i = -1;
	while (env && env[++i])
	{
		if (!ft_isvalid_identifier(env[i]))
			continue ;
		write(1, "declare -x ", 11);
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			write(1, env[i] + j++, 1);
		if (env[i][j] == '=')
		{
			j++;
			write(1, "=\"", 2);
			while (env[i][j])
				write(1, env[i] + j++, 1);
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
	}
	return (0);
}

void	t_builtins_export_append(char *str, int j)
{
	if (str[j] == '=')
		ft_setenv(str, str + j + 1, 1);
	else
		ft_setenv(str, NULL, 1);
}

int	t_builtins_export_join(char *str, int j)
{
	char	*key;
	char	*value;
	char	*joined;

	key = ft_strndup(str, j);
	if (!key)
		return (-1);
	value = ft_getenv(key);
	if (!value)
		ft_setenv(key, str + j + 2, 1);
	else
	{
		joined = ft_strjoin((char *[]){value, str + j + 2, NULL}, "");
		if (!joined)
			return (free(key), -1);
		ft_setenv(key, joined, 1);
		free(joined);
	}
	free(key);
	return (0);
}

int	t_builtins_export(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 1)
		return (t_builtins_putexports(ft_getenviron()));
	i = 1;
	while ((i < argc) && argv[i])
	{
		j = ft_varlen(argv[i]);
		if (j < 1)
		{
			if ((j < 0) && (argv[i][-j] == '+') && (argv[i][1 - j] == '='))
			{
				t_builtins_export_join(argv[i++], -j);
				continue ;
			}
			t_errorhandler_error(
				5, (char *[]){"export: ", "`", argv[i], "': ",
				"not a valid identifier", NULL});
		}
		else
			t_builtins_export_append(argv[i], j);
		i++;
	}
	return (0);
}
