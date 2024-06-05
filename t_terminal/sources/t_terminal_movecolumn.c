/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_movecolumn.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:40:50 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"

void	t_terminal_movecolumn(int by)
{
	t_terminal	*t;

	t = t_terminal_request();
	if (!t)
		return ;
	t->column += by;
	if (t->column < 0)
		t->column = 0;
	if (t->column > t->length)
		t->column = t->length;
}
