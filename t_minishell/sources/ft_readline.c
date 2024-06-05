/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:36:38 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minilibc.h"
#include "t_terminal.h"
#include <unistd.h>

char	*ft_readline(char *prompt)
{
	char	*line;

	line = t_terminal_readline(prompt);
	if (!line)
		return (line);
	if (!isatty(0))
	{
		write(2, "HADI MACHI TTY!\n", 16);
		ft_exit(0);
		return (0);
	}
	return (ft_strdup(line));
}
