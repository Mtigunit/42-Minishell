/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:42:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_relapath(char *dest, char *filename)
{
	char	*pwd;

	pwd = ft_getenv("PWD");
	if (!pwd)
		return ((char *)0);
	if (dest)
	{
		ft_strcpy(dest, pwd);
		ft_strcat(dest, "/");
		ft_strcat(dest, filename);
	}
	else
	{
		dest = ft_strjoin((char *[]){pwd, filename, NULL}, "/");
		if (access(dest, F_OK) != 0)
			free(dest);
	}
	if (access(dest, F_OK) == 0)
		return (dest);
	return ((char *)0);
}

char	*ft_abspath(char *dest, char *filename)
{
	if (!filename)
		return (filename);
	if (access(filename, F_OK) == 0)
	{
		if (!dest)
			return (ft_strdup(filename));
		return (ft_strcpy(dest, filename));
	}
	return (0);
}

char	*ft_pathof(char *to, const char *filename)
{
	int		i;
	int		j;
	char	*path;

	path = ft_getenv("PATH");
	if (!path || !to)
		return (to);
	i = 0;
	while (path[i])
	{
		while (path[i] == ':')
			i++;
		j = 0;
		while ((path[i + j] != ':') && (path[i + j] != '\0'))
		{
			to[j] = path[i + j];
			j++;
		}
		to[j] = '/';
		ft_strcpy(to + j + 1, filename);
		if (access(to, F_OK) == 0)
			return (to);
		i += j;
	}
	return (NULL);
}

char	*ft_command_path(char *dest, char *command)
{
	char	tmp[PATH_MAX];

	if (!command || !*command)
		return (NULL);
	if (command[0] == '.')
		return (ft_relapath(dest, command));
	if (command[0] == '/')
		return (ft_abspath(dest, command));
	if (!ft_pathof(tmp, command))
		return (NULL);
	if (!dest)
		return (ft_strdup(tmp));
	return (dest);
}
