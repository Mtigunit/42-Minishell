/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:29:03 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	while (s1[pos])
		pos++;
	while (n && *s2)
	{
		s1[pos] = *s2;
		s2++;
		pos++;
		n--;
	}
	s1[pos] = 0;
	return (s1);
}
