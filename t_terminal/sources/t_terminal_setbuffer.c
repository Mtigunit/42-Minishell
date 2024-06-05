/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_setbuffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:35:20 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"

int	t_terminal_setbuffer(const char *str)
{
	int			i;
	t_terminal	*t;

	if (!str)
		return (-1);
	t = t_terminal_request();
	if (!t || !t->buffer)
		return (-1);
	i = -1;
	while (str[++i])
		t->buffer[i] = str[i];
	t_terminal_setlength(i);
	t_terminal_setcolumn(i);
	return (0);
}
