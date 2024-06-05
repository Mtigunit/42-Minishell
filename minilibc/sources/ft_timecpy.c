/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timecpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 05:04:47 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"

char	*ft_timecpy(char *dest)
{
	int	t;
	int	hour;
	int	minute;
	int	second;

	t = ft_gettime();
	hour = (t % 86400) / 3600;
	minute = (t % 3600) / 60;
	second = t % 60;
	t = 0;
	dest[t++] = '0' + (((hour + 1) % 24) / 10);
	dest[t++] = '0' + (((hour + 1) % 24) % 10);
	dest[t++] = ':';
	dest[t++] = '0' + (minute / 10);
	dest[t++] = '0' + (minute % 10);
	dest[t++] = ':';
	dest[t++] = '0' + (second / 10);
	dest[t++] = '0' + (second % 10);
	dest[t++] = 0;
	return (dest);
}
