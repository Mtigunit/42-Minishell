/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_errorhandler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:27:58 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_errorhandler.h"
#include "minilibc.h"

int	t_errorhandler_error(int argc, char **argv)
{
	int	i;

	ft_putstr_fd(ft_progname(), 2);
	ft_putstr_fd(": ", 2);
	i = 0;
	while ((i < argc) && argv && argv[i])
	{
		ft_putstr_fd(argv[i], 2);
		i++;
	}
	ft_putstr_fd("\n", 2);
	return (1);
}
