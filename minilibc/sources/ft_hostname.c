/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hostname.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:02:26 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

static inline char	*read_hostname(int *pipe_fd, char *hostname, pid_t pid)
{
	int			status;
	int			hostlen;

	waitpid(pid, &status, 0);
	if (WEXITSTATUS(status) == 0)
	{
		hostlen = read(pipe_fd[0], hostname, MAX_HOSTNAME_LEN);
		if (hostlen > 0 && (hostlen < MAX_HOSTNAME_LEN))
			hostname[hostlen - 1] = 0;
	}
	else
		ft_strcpy(hostname, DEFAULT_HOSTNAME);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (hostname);
}

static inline char	*ft_get_hostname_(char *hostname)
{
	pid_t		pid;
	int			pipe_fd[2];

	if (pipe(pipe_fd) == 0)
	{
		pid = fork();
		if (pid < 0)
			return (ft_strcpy(hostname, DEFAULT_HOSTNAME));
		else if (pid == 0)
		{
			dup2(pipe_fd[1], 1);
			execve("/bin/hostname", (char *[]){"hostname", NULL}, NULL);
			ft_exit(1);
		}
		return (read_hostname(pipe_fd, hostname, pid));
	}
	return (ft_strcpy(hostname, DEFAULT_HOSTNAME));
}

char	*ft_hostname(void)
{
	static char	hostname[MAX_HOSTNAME_LEN];

	if (hostname[0] == 0)
		ft_get_hostname_(hostname);
	return (hostname);
}
