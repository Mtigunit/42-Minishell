/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 07:24:01 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include <stdlib.h>

char	*ft_getvar(const char *name)
{
	int		i;
	int		j;
	char	*key;
	char	*value;

	if (!name || (name[0] != '$') || !ft_isvstart(name[1]))
		return ((char *)0);
	i = 1;
	while (ft_isvchar(name[1 + i]))
		i++;
	key = malloc(sizeof(char) * (i + 1));
	if (!key)
		return ((char *)0);
	j = 0;
	while (j < i)
	{
		key[j] = name[1 + j];
		j++;
	}
	key[j] = 0;
	value = ft_getenv(key);
	free(key);
	return (value);
}
