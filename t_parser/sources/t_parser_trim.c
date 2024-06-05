/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parser_trim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 00:59:14 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_parser.h"
#include "minilibc.h"

char	*t_parser_trim(char *str, int *len)
{
	int	pos;
	int	start;

	if (!str || !len)
		return (str);
	pos = 0;
	pos = t_parser_skip_spaces(pos, str, *len);
	start = pos;
	while (pos < *len)
	{
		pos = t_parser_skip_string(pos, str, *len);
		if ((pos < *len) && (str[pos] == '#'))
			if ((pos == 0) || ft_isspace(str[pos - 1]))
				break ;
		if (pos < *len)
			pos++;
	}
	return (*len = pos - start, str + start);
}
