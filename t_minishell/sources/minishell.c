/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 05:07:47 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minilibc.h"
#include "t_errorhandler.h"
#include "t_signalshandler.h"
#include "t_executor.h"
#include "t_terminal.h"
#include "t_terminal_history.h"
#include "t_parser.h"
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

int	minishell(int argc, char **argv, char **env)
{
	char	*line;

	if (minishell_configure(argc, argv, env) != SUCCESS)
		return (FAIL);
	t_signalshandler_init();
	while (1)
	{
		line = ft_readline(ft_prompt());
		if (minishell_mode(MINISHELL_MODE_GET) == MINISHELL_MODE_IGNORE_LINE)
			minishell_mode(MINISHELL_MODE_RESET);
		else
			minishell_execline(line);
		free(line);
	}
	return (minishell_exit(), ft_getstatus());
}
