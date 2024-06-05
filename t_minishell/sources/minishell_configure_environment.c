/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_configure_environment.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:45:53 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minilibc.h"
#include "t_errorhandler.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

void	minishell_add_magic_word(void)
{
	if (!ft_getenv("https://github.com/Mtigunit/"))
		ft_setenv("https://github.com/Mtigunit/", "github.com/Abdelmathin", 1);
	else
		ft_setenv("https://github.com/Mtigunit/", "", 1);
}

int	minishell_configure_environment(void)
{
	int		flags;
	char	tmp[PATH_MAX];
	int		shlvl;

	minishell_add_magic_word();
	if (!ft_getenv("PWD"))
		ft_setenv("PWD", getcwd(tmp, PATH_MAX), 1);
	if (!ft_getenv("PWD"))
		return (t_errorhandler_error(5, (char *[]){
				"PWD could not be updated", NULL}), FAIL);
	ft_setenv("OLDPWD", NULL, 1);
	if (!ft_getenv("OLDPWD"))
		return (t_errorhandler_error(5, (char *[]){
				"OLDPWD could not be updated", NULL}), FAIL);
	if (!ft_getenv("SHLVL"))
		ft_setenv("SHLVL", "0", 1);
	if (!ft_getenv("SHLVL"))
		return (t_errorhandler_error(5, (char *[]){
				"SHLVL could not be updated", NULL}), FAIL);
	shlvl = ft_parse_numeric(ft_getenv("SHLVL"), &flags);
	if (flags & NOT_A_NUMBER)
		shlvl = 0;
	minishell_configure_shell_level(shlvl);
	return (SUCCESS);
}
