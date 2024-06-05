/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_readline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:43:58 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "t_terminal.h"
#include "t_terminal_history.h"
#include "minilibc.h"
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	t_terminal_event(t_terminal *t, int keycode)
{
	if (keycode == KEYCODE_TAB)
		return ;
	else if (keycode == EOF)
		t_terminal_rdelete(1);
	else if (keycode == KEYCODE_ARROW_UP)
		t_terminal_history_up();
	else if (keycode == KEYCODE_ARROW_DOWN)
		t_terminal_history_down();
	else if (t_terminal_history_get())
	{
		t_terminal_setbuffer(t_terminal_history_get());
		t_terminal_history_request(T_TERMINAL_HISTORY_REST_INDEX);
	}
	if (t_terminal_history_get())
	{
		t_terminal_resetline();
		t_terminal_putprompt();
		ft_putstr_fd(t_terminal_history_get(), t->fdout);
	}
	if (keycode == KEYCODE_ARROW_RIGHT)
		t_terminal_movecolumn(1);
	else if (keycode == KEYCODE_ARROW_LEFT)
		t_terminal_movecolumn(-1);
	else if (keycode == KEYCODE_DELETE)
		t_terminal_ldelete(1);
}

int	t_terminal_event_handler(t_terminal *t, int keycode)
{
	if (keycode == KEYCODE_TAB)
		t_terminal_event(t, keycode);
	else if (keycode == EOF)
		t_terminal_event(t, keycode);
	else if (keycode == KEYCODE_ARROW_UP)
		t_terminal_event(t, keycode);
	else if (keycode == KEYCODE_ARROW_DOWN)
		t_terminal_event(t, keycode);
	else if (keycode == KEYCODE_ARROW_RIGHT)
		t_terminal_event(t, keycode);
	else if (keycode == KEYCODE_ARROW_LEFT)
		t_terminal_event(t, keycode);
	else if (keycode == KEYCODE_DELETE)
		t_terminal_event(t, keycode);
	else if (keycode == KEYCODE_CONTROL_L)
		write(t->fdout, "\033[2J\033[1;1H", 10);
	else
		return (0);
	return (1);
}

int	t_terminal_readline_stop(t_terminal *t, int keycode)
{
	if (keycode == KEYCODE_ENDL)
	{
		write(t->fdout, "\n", 1);
		if (t_terminal_history_get())
			t_terminal_setbuffer(t_terminal_history_get());
		return (1);
	}
	return (0);
}

void	t_terminal_readline_addchar(int keycode)
{
	if (t_terminal_history_get())
		t_terminal_setbuffer(t_terminal_history_get());
	t_terminal_history_request(T_TERMINAL_HISTORY_REST_INDEX);
	t_terminal_insertchar(keycode);
}

char	*t_terminal_readline(char *prompt)
{
	int				keycode;
	t_terminal		*t;

	t_terminal_history_request(T_TERMINAL_HISTORY_REST_INDEX);
	t = t_terminal_readline_init(prompt);
	if (!t)
		return (NULL);
	while (1)
	{
		keycode = t_terminal_readcode(t->fdin);
		if (keycode == 0)
			return (t_terminal_readline_fini(), t_terminal_clearbuffer(),
				t_terminal_getbuffer());
		else if (keycode == SIGSTOP)
			return (t_terminal_readline_fini(), t_terminal_clearbuffer(), NULL);
		else if (t_terminal_event_handler(t, keycode))
			(void) t;
		else if (t_terminal_readline_stop(t, keycode))
			break ;
		else
			t_terminal_readline_addchar(keycode);
		if (!t_terminal_history_get())
			t_terminal_drawbuffer();
	}
	return (t_terminal_readline_fini(), t_terminal_getbuffer());
}
