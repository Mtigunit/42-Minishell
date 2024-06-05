/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_heredoc_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:00:15 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_heredoc.h"
#include "t_parser.h"

int	t_heredoc_last(int pos, char *str, int len)
{
	while ((pos + 1 < len) && str[pos])
	{
		pos = t_parser_skip_string(pos, str, len);
		if ((str[pos] == '<') && (str[pos + 1] == '<'))
			return (0);
		pos++;
	}
	return (1);
}
