/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_readline_init.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:00:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"
#include <termios.h>
#include <unistd.h>

t_terminal	*t_terminal_readline_init(char *prompt)
{
	t_terminal	*t;

	if (t_terminal_input_request(0, T_TERMINAL_IS_FAKE_INPUT))
		t_terminal_input_request(0, T_TERMINAL_UNSET_FAKE_INPUT);
	if (!isatty(0))
		return (NULL);
	t = t_terminal_init(prompt, 0, 1, 2);
	if (!t)
		return (NULL);
	t_terminal_clearbuffer();
	tcgetattr(t->fdin, &t->old_termios);
	t->new_termios = t->old_termios;
	t->new_termios.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(t->fdin, TCSANOW, &t->new_termios);
	t_terminal_putprompt();
	return (t);
}
