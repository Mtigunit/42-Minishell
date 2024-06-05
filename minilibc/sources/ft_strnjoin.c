/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:40:07 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnjoin(char *s1, char *s2, int l1, int l2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s1 || !s2 || (l1 < 0) || (l2 < 0))
		return (NULL);
	s3 = malloc(sizeof(char) * (l1 + l2 + 1));
	if (!s3)
		return (NULL);
	i = 0;
	while (i < l1)
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < l2)
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = 0;
	return (s3);
}
