/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_readline_fini.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:00:38 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"
#include "minishell.h"

int	t_terminal_readline_fini(void)
{
	t_terminal	*t;

	t = t_terminal_request();
	if (!t)
		return (FAIL);
	tcsetattr(t->fdin, TCSANOW, &t->old_termios);
	return (SUCCESS);
}
