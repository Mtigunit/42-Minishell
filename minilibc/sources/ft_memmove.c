/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:23:05 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = (s1 > s2) * (n - 1);
	while ((0 <= i) && (i < n) && (s1 != s2))
	{
		((char *)s1)[i] = ((char *)s2)[i];
		i += (s1 < s2) - (s1 > s2);
	}
	return (s1);
}
