/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_executor_execone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 02:40:00 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_parser.h"
#include "t_executor.h"
#include "minilibc.h"
#include "t_signalshandler.h"
#include "t_builtins.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

static inline int	t_executor_filerror(char **argv)
{
	char	*command;

	command = "";
	if (argv && argv[0])
		command = argv[0];
	write(2, ft_progname(), ft_strlen(ft_progname()));
	write(2, ": ", 2);
	write(2, command, ft_strlen(command));
	if (ft_isfilename(command))
		write(2, ": No such file or directory\n", 28);
	else
		write(2, ": command not found\n", 20);
	return (127);
}

static inline int	t_error_is_a_directory(char **argv)
{
	char	*command;

	command = "";
	if (argv && argv[0])
		command = argv[0];
	write(2, ft_progname(), ft_strlen(ft_progname()));
	write(2, ": ", 2);
	write(2, command, ft_strlen(command));
	write(2, ": is a directory\n", 17);
	return (126);
}

static inline int	t_executor_permission_denied(char **argv)
{
	char	*command;
	char	*err_msg;

	command = "";
	if (argv && argv[0])
		command = argv[0];
	err_msg = strerror(errno);
	write(2, ft_progname(), ft_strlen(ft_progname()));
	write(2, ": ", 2);
	perror(command);
	return (126);
}

static inline int	run_child(char **argv, char **env)
{
	char	*filename;

	if (!argv || !argv[0])
		return (1);
	filename = ft_command_path(NULL, argv[0]);
	if (!filename)
		return (t_executor_filerror(argv));
	if (ft_isdir(filename))
		return (free(filename), t_error_is_a_directory(argv));
	execve(filename, argv, env);
	t_executor_permission_denied(argv);
	free(filename);
	return (126);
}

int	t_executor_execone(char *cmd, int cmd_len)
{
	pid_t	pid;
	int		status;
	char	**argv;
	char	**env;

	argv = t_parser_argvsplit(cmd, cmd_len);
	if (!argv || !argv[0])
		return (1);
	env = ft_getenviron();
	if (t_builtins_execute(&status, argv, env))
		return (ft_strsfree(argv), ft_setstatus2(WEXITSTATUS(status)));
	t_signalshandler_fini();
	pid = fork();
	if (pid < 0)
		return (ft_strsfree(argv), write(2, "fork error\n", 11), 1);
	else if (pid == 0)
	{
		status = run_child(argv, env);
		return (ft_strsfree(argv), ft_exit(status), status);
	}
	t_signalshandler_init();
	waitpid(pid, &status, 0);
	return (ft_strsfree(argv), ft_setstatus2(WEXITSTATUS(status)));
}
