/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:42:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		l1;
	char	*ret;

	l1 = 0;
	while (s1[l1])
		l1++;
	ret = malloc((l1 + 1) * sizeof(char));
	if (ret)
	{
		l1 = 0;
		while (s1[l1])
		{
			ret[l1] = s1[l1];
			l1++;
		}
		ret[l1] = 0;
	}
	return (ret);
}
