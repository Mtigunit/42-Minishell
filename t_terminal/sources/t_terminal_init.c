/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:48:00 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"
#include "minilibc.h"
#include <stdlib.h>

static void	t_terminal_init_refcolumn(char *bufferclear, int fdin)
{
	int	ref;

	ref = t_terminal_getcol(fdin);
	bufferclear[0] = '\033';
	bufferclear[1] = '[';
	bufferclear[2] = '0' + 0;
	bufferclear[3] = '0' + (ref / 10);
	bufferclear[4] = '0' + (ref % 10);
	bufferclear[5] = 'G';
	bufferclear[6] = '\033';
	bufferclear[7] = '[';
	bufferclear[8] = '0';
	bufferclear[9] = 'K';
}

t_terminal	*t_terminal_init(char *prompt, int fdin, int fdout, int fderr)
{
	t_terminal	*t;

	t = t_terminal_request();
	if (!t)
		return (NULL);
	if (t->buffer == NULL)
	{
		t->size = T_TERMINAL_BUFFER_SIZE;
		t->buffer = malloc(sizeof(char) * t->size);
	}
	if (!prompt)
		prompt = "prompt: ";
	t->length = 0;
	t->column = 0;
	t->prompt = prompt;
	t->prompt_len = ft_strlen(prompt);
	t->fdin = fdin;
	t->fdout = fdout;
	t->fderr = fderr;
	t_terminal_init_refcolumn(t->bufferclear, fdin);
	return (t);
}
