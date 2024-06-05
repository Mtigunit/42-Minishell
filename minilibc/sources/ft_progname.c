/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_progname.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:57:54 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include <limits.h>

char	*ft_progname(void)
{
	int			i;
	int			j;
	char		**argv;
	static char	name[NAME_MAX];

	argv = ft_getargv();
	if (!argv || !argv[0])
		return (name);
	i = 0;
	j = 0;
	while (argv[0][i])
	{
		name[j++] = argv[0][i];
		if (argv[0][i] == '/')
			j = 0;
		i++;
	}
	name[j] = 0;
	return (name);
}
