/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:35:12 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell_mode(int req)
{
	static int	mode;

	if (req == MINISHELL_MODE_RESET)
		mode = 0;
	else if (req == MINISHELL_MODE_IGNORE_LINE)
		mode = MINISHELL_MODE_IGNORE_LINE;
	else if (req == MINISHELL_MODE_GET)
		return (mode);
	return (mode);
}
