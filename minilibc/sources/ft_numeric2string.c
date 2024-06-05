/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numeric2string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:55:47 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"

char	*ft_numeric2string(char *string, long long numeric)
{
	int			length;
	long long	old_numeric;

	if (!string)
		return ((char *)0);
	length = (numeric <= 0);
	old_numeric = numeric;
	while (old_numeric && ++length)
		old_numeric = old_numeric / 10;
	string[length--] = 0;
	while (length >= 0)
	{
		string[length--] = "9876543210123456789"[9 + numeric % 10];
		if ((length >= 0) && (-10 < numeric) && (numeric < 0))
			string[length--] = '-';
		numeric = numeric / 10;
	}
	return (string);
}
