/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_fini.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:47:43 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"
#include <stdlib.h>

int	t_terminal_fini(void)
{
	t_terminal	*t;

	t = t_terminal_request();
	if (!t)
		return (-1);
	tcsetattr(t->fdin, TCSANOW, &t->old_termios);
	free(t->buffer);
	t->buffer = NULL;
	return (0);
}
