/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getoperator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:41:47 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minilibc.h"
#include "t_precedence.h"

int	is_an_isolated_operator(int pos, const char *str, int len, char *oper)
{
	int	i;

	i = 0;
	while (oper[i] && (pos + i < len) && (oper[i] == str[pos + i]))
		i++;
	if (oper[i])
		return (0);
	else if ((pos + i < len) && ft_strchr("<>", str[pos + i]))
		return (0);
	else if ((pos > 0) && ft_strchr("<>", str[pos - 1]))
		return (0);
	return (1);
}

int	ft_getoperator(int pos, const char *str, int len)
{
	if ((pos + 1 < len) && (str[pos] == '>') && (str[pos + 1] == '>'))
		return (T_OPERATOR_APPEND_REDIRECTION);
	if (str[pos] == '>')
		return (T_OPERATOR_REDIRECT_OUTPUT);
	if ((pos + 1 < len) && (str[pos] == '<') && (str[pos + 1] == '<'))
		return (T_OPERATOR_HERE_DOCUMENT);
	if (is_an_isolated_operator(pos, str, len, "<"))
		return (T_OPERATOR_REDIRECT_INPUT);
	return (0);
}
