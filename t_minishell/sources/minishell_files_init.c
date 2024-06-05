/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_files_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:38:40 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "t_parser.h"
#include "minilibc.h"
#include "t_heredoc.h"
#include "t_precedence.h"
#include <stdlib.h>

char	*minishell_init_files(int error, char *str, int len)
{
	int		i;
	int		operator;

	i = 0;
	while ((i < len) && str[i])
	{
		i = t_parser_skip_string(i, str, len);
		operator = ft_getoperator(i, str, len);
		if ((operator == T_OPERATOR_REDIRECT_OUTPUT)
			|| (operator == T_OPERATOR_APPEND_REDIRECTION))
			return (minishell_init_output_files(error, i, str, len));
		if (operator == T_OPERATOR_REDIRECT_INPUT)
			return (minishell_init_input_files(i, str, len));
		i++;
	}
	return (NULL);
}

char	*minishell_files_init(char *str, int len)
{
	char	*heredoc;
	char	*files;

	heredoc = t_heredoc_init(str, len);
	if (minishell_mode(MINISHELL_MODE_GET) == MINISHELL_MODE_IGNORE_LINE)
		return (heredoc);
	if (heredoc)
	{
		files = minishell_init_files(0, heredoc, ft_strlen(heredoc));
		if (files)
			return (free(heredoc), files);
		return (heredoc);
	}
	return (minishell_init_files(0, str, len));
}
