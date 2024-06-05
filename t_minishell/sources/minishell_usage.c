/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_usage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:52:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minilibc.h"

int	minishell_usage(int argc, char **argv)
{
	(void) argv;
	if (argc != 1)
	{
		ft_putstr_fd("MiniShell 1.0.0 (default, Feb 26 2023, 23:14:56)\n", 2);
		if (argv && argv[0])
		{
			ft_putstr_fd("usage (with no options or arguments): \n\t", 2);
			ft_putstr_fd(argv[0], 2);
			ft_putstr_fd("\n", 2);
		}
		ft_putstr_fd(
			"builtins:\n"
			"\t* echo  : with option -n\n"
			"\t* cd    : with only a relative or absolute path\n"
			"\t* pwd   : with no options\n"
			"\t* export: with no options\n"
			"\t* unset : with no options\n"
			"\t* env   : with no options or arguments\n"
			"\t* exit  : with no options\n", 2);
		return (1);
	}
	return (0);
}
