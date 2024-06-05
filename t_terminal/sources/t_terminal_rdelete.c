/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_rdelete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:39:36 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"

int	t_terminal_rdelete(int nbytes)
{
	t_terminal	*t;

	t = t_terminal_request();
	if (nbytes <= 0 || !t || !t->buffer)
		return (-1);
	if (nbytes > t->length - t->column)
		nbytes = t->length - t->column;
	t_terminal_movecolumn(nbytes);
	t_terminal_inject(-nbytes);
	t_terminal_movecolumn(-nbytes);
	return (0);
}
