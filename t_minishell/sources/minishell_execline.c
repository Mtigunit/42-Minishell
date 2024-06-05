/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:35:40 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_terminal.h"
#include "t_terminal_history.h"
#include "t_executor.h"
#include "minilibc.h"
#include "minishell.h"
#include "t_parser.h"

void	minishell_execline(char *line)
{
	char	*line2;
	int		line_len;
	char	*linetrim;

	if (!line)
		return (minishell_exit());
	line_len = ft_strlen(line);
	linetrim = t_parser_trim(line, &line_len);
	if (!linetrim || line_len < 1 || !*linetrim)
		return ;
	line2 = minishell_files_init(linetrim, line_len);
	if (minishell_mode(MINISHELL_MODE_GET) == MINISHELL_MODE_IGNORE_LINE)
		return (minishell_mode(MINISHELL_MODE_RESET), free(line2));
	if (*line)
		t_terminal_history_add(line);
	if (line2)
	{
		t_executor_exec(line2, ft_strlen(line2));
		t_terminal_clearbuffer();
		minishell_files_fini(line2, ft_strlen(line2));
		return (free(line2));
	}
	t_executor_exec(linetrim, line_len);
}
