/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:38:43 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if ((n < 1) || (s1 == s2))
		return (0);
	if (*s1 && *s1 == *s2)
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
