/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal_readcode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 08:50:05 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_terminal.h"
#include "t_signalshandler.h"
#include <unistd.h>
#include <stdio.h>

int	t_terminal_input_request(char c, int req)
{
	static int	isenabled;
	static int	isfake;
	static int	pfd[2];
	static int	stdin_copy;

	if (req == T_TERMINAL_READ_MODE_IS_ENABLED)
		return (isenabled);
	if (req == T_TERMINAL_READ_MODE_ENABLE)
		return (isenabled = 1, 0);
	if (req == T_TERMINAL_READ_MODE_DISABLE)
		return (isenabled = 0, 0);
	if (req == T_TERMINAL_FAKE_INPUT)
		return (isfake = 1, pipe(pfd), stdin_copy = dup(STDIN_FILENO),
			dup2(pfd[0], STDIN_FILENO), write(pfd[1], &c, 1),
			close(pfd[1]), 1);
	if (req == T_TERMINAL_UNSET_FAKE_INPUT)
	{
		isfake = 0;
		return (close(pfd[0]), dup2(stdin_copy, STDIN_FILENO), 0);
	}
	if (req == T_TERMINAL_IS_FAKE_INPUT)
		return (isfake);
	return (0);
}

int	t_terminal_fakeinput(char c)
{
	if (!t_terminal_input_request(0, T_TERMINAL_READ_MODE_IS_ENABLED))
		return (0);
	t_terminal_input_request(c, T_TERMINAL_FAKE_INPUT);
	return (0);
}

int	ft_read(int fildes, void *buf, size_t nbyte)
{
	ssize_t	reads;

	t_terminal_input_request(0, T_TERMINAL_READ_MODE_ENABLE);
	reads = read(fildes, buf, nbyte);
	t_terminal_input_request(0, T_TERMINAL_READ_MODE_DISABLE);
	if (t_terminal_input_request(0, T_TERMINAL_IS_FAKE_INPUT))
	{
		t_terminal_input_request(0, T_TERMINAL_UNSET_FAKE_INPUT);
		return (1);
	}
	return (reads);
}

int	t_terminal_readcode(int fdin)
{
	int		reads;
	char	c;

	reads = ft_read(fdin, &c, 1);
	if (c == 27)
	{
		reads = ft_read(fdin, &c, 1);
		if (c == 91)
		{
			reads = ft_read(fdin, &c, 1);
			if (c == 65)
				return (KEYCODE_ARROW_UP);
			if (c == 66)
				return (KEYCODE_ARROW_DOWN);
			if (c == 67)
				return (KEYCODE_ARROW_RIGHT);
			if (c == 68)
				return (KEYCODE_ARROW_LEFT);
		}
	}
	if (c == 4)
		return (t_signalshandler_catch(EOF));
	return (c);
}
