/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_executor_here_document.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 06:07:17 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_executor.h"
#include "minilibc.h"
#include "t_errorhandler.h"
#include "t_heredoc.h"
#include <unistd.h>
#include <stdlib.h>

int	t_executor_here_document(char *left, char *right, int llen, int rlen)
{
	int		status;
	char	*new_cmd;
	int		heredoc_fd;
	int		old_stdin;

	new_cmd = t_executor_joinargs(left, right, llen, rlen);
	if (!new_cmd)
		return (t_errorhandler_error(1, (char *[]){"malloc error", NULL}));
	heredoc_fd = t_heredoc_getfd(right, rlen);
	llen = ft_strlen(new_cmd);
	old_stdin = dup(STDIN_FILENO);
	dup2(heredoc_fd, STDIN_FILENO);
	status = t_executor_exec(new_cmd, llen);
	dup2(old_stdin, STDIN_FILENO);
	if (heredoc_fd > 0)
		close(heredoc_fd);
	free(new_cmd);
	return (status);
}
