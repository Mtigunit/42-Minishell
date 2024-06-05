/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:42:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include <stdlib.h>
#include <stddef.h>

char	**ft_strsjoin(char **dest, char **src)
{
	char	**ret;
	size_t	dest_len;

	if (!dest || !src)
		return (NULL);
	dest_len = ft_strslen(dest);
	ret = malloc((sizeof(char *)) * (dest_len + ft_strslen(src) + 1));
	if (!ret || !ft_strscpy(ret, dest) || !ft_strscpy(ret + dest_len, src))
		return (ft_strsfree(ret), NULL);
	return (ret);
}
