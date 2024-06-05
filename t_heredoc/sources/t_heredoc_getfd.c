/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_heredoc_getfd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:11:20 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_heredoc.h"
#include "minilibc.h"

int	t_heredoc_getfd(const char *str, int len)
{
	int	fd;
	int	pos;
	int	factor;

	if (!str || (len < 5))
		return (0);
	fd = 0;
	pos = 0;
	factor = 10000;
	while (factor && (pos < len) && ft_isdigit(str[pos]))
	{
		fd += (str[pos] - '0') * factor;
		pos++;
		factor = factor / 10;
	}
	return (fd);
}
