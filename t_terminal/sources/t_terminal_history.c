/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_history.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:37:27 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"
#include "t_terminal_history.h"
#include "minilibc.h"
#include <stdlib.h>

t_terminal_history	*t_terminal_history_request(int req)
{
	static int					entry;
	static t_terminal_history	h;

	if (entry++ == 0)
	{
		h.history_len = 0;
		h.history_size = T_TERMINAL_HISTORY_SIZE;
		if (h.history_size < 1)
			h.history_size = 0;
		h.history = ft_calloc(sizeof(char *), h.history_size);
	}
	if (req == T_TERMINAL_HISTORY_REST_INDEX)
		h.history_index = 0;
	return (&h);
}

int	t_terminal_history_add(char *str)
{
	int					i;
	t_terminal_history	*n;
	char				**history;

	n = t_terminal_history_request(T_TERMINAL_HISTORY_GET);
	if (n->history_len + 1 >= n->history_size)
	{
		n->history_size *= 2;
		if (n->history_size < 1)
			n->history_size = 2;
		history = ft_calloc(sizeof(char *), n->history_size);
		if (!history)
			return (-1);
		i = 0;
		while (n->history[i])
		{
			history[i] = n->history[i];
			i++;
		}
		history[i] = NULL;
		free(n->history);
		n->history = history;
	}
	n->history[n->history_len++] = ft_strdup(str);
	return (0);
}

char	*t_terminal_history_get(void)
{
	int					i;
	t_terminal_history	*n;

	n = t_terminal_history_request(T_TERMINAL_HISTORY_GET);
	i = n->history_index;
	if (i <= 0 || !n->history)
		return (NULL);
	if (n->history_len < i)
		return (n->history[0]);
	return (n->history[n->history_len - i]);
}

void	t_terminal_history_up(void)
{
	t_terminal_history	*n;

	n = t_terminal_history_request(T_TERMINAL_HISTORY_GET);
	n->history_index++;
	if (n->history_index > n->history_len)
		n->history_index = n->history_len;
	else if (n->history_index < 0)
		n->history_index = 0;
}

void	t_terminal_history_down(void)
{
	t_terminal_history	*n;

	n = t_terminal_history_request(T_TERMINAL_HISTORY_GET);
	n->history_index--;
	if (n->history_index > n->history_len)
		n->history_index = n->history_len;
	else if (n->history_index < 0)
		n->history_index = 0;
}
