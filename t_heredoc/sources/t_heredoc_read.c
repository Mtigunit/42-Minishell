/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_heredoc_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:57:11 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_heredoc.h"
#include "t_errorhandler.h"
#include "t_parser.h"
#include "minilibc.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static inline int	ft_virtualfile(char *virtual_filename)
{
	int			virtual_fd;
	static int	virtual_fileindex;
	char		*base;

	base = (char []){10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
	ft_numeric2stringbase(virtual_filename + 1, virtual_fileindex, base);
	virtual_filename[0] = '.';
	virtual_fd = open(virtual_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	virtual_fileindex++;
	return (virtual_fd);
}

static inline int	t_heredoc_read_helper(int *at, char *str, int len)
{
	int		i;
	int		herdoc_fd;
	char	*delimiter;
	char	filename[VIRTUAL_FILENAME_MAX];

	i = at[0] + 2;
	if ((str[*at] != '<') || (str[*at + 1] != '<'))
		t_errorhandler_developer(__LINE__, __FILE__);
	at[0] = t_parser_skip_spaces(at[0] + 2, str, len);
	at[0] = t_heredoc_get_delimiter(&delimiter, at[0], str, len);
	herdoc_fd = ft_virtualfile(filename);
	if (!t_heredoc_should_expand(str + i, at[0] - i))
		t_expand_disable();
	if (t_heredoc_redirect(herdoc_fd, delimiter) < 0)
		return (-1);
	t_expand_enable();
	free(delimiter);
	close(herdoc_fd);
	herdoc_fd = open(filename, O_RDONLY);
	unlink(filename);
	return (herdoc_fd);
}

void	t_heredoc_inject_fd(char *left, char *str, int i, int herdoc_fd)
{
	ft_strncpy(left, str, i);
	left[i + 0] = ' ';
	t_heredoc_setfd(left + i + 1, herdoc_fd);
	ft_strcpy(left + i + 6, " ");
}

char	*t_heredoc_read(int *at, char *str, int len)
{
	int		i;
	int		herdoc_fd;	
	char	*full;
	char	*left;
	char	*right;

	i = at[0] + 2;
	herdoc_fd = t_heredoc_read_helper(at, str, len);
	if (herdoc_fd < 0)
		return (NULL);
	left = malloc((i + 1 + 5 + 1 + 1) * sizeof(char));
	if (!left)
		return (NULL);
	t_heredoc_inject_fd(left, str, i, herdoc_fd);
	if (t_heredoc_deprecated(left + i + 1, i, str, len))
		close(herdoc_fd);
	if (t_heredoc_last(at[0], str, len))
		right = ft_strndup(str + at[0], len - at[0]);
	else
		right = t_heredoc_init(str + at[0], len - at[0]);
	if (!right)
		return (free(left), NULL);
	full = ft_strjoin((char *[]){left, right, NULL}, "");
	return (free(left), free(right), full);
}
