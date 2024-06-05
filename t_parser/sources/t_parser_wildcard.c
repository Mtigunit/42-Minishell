/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parser_wildcard.c                                :+:      :+:    :+:   */
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

int	t_wildcard_hlp(char **argv, const char *src, int len);
int	t_wildcard_appenddir(t_wildcard *p, char *base, int b_len, int maxlen);

static inline void	t_wildcard_fini(char **argv)
{
	int	i;
	int	j;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == CHAR_FAKE_STAR)
				argv[i][j] = '*';
			if (argv[i][j] == CHAR_FAKE_DOLLAR_SIGN)
				argv[i][j] = '$';
			j++;
		}
		i++;
	}
}

int	t_wildcard_ignore(const char *name, char *dr, const char *schema, int slen)
{
	if (!name || !dr || !schema)
		return (0);
	if ((slen > 0) && (schema[0] == '*') && (name[0] == '.'))
		return (1);
	if (dr[0] == '/')
	{
		if ((name[0] == '.') && (name[1] == '.') && (name[2] == '\0'))
			return (1);
		else if ((name[0] == '.') && (name[2] == '\0'))
			return (1);
	}
	return (0);
}

int	t_wildcard_readdir(t_wildcard *p, char *basename, int b_len, int maxlen)
{
	DIR				*d;

	d = NULL;
	if (!*p->dirname)
		d = opendir(".");
	else if (ft_isdir(p->dirname))
		d = opendir(p->dirname);
	if (!d)
		return (0);
	while (1)
	{
		p->e = readdir(d);
		if (!p->e)
			break ;
		if (t_wildcard_ignore(p->e->d_name, p->dirname, basename, b_len))
			continue ;
		else if (ft_matched(basename, p->e->d_name, b_len, p->e->d_namlen))
		{
			if (t_wildcard_appenddir(p, basename, b_len, maxlen))
				return (-1);
		}
	}
	closedir(d);
	return (p->argc);
}

int	t_wildcard_prepare(char **dest, const char *src, int len)
{
	int		ecopy_len;

	if (!dest)
		return (-1);
	ecopy_len = t_parser_argexp(NULL, src, len);
	if (ecopy_len < 0)
		return (-1);
	dest[0] = malloc(sizeof(char) * (ecopy_len + 1));
	if (!dest[0])
		return (-1);
	t_parser_argexp(dest[0], src, len);
	return (ecopy_len);
}

int	t_parser_wildcard(char **argv, const char *src, int len)
{
	int		length;
	char	*expanded;
	int		expanded_len;

	expanded = NULL;
	expanded_len = t_wildcard_prepare(&expanded, src, len);
	if ((expanded_len < 0) || !expanded)
		return (-1);
	length = t_wildcard_hlp(argv, expanded, expanded_len);
	if (length == 0)
	{
		if (argv)
		{
			argv[0] = expanded;
			argv[1] = NULL;
			t_wildcard_fini(argv);
			return (1);
		}
		return (free(expanded), 1);
	}
	t_wildcard_fini(argv);
	return (free(expanded), length);
}
