/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:04:39 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include <limits.h>
#include <unistd.h>

static inline char	*ft_cwdbasecpy(char *dest)
{
	int		i;
	int		j;
	char	dirname[PATH_MAX];

	dirname[0] = 0;
	getcwd(dirname, PATH_MAX);
	i = 0;
	j = 0;
	while (dirname[i])
	{
		if (dirname[i] == '/')
			j = i;
		i++;
	}
	if (dirname[j] && dirname[j + 1])
		j++;
	ft_strcpy(dest, dirname + j);
	return (dest);
}

static inline void	help_prompt(char *prompt, int status)
{
	int			i;

	prompt[0] = 0;
	ft_strcat(prompt, OS_UNICODE_LOGO " ");
	ft_strcat(prompt, ft_hostname());
	i = 0;
	while (prompt[i] && prompt[i] != '.')
		i++;
	prompt[i] = 0;
	if (isatty(0))
	{
		ft_strcat(prompt, "\033[40m");
		prompt[ft_strlen(prompt) - 2] = '2' - (status != 0);
	}
	ft_strcat(prompt, "(");
	ft_timecpy(prompt + ft_strlen(prompt));
	ft_strcat(prompt, ")");
	if (isatty(0))
		ft_strcat(prompt, "\033[0m");
}

char	*ft_prompt(void)
{
	int			status;
	char		*user_defined;
	static char	prompt[PATH_MAX + 512];

	user_defined = ft_getenv("PS1");
	if (user_defined)
		return (user_defined);
	status = ft_getstatus();
	help_prompt(prompt, status);
	ft_strcat(prompt, "[");
	if (isatty(0))
		ft_strcat(prompt, "\033[36m");
	ft_cwdbasecpy(prompt + ft_strlen(prompt));
	if (isatty(0))
		ft_strcat(prompt, "\033[0m");
	ft_strcat(prompt, "][");
	if (status && isatty(0))
		ft_strcat(prompt, "\033[31m");
	else if (isatty(0))
		ft_strcat(prompt, "\033[32m");
	ft_numeric2string(prompt + ft_strlen(prompt), status);
	if (isatty(0))
		ft_strcat(prompt, "\033[0m");
	ft_strcat(prompt, "]$ ");
	return (prompt);
}
