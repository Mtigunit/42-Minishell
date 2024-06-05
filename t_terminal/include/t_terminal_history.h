/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_history.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:40:29 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TERMINAL_HISTORY_H
# define T_TERMINAL_HISTORY_H

# define T_TERMINAL_HISTORY_SIZE		1024
# define T_TERMINAL_HISTORY_REST_INDEX	9161
# define T_TERMINAL_HISTORY_GET			0

typedef struct s_terminal_history
{
	char	**history;
	int		history_index;
	int		history_len;
	int		history_size;
}	t_terminal_history;

t_terminal_history	*t_terminal_history_request(int req);
int					t_terminal_history_add(char *str);
char				*t_terminal_history_get(void);
void				t_terminal_history_up(void);
void				t_terminal_history_down(void);

#endif//!T_TERMINAL_HISTORY_H