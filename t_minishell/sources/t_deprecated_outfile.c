/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_deprecated_outfile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:42:17 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minilibc.h"
#include "t_parser.h"

int	t_deprecated_outfile(int pos, char *str, int len)
{
	while ((pos < len) && str[pos])
	{
		if (ft_strchr("|&<)", str[pos]))
			return (0);
		pos = t_parser_skip_string(pos, str, len);
		if ((pos < len) && (str[pos] == '>'))
			return (1);
		pos++;
	}
	return (0);
}
