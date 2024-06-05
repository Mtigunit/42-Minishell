/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_configure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 08:36:57 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minilibc.h"
#include "t_errorhandler.h"
#include <limits.h>
#include <unistd.h>

int	minishell_configure(int argc, char **argv, char **env)
{
	if (minishell_usage(argc, argv))
		return (FAIL);
	if (!__minilibc(argc, argv, env, MINILIBC_REQUEST_INIT))
		return (FAIL);
	if (minishell_configure_environment())
		return (FAIL);
	return (0);
}
