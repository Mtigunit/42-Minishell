/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:42:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include <stdlib.h>

char	**ft_strsdup(char **strs)
{
	size_t	len;
	char	**newstrs;

	if (!strs)
		return (NULL);
	len = 0;
	while (strs[len])
		len++;
	newstrs = malloc(sizeof(char *) * (len + 1));
	if (!newstrs)
		return (NULL);
	len = 0;
	while (strs[len])
	{
		newstrs[len] = ft_strdup(strs[len]);
		if (!newstrs[len])
		{
			ft_strsfree(newstrs);
			return (NULL);
		}
		len++;
	}
	newstrs[len] = NULL;
	return (newstrs);
}
