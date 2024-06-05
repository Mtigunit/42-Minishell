/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_heredoc_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:06:23 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_heredoc.h"
#include "t_parser.h"

char	*t_heredoc_init(char *str, int len)
{
	int		i;

	i = 0;
	while ((i < len) && str[i])
	{
		i = t_parser_skip_string(i, str, len);
		if ((i + 1 < len) && (str[i] == '<') && (str[i + 1] == '<'))
			return (t_heredoc_read(&i, str, len));
		i++;
	}
	return ((char *)0);
}
