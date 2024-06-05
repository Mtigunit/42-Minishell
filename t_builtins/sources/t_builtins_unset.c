/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_builtins_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:22:06 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_builtins.h"
#include "minilibc.h"
#include "t_errorhandler.h"

static inline int	_unset_check(char *identifier)
{
	int	i;

	if (ft_isvstart(identifier[0]))
	{
		i = 1;
		while (ft_isvchar(identifier[i]))
			i++;
		if (identifier[i] == 0)
			return (0);
	}
	return (t_errorhandler_error(
			5, (char *[]){
			"unset: ", "`", identifier, "': ", "not a valid identifier", NULL}
	));
}

int	t_builtins_unset(int argc, char **argv, __attribute__ ((unused)) char **env)
{
	int	i;
	int	status;

	i = 1;
	status = 0;
	while (i < argc)
	{
		status |= _unset_check(argv[i]);
		ft_unsetenv(argv[i]);
		i++;
	}
	return (status);
}
