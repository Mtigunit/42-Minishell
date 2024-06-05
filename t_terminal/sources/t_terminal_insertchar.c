/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_insertchar.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 07:59:10 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"

int	t_terminal_insertchar(char c)
{
	t_terminal	*t;

	t = t_terminal_request();
	if (!t || !t->buffer || (t_terminal_inject(1) < 0))
		return (-1);
	t->buffer[t->column] = c;
	t_terminal_movecolumn(1);
	t->buffer[t->length] = 0;
	return (0);
}
