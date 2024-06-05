/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_setlength.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:40:16 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"

int	t_terminal_setlength(int length)
{
	t_terminal	*t;

	t = t_terminal_request();
	if (!t || length < 0 || (!t->buffer && (length > 0)))
		return (-1);
	if (t->buffer)
		t->buffer[length] = 0;
	t->length = length;
	if (t->column > length)
		t->column = length;
	return (0);
}
