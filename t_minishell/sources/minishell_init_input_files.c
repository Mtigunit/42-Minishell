/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init_input_files.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 23:02:07 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minilibc.h"
#include "t_errorhandler.h"
#include "t_parser.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_norm
{
	int		dx;	
	int		filelen;
	char	*filename;
	int		oldpos;
	int		fd;
	int		mode;
	char	*new;
	char	*l;
}	t_norm;

char	*minishell_init_input_files(int pos, char *str, int len)
{
	t_norm	p;

	p.oldpos = pos;
	pos = t_parser_skip_spaces(pos + 1, str, len);
	p.dx = t_parser_argcpy(&p.filelen, NULL, str + pos, len - pos);
	p.filename = malloc(sizeof(char) * (p.filelen + 1));
	t_parser_argcpy(&p.filelen, p.filename, str + pos, len - pos);
	p.fd = open(p.filename, O_RDONLY);
	if (p.fd < 0)
		t_errorhandler_perror(p.filename);
	free(p.filename);
	if (t_redirection_last(pos + p.dx, str, len, '<'))
	{
		p.new = malloc(sizeof(char) * (5 + len - p.dx + 1));
		ft_strncpy(p.new, str, pos);
		t_redirection_setfd(p.new + pos, p.fd);
		ft_strncpy(p.new + pos + 5, str + pos + p.dx, len - pos - p.dx);
		return (p.new[5 + len - p.dx] = 0, p.new);
	}
	if (p.fd >= 0)
		close(p.fd);
	p.new = ft_strnjoin(str, str + pos + p.dx, p.oldpos, len - pos - p.dx);
	p.l = minishell_init_files(0, p.new, ft_strlen(p.new));
	return (free(p.new), p.l);
}
