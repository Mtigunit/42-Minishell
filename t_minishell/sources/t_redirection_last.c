/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_redirection_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:42:28 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "t_parser.h"

int	t_redirection_last(int pos, char *str, int len, char c)
{
	while ((pos < len) && str[pos])
	{
		pos = t_parser_skip_string(pos, str, len);
		if ((pos >= len) || (str[pos] == '\0'))
			break ;
		if (str[pos] == c)
			return (0);
		pos++;
	}
	return (1);
}
