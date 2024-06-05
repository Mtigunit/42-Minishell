/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:17:05 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"
#include <unistd.h>

int	t_terminal_getcol(int fdin)
{
	int				j;
	int				_col;
	char			response[32];
	struct termios	old_termios;
	struct termios	new_termios;

	if (!isatty(0))
		return (0);
	tcgetattr(fdin, &old_termios);
	new_termios = old_termios;
	new_termios.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(fdin, TCSANOW, &new_termios);
	write(STDOUT_FILENO, "\x1b[6n", 4);
	read(STDIN_FILENO, response, sizeof(response));
	tcsetattr(fdin, TCSANOW, &old_termios);
	j = 2;
	while ((j < 32) && ('0' <= response[j] && response[j] <= '9'))
		j++;
	j++;
	_col = 0;
	while ((j < 32) && ('0' <= response[j] && response[j] <= '9'))
		_col = 10 * _col + response[j++] - '0';
	return (_col);
}
