/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:42:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include <stdlib.h>

char	*ft_strndup(const char *const src, size_t size)
{
	size_t	i;
	char	*ret;

	ret = malloc((size + 1) * sizeof(char));
	if (ret)
	{
		i = 0;
		while (i < size)
		{
			ret[i] = src[i];
			i++;
		}
		ret[i] = 0;
	}
	return (ret);
}
