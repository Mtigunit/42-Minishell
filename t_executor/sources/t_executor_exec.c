/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_executor_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 04:10:52 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_precedence.h"
#include "t_executor.h"
#include "minilibc.h"
#include <unistd.h>

static inline int	t_executor_exec_help(t_precedence *p)
{
	int		llen;
	int		rlen;

	llen = p->left_len;
	rlen = p->right_len;
	if (p->operation == T_OPERATOR_PIPE)
		return (t_executor_pipe(p->left, p->right, llen, rlen));
	else if (p->operation == T_OPERATOR_OR)
		return (t_executor_logical_or(p->left, p->right, llen, rlen));
	else if (p->operation == T_OPERATOR_AND)
		return (t_executor_logical_and(p->left, p->right, llen, rlen));
	else if (p->operation == T_OPERATOR_REDIRECT_OUTPUT)
		return (t_executor_redirect_output(p->left, p->right, llen, rlen));
	else if (p->operation == T_OPERATOR_REDIRECT_INPUT)
		return (t_executor_redirect_input(p->left, p->right, llen, rlen));
	else if (p->operation == T_OPERATOR_APPEND_REDIRECTION)
		return (t_executor_append_output(p->left, p->right, llen, rlen));
	else if (p->operation == T_OPERATOR_HERE_DOCUMENT)
		return (t_executor_here_document(p->left, p->right, llen, rlen));
	while ((p->left_len > 0) && p->left && ft_isspace(p->left[p->left_len - 1]))
		p->left_len--;
	return (t_executor_execone(p->left, p->left_len));
}

int	t_precedence_init(t_precedence *p, char *str, int len)
{
	int	pos;

	pos = t_executor_skip_blanks(0, str, len);
	p->pos = 0;
	p->str = str + pos;
	p->len = len - pos;
	p->left = 0;
	p->left_len = 0;
	p->left = 0;
	p->right = 0;
	p->right_len = 0;
	p->operation = 0;
	return (0);
}

int	t_executor_exec(char *command, int command_len)
{
	t_precedence	p;

	if (t_precedence_init(&p, command, command_len))
		return (0);
	if (t_precedence_parse(&p))
		return (1);
	while ((p.right_len > 0) && p.right && (p.right[p.right_len -1] == ' '))
		p.right_len--;
	while ((p.left_len > 0) && p.left && (p.left[p.left_len -1] == ' '))
		p.left_len--;
	if (p.pos < p.len)
	{
		write(2, ft_progname(), ft_strlen(ft_progname()));
		write(2, ": syntax error near unexpected token `", 38);
		write(2, p.str + p.pos, 1);
		write(2, "\n", 1);
		return (258);
	}
	return (t_executor_exec_help(&p));
}
