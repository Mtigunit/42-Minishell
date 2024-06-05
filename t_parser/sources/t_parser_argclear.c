/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parser_argclear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 01:55:03 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_parser.h"

char	*t_parser_argclear(char *src, int len)
{
	int	i;

	i = 0;
	while ((i < len) && (src[i]))
	{
		if (src[i] == CHAR_FAKE_STAR)
			src[i] = '*';
		else if (src[i] == CHAR_FAKE_DOLLAR_SIGN)
			src[i] = '$';
		i++;
	}
	return (src);
}
