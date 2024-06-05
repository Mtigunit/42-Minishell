/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parser_cmdcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:42:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/t_parser.h"
#include "minilibc.h"

int	t_isoperator(char c)
{
	if ((c == '>') || (c == '<') || (c == '|'))
		return (1);
	else if ((c == '(') || (c == ')') || (c == '&'))
		return (1);
	return (0);
}

int	t_parser_string(int i, char *dest, const char *src, int len)
{
	int	tmp;
	int	di;

	if (!src || (len <= i))
		return (-1);
	if (src[i] == '\'')
		di = t_parser_strong_string(&tmp, (char *)0, src + i, len - i);
	else if (src[i] == '"')
		di = t_parser_weak_string(&tmp, (char *)0, src + i, len - i);
	else
		di = -1;
	if (di < 0)
		return (di);
	tmp = i + di;
	while (i < tmp)
	{
		if (dest)
			dest[i] = src[i];
		i++;
	}
	return (i);
}

int	t_parser_cmdcpy(char *dest, const char *src, int len)
{
	int	i;

	if (!src)
		return (-1);
	i = 0;
	while ((i < len) && src[i] && !t_isoperator(src[i]))
	{
		if ((src[i] == '\'') || (src[i] == '"'))
		{
			i = t_parser_string(i, dest, src, len);
			if (i < 0)
				return (-1);
			continue ;
		}
		if (dest)
			dest[i] = src[i];
		i++;
	}
	while ((i > 0) && ft_isspace(src[i - 1]))
		i--;
	if (dest)
		dest[i] = 0;
	return (i);
}
