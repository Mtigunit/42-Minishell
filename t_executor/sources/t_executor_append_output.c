/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_executor_append_output.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 05:16:37 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_executor.h"
#include "t_errorhandler.h"
#include "minilibc.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	t_executor_append_output(char *left, char *right, int llen, int rlen)
{
	int		fd;
	int		status;
	int		stdout_copy;
	char	*new_cmd;

	new_cmd = t_executor_joinargs(left, right, llen, rlen);
	if (!new_cmd)
		return (t_errorhandler_error(1, (char *[]){"malloc error", NULL}));
	fd = t_executor_redirections_getfd(right, rlen);
	if (fd < 0)
		return (free(new_cmd), 1);
	stdout_copy = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	if (!*new_cmd)
		return (free(new_cmd), 0);
	status = t_executor_exec(new_cmd, ft_strlen(new_cmd));
	dup2(stdout_copy, STDOUT_FILENO);
	close(fd);
	free(new_cmd);
	return (status);
}
