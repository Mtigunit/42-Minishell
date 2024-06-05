/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_heredoc_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:51:53 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_heredoc.h"
#include "t_errorhandler.h"
#include "minishell.h"
#include "t_parser.h"
#include "minilibc.h"
#include <unistd.h>
#include <stdlib.h>

int	t_heredoc_mode(int req)
{
	static int	isenabled;

	if (req == T_HEREDOC_IS_ENABLED)
		return (isenabled != 0);
	else if (req == T_HEREDOC_IS_DISABLED)
		return (isenabled == 0);
	else if (req == T_HEREDOC_ENABLE)
		isenabled = 1;
	else if (req == T_HEREDOC_DISABLE)
		isenabled = 0;
	return (isenabled);
}

void	t_heredoc_putbuffer(int fd, char *expanded, char *line)
{
	write(fd, expanded, ft_strlen(expanded));
	write(fd, "\n", 1);
	free(expanded);
	free(line);
}

int	t_heredoc_redirect(int fd, const char *delimiter)
{
	char	*line;
	char	*expanded;
	int		expanded_len;

	if (!isatty(0))
		return (t_errorhandler_error(1,
				(char *[]){"I can't read heredoc (stdin is not a tty)", NULL}
		));
	if (minishell_mode(MINISHELL_MODE_GET) == MINISHELL_MODE_IGNORE_LINE)
		return (-1);
	t_heredoc_mode(T_HEREDOC_ENABLE);
	while (1)
	{
		line = ft_readline("> ");
		if (!t_heredoc_mode(T_HEREDOC_IS_ENABLED))
			return (t_heredoc_mode(T_HEREDOC_DISABLE), free(line), -1);
		if (!line || !ft_strcmp(line, delimiter))
			return (t_heredoc_mode(T_HEREDOC_DISABLE), free(line), 0);
		expanded_len = t_parser_argexp(NULL, line, ft_strlen(line));
		expanded = malloc(sizeof(char) * (expanded_len + 1));
		t_parser_argexp(expanded, line, ft_strlen(line));
		t_heredoc_putbuffer(fd, expanded, line);
	}
	return (t_heredoc_mode(T_HEREDOC_DISABLE), 0);
}
