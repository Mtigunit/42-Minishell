/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_precedence_parse_parenthesis.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:31:48 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_precedence.h"
#include "t_parser.h"
#include <unistd.h>

static int	t_parenthesis_help(t_precedence *p, t_precedence *q, int old_pos)
{
	int				dx;

	h_precedence_copy(q, p);
	ft_move(q, 1);
	t_precedence_parse(q);
	if (ft_peek(q, 0) != ')')
	{
		write(2, "syntax error near unexpected token `", 36);
		write(2, p->str + p->pos, 1);
		write(2, "'\n", 2);
		return (1);
	}
	ft_move(q, 1);
	p->left = p->str + p->pos;
	dx = q->pos - p->pos;
	p->left_len = dx;
	t_precedence_skip_spaces(q);
	if ((old_pos == 0) && (q->pos == p->len))
	{
		p->pos = 0;
		p->str = p->left + 1;
		p->len = dx - 2;
		return (t_precedence_parse(p), 0);
	}
	return (p->pos = q->pos, 0);
}

int	t_precedence_parse_parenthesis(t_precedence *p)
{
	int				command_len;
	int				old_pos;
	t_precedence	q;

	old_pos = p->pos;
	t_precedence_skip_spaces(p);
	if (ft_peek(p, 0) == '(')
		return (t_parenthesis_help(p, &q, old_pos));
	p->left = p->pos + p->str;
	old_pos = p->pos;
	command_len = t_parser_cmdcpy((char *)0, p->left, p->len - p->pos);
	if (command_len < 0)
		return (1);
	ft_move(p, command_len);
	t_precedence_skip_spaces(p);
	p->left_len = p->pos - old_pos;
	return (0);
}
