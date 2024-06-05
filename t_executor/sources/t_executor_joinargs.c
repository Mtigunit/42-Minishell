/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_executor_joinargs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:04:18 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_executor.h"
#include "t_parser.h"
#include "minilibc.h"
#include <stdlib.h>

char	*t_executor_joinargs(char *left, char *right, int llen, int rlen)
{
	int		offset;
	int		filelen;
	int		new_cmd_len;
	char	*new_cmd;

	offset = t_parser_argcpy(&filelen, NULL, right, rlen);
	new_cmd_len = llen + 1 + rlen - offset;
	new_cmd = malloc(new_cmd_len + 1);
	if (!new_cmd)
		return (NULL);
	ft_strncpy(new_cmd, left, llen);
	new_cmd[llen] = 0;
	ft_strcat(new_cmd, " ");
	ft_strncat(new_cmd, right + offset, rlen - offset);
	new_cmd[new_cmd_len] = 0;
	return (new_cmd);
}
