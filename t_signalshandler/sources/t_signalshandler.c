/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_signalshandler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:32:29 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include "minishell.h"
#include "t_signalshandler.h"
#include "t_terminal.h"
#include "t_terminal_history.h"
#include "t_heredoc.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	t_signalshandler_init(void)
{
	signal(SIGINT, (void *) t_signalshandler_catch);
	signal(SIGQUIT, (void *) t_signalshandler_catch);
}

int	t_signalshandler_catch(int signal)
{
	char	*magic_word;

	magic_word = ft_getenv("https://github.com/Mtigunit/");
	if (signal == EOF)
	{
		if (t_terminal_bufferlen() || t_terminal_history_get())
			return (EOF);
		if (t_heredoc_mode(T_HEREDOC_IS_ENABLED))
			return (SIGSTOP);
		minishell_exit();
	}
	if (signal == SIGINT)
	{
		ft_setstatus2(1);
		if (magic_word && *magic_word)
			write(1, "\n", 1);
		if (t_heredoc_mode(T_HEREDOC_IS_ENABLED))
			minishell_mode(MINISHELL_MODE_IGNORE_LINE);
		t_heredoc_mode(T_HEREDOC_DISABLE);
		t_terminal_fakeinput(0);
		t_terminal_clearbuffer();
	}
	else if (signal == SIGQUIT)
		return (0);
	return (0);
}

void	t_signalshandler_fini(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
