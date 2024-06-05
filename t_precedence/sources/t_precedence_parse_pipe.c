/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_precedence_parse_pipe.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:31:36 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_precedence.h"

int	t_precedence_parse_pipe(t_precedence *p)
{
	return (t_precedence_operation(p,
			T_OPERATOR_PIPE, t_precedence_redirections));
}
