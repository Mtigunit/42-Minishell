/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_heredoc_fini.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:06:27 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_heredoc.h"
#include "t_parser.h"
#include <unistd.h>

void	t_heredoc_fini(char *str, int len)
{
	int		i;
	int		fd;

	if (!str || len <= 0)
		return ;
	i = 0;
	while (i < len && str[i])
	{
		i = t_parser_skip_string(i, str, len);
		if ((i + 1 < len) && (str[i] == '<') && (str[i + 1] == '<'))
		{
			i = t_parser_skip_spaces(i + 2, str, len);
			fd = t_heredoc_getfd(str + i, len - i);
			if (fd > 0)
				close(fd);
		}
		i++;
	}
}
