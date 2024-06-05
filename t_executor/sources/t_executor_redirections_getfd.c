/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_executor_redirections_getfd.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 02:51:21 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_executor.h"
#include "minilibc.h"

int	t_executor_redirections_getfd(const char *str, int len)
{
	int		i;
	int		fd;

	if (!str || len < FILE_DESCRIPTOR_MAXLEN)
		return (-1);
	fd = 0;
	i = 0;
	while (i < FILE_DESCRIPTOR_MAXLEN)
	{
		if ((str[i] < '0') || (str[i] > '9'))
			return (-1);
		fd = 10 * fd + str[i] - '0';
		i++;
	}
	return (fd);
}
