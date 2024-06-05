/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parser_argexp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:42:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/t_parser.h"
#include "minilibc.h"
#include <stdlib.h>

static inline int	key_len(const char *str, int len)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if ((i >= len) || !ft_isvstart(str[i]))
		return (0);
	while ((i < len) && str[i] && ft_isvchar(str[i]))
		i++;
	return (i);
}

static inline int	append_value(char *dest, const char *src, int at, int len)
{
	int		p;
	char	*key;
	char	*value;

	if (!src)
		return (0);
	key = ft_strndup(src, key_len(src, len));
	if (!key)
		return (0);
	value = ft_getenv(key);
	free(key);
	if (!value || !*value)
		return (0);
	p = 0;
	while (value[p])
	{
		if (dest)
			dest[at + p] = value[p];
		p++;
	}
	return (p);
}

static inline int	append_pid(char *dest, int at)
{
	char	pidstr[16];

	ft_numeric2string(pidstr, ft_getpid());
	if (dest)
		ft_strcpy(dest + at, pidstr);
	return (ft_strlen(pidstr));
}

static int	special_parameter(char *dest, int *at, const char *src, int len)
{
	int		i;
	char	str_status[16];

	i = 0;
	while ((i + 1 < len) && (src[i] == src[i + 1]) && (src[i] == '$'))
	{
		*at += append_pid(dest, *at);
		i += 2;
	}
	while ((i + 1 < len) && (src[i] == '$') && (src[i + 1] == '?'))
	{
		ft_numeric2string(str_status, ft_getstatus());
		if (dest)
			ft_strcpy(dest + *at, str_status);
		*at += ft_strlen(str_status);
		i += 2;
	}
	return (i);
}

int	t_parser_argexp(char *dest, const char *src, int len)
{
	int	i;
	int	length;

	if (!src)
		return (0);
	i = 0;
	length = 0;
	while ((i < len) && src[i])
	{
		i += special_parameter(dest, &length, src + i, len - i);
		if (t_expand_isenabled())
		{
			if ((i + 1 < len) && (src[i] == '$') && ft_isvstart(src[i + 1]))
			{
				length += append_value(dest, src + i + 1, length, len - i - 1);
				i += key_len(src + i + 1, len - i - 1) + 1;
				continue ;
			}			
		}
		t_parser_append_char(length, dest, src[i]);
		length++;
		i++;
	}
	t_parser_append_char(length, dest, 0);
	return (length);
}
