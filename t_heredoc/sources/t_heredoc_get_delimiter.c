/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_heredoc_get_delimiter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:00:29 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_heredoc.h"
#include "t_parser.h"
#include <stdlib.h>

int	t_heredoc_get_delimiter(char **delimiter, int pos, const char *str, int len)
{
	int	lim_len;
	int	move;

	t_expand_disable();
	move = t_parser_argcpy(&lim_len, NULL, str + pos, len - pos);
	delimiter[0] = malloc((sizeof(char)) * (lim_len + 1));
	if (!delimiter[0])
		return (move);
	move = t_parser_argcpy(&lim_len, delimiter[0], str + pos, len - pos);
	t_expand_enable();
	t_parser_argclear(delimiter[0], lim_len);
	return (pos + move);
}
