/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parser_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:05:50 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_parser.h"

static inline int	t_expand_setmode(int a)
{
	static int	mode = 1;

	if (a == 0)
		mode = 0;
	else if (a == 1)
		mode = 1;
	return (mode);
}

int	t_expand_isenabled(void)
{
	return (t_expand_setmode(2) != 0);
}

void	t_expand_enable(void)
{
	t_expand_setmode(1);
}

void	t_expand_disable(void)
{
	t_expand_setmode(0);
}

void	t_parser_append_char(int at, char *dest, char c)
{
	if (dest)
		dest[at] = c;
}
