/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_errorhandler_perror.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 08:05:59 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include "t_errorhandler.h"
#include <stdio.h>

int	t_errorhandler_perror(char *message)
{
	ft_putstr_fd(ft_progname(), 2);
	ft_putstr_fd(": ", 2);
	if (message)
	{
		ft_putstr_fd(message, 2);
		ft_putstr_fd(": ", 2);
	}
	perror("");
	return (1);
}
