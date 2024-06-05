/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_precedence_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:50:08 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_precedence.h"
#include <unistd.h>

char	ft_peek(t_precedence *p, int at)
{
	if ((p->pos < 0) || (p->pos + at < 0) || (p->pos + at >= p->len))
		return (0);
	return (p->str[p->pos + at]);
}

void	ft_move(t_precedence *p, int by)
{
	if (by > 0)
		p->pos += by;
}

void	t_precedence_skip_spaces(t_precedence *p)
{
	while (ft_peek(p, 0) == ' ')
		p->pos++;
}

void	h_precedence_copy(t_precedence *dest, t_precedence *src)
{
	dest->pos = src->pos;
	dest->str = src->str;
	dest->len = src->len;
	dest->left_len = src->left_len;
	dest->left = src->left;
	dest->right_len = src->right_len;
	dest->right = src->right;
	dest->operation = src->operation;
}

int	ft_operator_len(int oper)
{
	if (oper & T_OPERATOR_HERE_DOCUMENT)
		return (2);
	if (oper & T_OPERATOR_APPEND_REDIRECTION)
		return (2);
	if (oper & T_OPERATOR_REDIRECT_INPUT)
		return (1);
	if (oper & T_OPERATOR_PIPE)
		return (1);
	if (oper & T_OPERATOR_REDIRECT_OUTPUT)
		return (1);
	if (oper & T_OPERATOR_OR)
		return (2);
	if (oper & T_OPERATOR_AND)
		return (2);
	write(2, "Unknown operation\n", 18);
	return (0);
}
