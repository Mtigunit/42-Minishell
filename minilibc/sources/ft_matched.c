/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matched.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 01:28:55 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"

int	ft_matched(const char *s1, const char *s2, int l1, int l2)
{
	int	p;
	int	i1;

	if ((l1 == l2) && (ft_strncmp(s1, s2, l1) == 0))
		return (1);
	i1 = 0;
	while ((i1 < l1) && (s1[i1] == '*'))
		i1++;
	if ((0 < i1) && (i1 == l1))
		return (1);
	if (i1 > 0)
	{
		p = 0;
		while (p < l2)
		{
			if (ft_matched(s1 + i1, s2 + p, l1 - i1, l2 - p))
				return (1);
			p++;
		}
	}
	if (l1 > 0 && l2 > 0 && s1[0] == s2[0])
		return (ft_matched(s1 + 1, s2 + 1, l1 - 1, l2 - 1));
	return (0);
}
