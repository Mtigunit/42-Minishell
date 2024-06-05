/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_setcolumn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:23:04 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"

void	t_terminal_setcolumn(int column)
{
	t_terminal	*t;

	t = t_terminal_request();
	if (!t)
		return ;
	t->column = column;
	if (t->column > t->length)
		t->column = t->length;
	if (t->column < 0)
		t->column = 0;
}
