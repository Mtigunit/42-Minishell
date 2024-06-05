/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_precedence_redirections.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:31:41 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_precedence.h"

int	t_precedence_redirections(t_precedence *p)
{
	return (t_precedence_operation(p,
			T_OPERATOR_HERE_DOCUMENT
			| T_OPERATOR_APPEND_REDIRECTION
			| T_OPERATOR_REDIRECT_OUTPUT
			| T_OPERATOR_REDIRECT_INPUT,
			t_precedence_parse_parenthesis));
}
