/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_heredoc_deprecated.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:00:23 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_heredoc.h"
#include "minilibc.h"
#include "t_parser.h"

int	t_heredoc_deprecated(char *dest, int pos, char *str, int len)
{
	while ((pos + 1 < len) && str[pos])
	{
		if (ft_strchr("|&", str[pos]))
			return (0);
		pos = t_parser_skip_string(pos, str, len);
		if ((str[pos] == '<') && (str[pos + 1] == '<'))
		{
			dest[0] = '-';
			dest[1] = '-';
			dest[2] = '-';
			dest[3] = '-';
			dest[4] = '-';
			return (1);
		}
		pos++;
	}
	return (0);
}
