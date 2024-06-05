/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_numeric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:28:02 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include <limits.h>

static int	check_positive_limit(unsigned long long p)
{
	int	flags;

	flags = 0;
	if (p > SCHAR_MAX)
		flags |= GREATER_THAN_SCHAR_MAX;
	if (p > UCHAR_MAX)
		flags |= GREATER_THAN_UCHAR_MAX;
	if (p > CHAR_MAX)
		flags |= GREATER_THAN_CHAR_MAX;
	if (p > SHRT_MAX)
		flags |= GREATER_THAN_SHRT_MAX;
	if (p > USHRT_MAX)
		flags |= GREATER_THAN_USHRT_MAX;
	if (p > INT_MAX)
		flags |= GREATER_THAN_INT_MAX;
	if (p > UINT_MAX)
		flags |= GREATER_THAN_UINT_MAX;
	if (p > LONG_MAX)
		flags |= GREATER_THAN_LONG_MAX;
	if (p > ULONG_MAX)
		flags |= GREATER_THAN_ULONG_MAX;
	if (p > LLONG_MAX)
		flags |= GREATER_THAN_LLONG_MAX;
	return (flags);
}

static int	check_negative_limit(unsigned long long p)
{
	int	flags;

	flags = 0;
	if (p > (unsigned long long)SCHAR_MAX + 1)
		flags |= LOWER_THAN_SCHAR_MIN;
	if (p > (unsigned long long)UCHAR_MAX + 1)
		flags |= LOWER_THAN_UCHAR_MIN;
	if (p > (unsigned long long)CHAR_MAX + 1)
		flags |= LOWER_THAN_CHAR_MIN;
	if (p > (unsigned long long)SHRT_MAX + 1)
		flags |= LOWER_THAN_SHRT_MIN;
	if (p > (unsigned long long)USHRT_MAX + 1)
		flags |= LOWER_THAN_USHRT_MIN;
	if (p > (unsigned long long)INT_MAX + 1)
		flags |= LOWER_THAN_INT_MIN;
	if (p > (unsigned long long)UINT_MAX + 1)
		flags |= LOWER_THAN_UINT_MIN;
	if (p > (unsigned long long)LONG_MAX + 1)
		flags |= LOWER_THAN_LONG_MIN;
	if (p > (unsigned long long)ULONG_MAX + 1)
		flags |= LOWER_THAN_ULONG_MIN;
	if (p > (unsigned long long)LLONG_MAX + 1)
		flags |= LOWER_THAN_LLONG_MIN;
	return (flags);
}

static unsigned long long	check_limit(
	int sign,
	unsigned long long result,
	char c,
	int *flags)
{
	unsigned long long	p;

	p = 10 * result + c - '0';
	if (flags)
	{
		if (sign > 0)
			*flags |= check_positive_limit(p);
		else if (sign < 0)
			*flags |= check_negative_limit(p);
	}
	return (p);
}

long long	ft_parse_numeric(const char *str, int *flags)
{
	int					i;
	int					sign;
	unsigned long long	result;

	if (flags)
		*flags = 0;
	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
		if (str[i++] == '-')
			sign = -1;
	if (flags && !ft_isdigit(str[i]))
		*flags |= NOT_A_NUMBER;
	while (ft_isdigit(str[i]))
		result = check_limit(sign, result, str[i++], flags);
	if (flags && str[i])
		*flags |= NOT_A_NUMBER;
	return (result * sign);
}
