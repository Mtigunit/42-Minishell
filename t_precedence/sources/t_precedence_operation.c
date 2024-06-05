/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_precedence_operation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:31:54 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_precedence.h"
#include "minilibc.h"
#include <unistd.h>

static int	check_operator(char before, int operator, char after)
{
	if (
		(operator == T_OPERATOR_REDIRECT_OUTPUT)
		|| (operator == T_OPERATOR_APPEND_REDIRECTION)
		|| (operator == T_OPERATOR_HERE_DOCUMENT)
		|| (operator == T_OPERATOR_REDIRECT_INPUT))
	{
		if ((before == 0) || ft_strchr("|&", before))
		{
			if (!after || ft_strchr("|&<>", after))
				return (-1);
			return (0);
		}
		return (0);
	}
	if ((before == 0) || ft_strchr("|&<>", before))
		return (-1);
	if ((after == 0) || ft_strchr("|&<>", after))
		return (-1);
	return (0);
}

static int	get_operator(int pos, const char *str, int len, int operator)
{
	int		i;
	char	before;
	char	after;

	i = -1;
	while ((pos + i > 0) && ft_isspace(str[pos + i]))
		i--;
	before = 0;
	if (pos + i > 0)
		before = str[pos + i];
	i = ft_operator_len(operator);
	while ((pos + i < len) && ft_isspace(str[pos + i]))
		i++;
	after = 0;
	if (pos + i < len)
		after = str[pos + i];
	if (check_operator(before, operator, after) < 0)
	{
		ft_setstatus2(258);
		write(2, "syntax error\n", 13);
		return (-1);
	}
	return (operator);
}

static int	ft_getoper(t_precedence *p, int at)
{
	int	operator;

	if ((ft_peek(p, at) == '>') && (ft_peek(p, at + 1) == '>'))
		operator = T_OPERATOR_APPEND_REDIRECTION;
	else if ((ft_peek(p, at) == '<') && (ft_peek(p, at + 1) == '<'))
		operator = T_OPERATOR_HERE_DOCUMENT;
	else if ((ft_peek(p, at) == '|') && (ft_peek(p, at + 1) != '|'))
		operator = T_OPERATOR_PIPE;
	else if ((ft_peek(p, at) == '|') && (ft_peek(p, at + 1) == '|'))
		operator = T_OPERATOR_OR;
	else if ((ft_peek(p, at) == '&') && (ft_peek(p, at + 1) == '&'))
		operator = T_OPERATOR_AND;
	else if ((ft_peek(p, at) == '>') && (ft_peek(p, at + 1) != '>'))
		operator = T_OPERATOR_REDIRECT_OUTPUT;
	else if ((ft_peek(p, at) == '<') && (ft_peek(p, at + 1) != '<'))
		operator = T_OPERATOR_REDIRECT_INPUT;
	else
		return (0);
	return (get_operator(p->pos + at, p->str, p->len, operator));
}

int	t_precedence_operation(t_precedence *p,
	int operation, int (*prev)(t_precedence *p))
{
	t_precedence	q;
	int				tmp;

	tmp = p->pos;
	if (prev(p) || ft_getoper(p, 0) < 0)
		return (1);
	if (!(ft_getoper(p, 0) & operation))
		return (0);
	p->left_len = p->pos - tmp;
	h_precedence_copy(&q, p);
	while (ft_getoper(&q, 0) & operation)
	{
		p->left_len += q.pos - p->pos;
		p->pos = q.pos;
		p->operation = ft_getoper(&q, 0);
		ft_move(&q, ft_operator_len(p->operation));
		t_precedence_skip_spaces(&q);
		tmp = q.pos;
		if (prev(&q))
			return (1);
	}
	p->right_len = q.pos - tmp;
	p->right = q.left;
	p->pos = q.pos;
	return (0);
}
