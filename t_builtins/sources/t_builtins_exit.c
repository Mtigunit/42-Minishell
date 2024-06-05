/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_builtins_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:22:12 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_builtins.h"
#include "minilibc.h"
#include "t_errorhandler.h"

int	t_builtins_exit(int argc, char **argv, __attribute__ ((unused)) char **env)
{
	int	flags;
	int	status;

	flags = 0;
	status = ft_getstatus();
	ft_putstr_fd("exit\n", 2);
	if (argc == 2)
		status = ft_parse_numeric(argv[1], &flags);
	if ((argc > 1) && (flags & NOT_A_NUMBER || flags & LOWER_THAN_LONG_MIN
			|| flags & GREATER_THAN_LONG_MAX))
	{
		t_errorhandler_error(
			4, (char *[]){"exit: ", argv[1], ": ",
			"numeric argument required", NULL}
			);
		ft_exit(255);
	}
	if (argc > 2)
		return (t_errorhandler_error(
				2, (char *[]){"exit: ", "too many arguments", NULL}
		));
	status = status & 255;
	ft_exit(status);
	return (status);
}
