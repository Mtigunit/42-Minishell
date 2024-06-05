/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numeric2stringbase.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:33:17 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"

int	ft_baselen(const char *base)
{
	int	i;
	int	j;

	if (!base)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

char	*ft_numeric2stringbase(char *string, long long numeric,
		const char *base)
{
	int			length;
	long long	old_numeric;
	int			base_len;

	base_len = ft_baselen(base);
	if (!string || base_len < 2)
		return ((char *)0);
	length = (numeric <= 0);
	old_numeric = numeric;
	while (old_numeric && ++length)
		old_numeric = old_numeric / base_len;
	string[length--] = 0;
	while (length >= 0)
	{
		if (numeric >= 0)
			string[length--] = base[numeric % base_len];
		else
			string[length--] = base[-(numeric % base_len)];
		if ((length >= 0) && (-base_len < numeric) && (numeric < 0))
			string[length--] = '-';
		numeric = numeric / base_len;
	}
	return (string);
}
