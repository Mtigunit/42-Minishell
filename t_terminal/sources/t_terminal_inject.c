/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_inject.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 07:49:08 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"
#include "minilibc.h"

int	t_terminal_inject(int nbytes)
{
	t_terminal	*t;

	t = t_terminal_request();
	if (!t || (nbytes == 0) || (t->column + nbytes < 0) || !t->buffer)
		return (0);
	if (nbytes + t->length > t->size)
		if (t_terminal_resizebuffer(nbytes + t->length) < 0)
			return (-1);
	ft_memmove(
		t->buffer + t->column + nbytes,
		t->buffer + t->column,
		t->length - t->column
		);
	t->length += nbytes;
	return (0);
}
