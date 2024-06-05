/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_executor_skip_blanks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 07:22:16 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include "t_executor.h"
#include "t_parser.h"

int	t_executor_skip_blanks(int pos, const char *str, int len)
{
	char	*value;

	if (!str || len < 1)
		return (0);
	while (pos < len)
	{
		pos = t_parser_skip_spaces(pos, str, len);
		if ((pos + 1 >= len) || (str[pos] != '$') || !ft_isvstart(str[pos + 1]))
			break ;
		value = ft_getvar(str + pos);
		if (value && *value)
			break ;
		pos += 2;
		while ((pos < len) && ft_isvchar(str[pos]))
			pos++;
	}
	return (pos);
}
