/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_builtins_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:21:07 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "minilibc.h"
#include "t_builtins.h"

static inline int	_echo_option(const char *str)
{
	int	i;

	i = 1;
	while ((str[0] == '-') && (str[i] == 'n'))
		i++;
	return ((str[i] == 0) * (i > 1));
}

int	t_builtins_echo(int argc, char **argv, __attribute__ ((unused)) char **env)
{
	int		i;
	int		n_option;
	char	*arg;

	i = 1;
	n_option = 0;
	while ((i < argc) && argv[i] && _echo_option(argv[i]))
	{
		i++;
		n_option = 1;
	}
	while ((i < argc) && argv[i])
	{
		arg = argv[i++];
		write(1, arg, ft_strlen(arg));
		write(1, " ", ((i < argc) && argv[i]));
	}
	write(1, "\n", !n_option);
	return (0);
}
