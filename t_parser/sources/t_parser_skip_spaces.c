/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parser_skip_spaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:00:06 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_parser.h"
#include "minilibc.h"

int	t_parser_skip_spaces(int pos, const char *str, int len)
{
	if (!str || pos < 0)
		return (pos);
	while ((pos < len) && ft_isspace(str[pos]))
		pos++;
	return (pos);
}
