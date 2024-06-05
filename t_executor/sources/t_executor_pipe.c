/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_executor_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:45:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_executor.h"
#include "minilibc.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int	t_executor_pipe(char *left, char *right, int left_len, int right_len)
{
	int		pfd[2];
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pfd) < 0)
		return (perror("pipe"), ft_exit(1), 1);
	pid1 = fork();
	if (pid1 < 0)
		return (perror("fork"), ft_exit(1), 1);
	else if (pid1 == 0)
		return (close(pfd[0]), dup2(pfd[1], STDOUT_FILENO),
			ft_exit(t_executor_exec(left, left_len)), 1);
	pid2 = fork();
	if (pid2 < 0)
		return (perror("fork"), ft_exit(1), 1);
	else if (pid2 == 0)
		return (close(pfd[1]), dup2(pfd[0], STDIN_FILENO),
			ft_exit(t_executor_exec(right, right_len)), 1);
	return (close(pfd[0]), close(pfd[1]), waitpid(pid1, NULL, 0),
		waitpid(pid2, &status, 0), ft_setstatus2(WEXITSTATUS(status)));
}
