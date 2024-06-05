/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parser_skip_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:00:53 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_parser.h"

int	t_parser_skip_string(int pos, char *str, int len)
{
	char	c;

	if (!str || pos < 0)
		return (pos);
	c = str[pos];
	if ((c == '"') || (c == '\''))
	{
		pos++;
		while ((pos < len) && str[pos] && (str[pos] != c))
			pos++;
		if ((pos < len) && (str[pos] == c))
			pos++;
	}
	return (pos);
}
