/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_configure_shell_level.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:46:08 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minilibc.h"
#include "t_errorhandler.h"

void	minishell_configure_shell_level(int shlvl)
{
	char	tmp[NUMERIC2STRING_MAX];

	if (shlvl < 0)
		shlvl = -1;
	if (shlvl == 999)
		ft_setenv("SHLVL", "", 1);
	else
	{
		ft_numeric2string(tmp, shlvl * (shlvl < 1000) + 1);
		ft_setenv("SHLVL", tmp, 1);
		if (shlvl >= 1000)
		{
			ft_numeric2string(tmp, shlvl + 1);
			t_errorhandler_error(5, (char *[]){"warning: ", "shell level (",
				tmp, ") too high, resetting to 1", NULL});
		}		
	}
}
