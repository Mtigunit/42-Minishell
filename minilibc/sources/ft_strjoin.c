/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:42:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include <stdlib.h>

static size_t	ft_strs_sum_len(char **strs)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	if (!strs)
		return (0);
	while (strs[i])
		len += ft_strlen(strs[i++]);
	return (len);
}

char	*ft_strjoin(char **strs, char *delim)
{
	int		i;
	size_t	len;
	char	*s;

	if (!strs || !*strs || !delim)
		return (NULL);
	i = 0;
	while (strs[i])
		i++;
	len = ft_strs_sum_len(strs) + ((i - 1) * ft_strlen(delim));
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	i = 0;
	s[0] = 0;
	while (strs[i])
	{
		ft_strcat(s, strs[i]);
		if (strs[i + 1])
			ft_strcat(s, delim);
		i++;
	}
	return (s);
}
