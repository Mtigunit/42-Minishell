/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_putbuffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:45:25 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"
#include <unistd.h>

void	t_terminal_putbuffer(void)
{
	int			i;
	t_terminal	*t;

	t = t_terminal_request();
	i = 0;
	while (i < t->column)
		write(t->fdout, t->buffer + i++, 1);
	while (i < t->length)
		write(t->fdout, t->buffer + i++, 1);
	while (i-- > t->column)
		write(t->fdout, (char []){27, 91, 68}, 3);
}
