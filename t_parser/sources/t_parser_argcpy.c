/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parser_argcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:42:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/t_parser.h"
#include "minilibc.h"
#include <unistd.h>

int	t_parser_weak_string(int *pos, char *dest, const char *src, int len)
{
	int		k;
	int		l2;
	int		lll;

	if (!pos || !src || (len <= 0) || (src[0] != '"'))
		return (-1);
	k = 1;
	while ((k < len) && (src[k]) && (src[k] != '"'))
		k++;
	if ((k == len) || (src[k] != '"'))
		return (write(2, "SYNTAX ERROR quote mamsdoudach!\n", 32), -1);
	l2 = k - 1;
	if (dest)
		l2 = t_parser_argexp(dest + pos[0], src + 1, k - 1);
	else
		l2 = t_parser_argexp(NULL, src + 1, k - 1);
	lll = -1;
	while (dest && (++lll < l2))
	{
		if (dest[pos[0] + lll] == '*')
			t_parser_append_char(pos[0] + lll, dest, CHAR_FAKE_STAR);
		if (dest[pos[0] + lll] == '$')
			t_parser_append_char(pos[0] + lll, dest, CHAR_FAKE_DOLLAR_SIGN);
	}
	return (pos[0] += l2, k + 1);
}

int	t_parser_strong_string(int *pos, char *dest, const char *src, int len)
{
	int	i;

	if (!pos || !src || (len <= 0) || (src[0] != '\''))
		return (-1);
	i = 1;
	while ((i < len) && (src[i]) && (src[i] != '\''))
	{
		if (dest && src[i] == '*')
			dest[pos[0]] = CHAR_FAKE_STAR;
		else if (dest && (src[i] == '$'))
			dest[pos[0]] = CHAR_FAKE_DOLLAR_SIGN;
		else if (dest)
			dest[pos[0]] = src[i];
		pos[0]++;
		i++;
	}
	if ((i == len) || (src[i] != '\''))
		return (write(2, "SYNTA- error quote mamsdoudach!\n", 32), -1);
	return (i + 1);
}

int	t_parser_arg(int *pos, char *dest, const char *src, int len)
{
	int	i;
	int	di;

	i = 0;
	if ((i + 1 < len) && (src[i] == '$') && ft_isquote(src[i + 1]))
		i++;
	if ((i < len) && (src[i] == '\''))
	{
		di = t_parser_strong_string(pos, dest, src + i, len - i);
		if (di < 0)
			return (di);
		i += di;
	}
	else if ((i < len) && (src[i] == '"'))
	{
		di = t_parser_weak_string(pos, dest, src + i, len - i);
		if (di < 0)
			return (di);
		i += di;
	}
	else
		t_parser_append_char(pos[0]++, dest, src[i++]);
	return (i);
}

int	t_parser_argcpy(int *arglen, char *dest, const char *src, int len)
{
	int	i;
	int	j;
	int	di;

	i = 0;
	j = 0;
	while (src && (i < len) && (src[i]) && !t_parser_argend(src[i]))
	{
		while ((i + 1 < len) && (src[i] == src[i + 1]) && (src[i] == '$'))
		{
			t_parser_append_char(j++, dest, src[i++]);
			t_parser_append_char(j++, dest, src[i++]);
		}
		di = t_parser_arg(&j, dest, src + i, len - i);
		if (di < 0)
			return (di);
		i += di;
	}
	if (dest)
		dest[j] = 0;
	if (arglen)
		arglen[0] = j;
	return (i);
}
