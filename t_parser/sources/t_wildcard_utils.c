/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_wildcard_utils.c                                 :+:      :+:    :+:   */
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

int	t_wildcard_readdir(t_wildcard *p, char *basename, int b_len, int maxlen);

int	t_parser_wildcard_clear(char **argv)
{
	int	i;

	if (argv)
	{
		i = 0;
		while (argv[i])
		{
			free(argv[i]);
			argv[i] = (char *)0;
			i++;
		}
	}
	return (-1);
}

int	t_wildcard_valid_entry(t_wildcard *p, t_wildcard *q, char *base, int b_len)
{
	if (!ft_isdir(q->dirname) || (base[b_len] != '/'))
		q->dirname[ft_strlen(q->dirname) - 1] = 0;
	if (q->argv)
	{
		q->argv[q->argc] = q->dirname;
		q->argc++;
		q->argv[q->argc] = NULL;
		p->argc = q->argc;
		return (1);
	}
	q->argc++;
	return (0);
}

int	t_wildcard_appenddir(t_wildcard *p, char *base, int b_len, int maxlen)
{
	t_wildcard		q;
	int				prefix;
	int				sb_len;

	q.argv = p->argv;
	q.argc = p->argc;
	q.dirname = ft_strjoin((char *[]){p->dirname, p->e->d_name, "/", NULL}, "");
	if (!q.dirname)
		return (-1);
	prefix = b_len;
	while ((prefix < maxlen) && (base[prefix] == '/'))
		prefix++;
	sb_len = prefix;
	while (sb_len < maxlen && (base[sb_len] != '/') && (base[sb_len] != '\0'))
		sb_len++;
	if (!ft_isdir(q.dirname) && (base[b_len] == '/'))
		return (free(q.dirname), 0);
	if (sb_len > prefix)
		t_wildcard_readdir(&q, base + prefix, sb_len - prefix, maxlen - prefix);
	else if (t_wildcard_valid_entry(p, &q, base, b_len))
		return (0);
	return (p->argc = q.argc, free(q.dirname), 0);
}

int	t_wildcard_hlp1(t_wildcard *p, int pos, const char *src, int len)
{
	int	j;

	j = p->last_slash;
	while ((pos < len) && src[pos] && (src[pos] != '/'))
		pos++;
	if (j < 0)
		p->dirname = ft_strndup("", 1);
	else
		p->dirname = ft_strndup(src, j + 1);
	if (!p->dirname && p->argv)
		return (t_parser_wildcard_clear(p->argv), -1);
	t_wildcard_readdir(p, (char *)src + j + 1, pos - j - 1, len - j - 1);
	free(p->dirname);
	return (p->argc);
}

int	t_wildcard_hlp(char **argv, const char *src, int len)
{
	t_wildcard	p;
	int			i;

	p.argc = 0;
	p.argv = argv;
	i = 0;
	p.last_slash = -1;
	while ((i < len) && src[i])
	{
		if (src[i] == '/')
			p.last_slash = i;
		if (src[i] == '*')
			return (t_wildcard_hlp1(&p, i, src, len));
		i++;
	}
	return (p.argc);
}
