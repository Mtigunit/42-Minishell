/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_redirection_setfd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:39:43 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minilibc.h"

int	t_redirection_setfd(char *dest, int herdoc_fd)
{
	if (!dest)
		return (0);
	if (herdoc_fd < 0)
	{
		ft_strcpy(dest, "-----");
		return (1);
	}
	dest[0] = '0' + (herdoc_fd / 10000);
	herdoc_fd %= 10000;
	dest[1] = '0' + (herdoc_fd / 1000);
	herdoc_fd %= 1000;
	dest[2] = '0' + (herdoc_fd / 100);
	herdoc_fd %= 100;
	dest[3] = '0' + (herdoc_fd / 10);
	herdoc_fd %= 10;
	dest[4] = '0' + (herdoc_fd);
	dest[5] = 0;
	return (1);
}
