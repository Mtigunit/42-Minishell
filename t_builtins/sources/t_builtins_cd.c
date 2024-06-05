/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_builtins_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:22:00 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/syslimits.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "minilibc.h"
#include "t_errorhandler.h"
#include "t_builtins.h"

static inline int	change_directory(char *filename, char *cwd)
{
	int		ret;

	if (filename[0] == '/')
		return (chdir(filename));
	getcwd(cwd, PATH_MAX);
	filename = ft_strjoin((char *[]){cwd, filename, NULL}, "/");
	if (!filename)
		return (-1);
	ret = chdir(filename);
	free(filename);
	return (ret);
}

int	t_builtins_cd(int argc, char **argv, __attribute__ ((unused)) char **env)
{
	char	cwd[PATH_MAX];
	char	*oldcwd;
	char	*dirname;

	if ((argc < 2) || !ft_strcmp(argv[1], "~"))
	{
		dirname = ft_getenv("HOME");
		if (!dirname)
			return (t_errorhandler_error(2, (char *[]){"cd: ",
					"HOME not set", NULL}));
	}
	else
		dirname = argv[1];
	if (!dirname || !*dirname)
		return (write(2, "cd with only a relative or absolute path\n", 41), 1);
	oldcwd = ft_getenv("PWD");
	getcwd(cwd, PATH_MAX);
	if (change_directory(dirname, cwd) < 0)
		return (t_errorhandler_error(
				5, (char *[]){
				"cd: ", dirname, ": ", strerror(errno), NULL}
		));
	ft_setenv("OLDPWD", oldcwd, 1);
	getcwd(cwd, PATH_MAX);
	return (ft_setenv("PWD", cwd, 1), 0);
}
