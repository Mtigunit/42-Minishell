/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_errorhandler_developer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 08:12:42 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_errorhandler.h"
#include "minilibc.h"
#include <unistd.h>

void	t_errorhandler_developer(int line, const char *file)
{
	(void) line;
	write(2, file, ft_strlen(file));
	write(2, "ila wssalti lhna makhask tvaladi minishell!\n", 43);
	ft_exit(1);
}
