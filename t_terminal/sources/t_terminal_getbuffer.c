/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_getbuffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:30:39 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"

char	*t_terminal_getbuffer(void)
{
	t_terminal	*t;

	t = t_terminal_request();
	if (!t)
		return ((char *)0);
	else if (!t->buffer)
		return ((char *)0);
	t->buffer[t->length] = 0;
	return (t->buffer);
}
