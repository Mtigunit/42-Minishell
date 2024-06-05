/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_heredoc_should_expand.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:58:29 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_heredoc.h"

int	t_heredoc_should_expand(const char *str, int len)
{
	int	pos;

	pos = 0;
	while ((pos < len) && str[pos])
	{
		if ((str[pos] == '"') || (str[pos] == '\''))
			return (0);
		pos++;
	}
	return (1);
}
