/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_ldelete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:31:18 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"

int	t_terminal_ldelete(int nbytes)
{
	t_terminal	*t;

	t = t_terminal_request();
	if (nbytes <= 0 || !t || !t->buffer)
		return (0);
	if (t->column - nbytes < 0)
		nbytes = t->column;
	t_terminal_inject(-nbytes);
	t_terminal_movecolumn(-nbytes);
	return (0);
}
