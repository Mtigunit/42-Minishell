/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_resizebuffer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:44:46 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"
#include <stdlib.h>

int	t_terminal_resizebuffer(int size)
{
	int			i;
	t_terminal	*t;
	char		*buffer;

	t = t_terminal_request();
	if (!t)
		return (-1);
	if (t->size < 1)
		t->size = 1;
	while (t->size < size)
		t->size *= 2;
	buffer = malloc(t->size * sizeof(char));
	if (!buffer)
		return (free(t->buffer), t->buffer = NULL, -1);
	i = -1;
	while (++i < t->length)
		buffer[i] = t->buffer[i];
	return (free(t->buffer), t->buffer = buffer, 0);
}
