/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_builtins_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:21:57 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/syslimits.h>
#include "t_builtins.h"
#include "minilibc.h"
#include <unistd.h>

int	t_builtins_pwd(
	__attribute__ ((unused)) int	argc,
	__attribute__ ((unused)) char	**argv,
	__attribute__ ((unused)) char	**env
)
{
	char	pathname[PATH_MAX];

	getcwd(pathname, PATH_MAX);
	ft_putendl_fd(pathname, 1);
	return (0);
}
