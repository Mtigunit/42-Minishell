/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_executor_redirect_input.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 04:51:49 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_executor.h"
#include "minilibc.h"
#include "t_errorhandler.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	t_executor_redirect_input(char *left, char *right, int llen, int rlen)
{
	int		fd;
	int		status;
	int		old;
	char	*new_cmd;

	new_cmd = t_executor_joinargs(left, right, llen, rlen);
	if (!new_cmd)
		return (t_errorhandler_error(1, (char *[]){"malloc error", NULL}));
	old = dup(STDIN_FILENO);
	fd = t_executor_redirections_getfd(right, rlen);
	if (fd < 0)
		return (free(new_cmd), 1);
	dup2(fd, STDIN_FILENO);
	status = t_executor_exec(new_cmd, ft_strlen(new_cmd));
	dup2(old, STDIN_FILENO);
	close(fd);
	free(new_cmd);
	return (status);
}
