/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:42:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"

int	ft_varlen(const char *str)
{
	int	i;

	i = 0;
	if (ft_isvstart(str[0]))
	{
		i = 1;
		while (ft_isvchar(str[i]))
			i++;
	}
	if ((str[i] == '=') || (str[i] == '\0'))
		return (i);
	return (-i);
}
