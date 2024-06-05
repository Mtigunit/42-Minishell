/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init_output_files.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 23:01:41 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minilibc.h"
#include "t_parser.h"
#include "t_errorhandler.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_norm0
{
	int		oldpos;
	int		len;
	char	*str;
}	t_norm0;

static int	minishell_init_output_files_mode(int *pos, char *str, int len)
{
	int	mode;

	mode = O_WRONLY | O_CREAT | O_TRUNC;
	if ((str[pos[0]] == '>') && (str[pos[0] + 1] == '>'))
	{
		mode = O_WRONLY | O_CREAT | O_APPEND;
		pos[0] += 2;
	}
	else if (str[pos[0]] == '>')
		pos[0] += 1;
	pos[0] = t_parser_skip_spaces(pos[0], str, len);
	return (mode);
}

static void	_help2(int *error, char *filename, int *fd)
{
	if (error[0])
	{
		if (fd[0] >= 0)
			close(fd[0]);
		fd[0] = -1;
	}
	else if (fd[0] < 0)
	{
		error[0] = 1;
		t_errorhandler_perror(filename);
	}
}

static int	_helpfd(int *dx, int *error, int *pos, t_norm0 *n)
{
	int		fd;
	int		mode;
	char	*filename;
	int		filelen;

	mode = minishell_init_output_files_mode(pos, n->str, n->len);
	dx[0] = t_parser_argcpy(&filelen, NULL, n->str + pos[0], n->len - pos[0]);
	if ((dx[0] < 0) || (filelen < 1))
		return (-2);
	filename = malloc(sizeof(char) * (filelen + 1));
	if (!filename)
		return (write(2, "malloc error\n", 13), ft_exit(1), -1);
	t_parser_argcpy(&filelen, filename, n->str + pos[0], n->len - pos[0]);
	fd = -1;
	if (!error[0])
		fd = open(filename, mode, 0644);
	_help2(error, filename, &fd);
	return (free(filename), fd);
}

char	*minishell_init_output_files(int error, int pos, char *str, int len)
{
	int		fd;
	int		dx;
	char	*new;
	char	*right;
	t_norm0	n;

	n.len = len;
	n.str = str;
	n.oldpos = pos;
	fd = _helpfd(&dx, &error, &pos, &n);
	if (fd == -2)
		return (NULL);
	if (t_redirection_last(pos + dx, str, len, '>'))
		return (new = malloc(sizeof(char) * (5 + len - dx + 1)),
			ft_strncpy(new, str, pos), t_redirection_setfd(new + pos, fd),
			ft_strncpy(new + pos + 5, str + pos + dx, len - pos - dx),
			new[5 + len - dx] = 0, new);
	else
	{
		right = minishell_init_files(error, str + pos + dx, len - pos);
		if (right)
			return (new = ft_strnjoin(str, right, n.oldpos, ft_strlen(right)),
				free(right), new);
	}
	return (NULL);
}
