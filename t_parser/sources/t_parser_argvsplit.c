/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parser_argvsplit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:42:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/t_parser.h"
#include "minilibc.h"
#include <stdlib.h>

int	t_parser_eos(int pos, const char *str, int len)
{
	if (!str || (pos >= len) || (pos < 0))
		return (1);
	if (str[pos] == '\0')
		return (1);
	return (0);
}

int	t_parser_argument(int *argc, char **argv, const char *str, int len)
{
	int		i;
	int		arg_len;
	char	*argument;
	int		wild_len;

	i = 0;
	if (argc && !t_parser_eos(i, str, len) && !ft_isspace(str[i]))
	{
		if (t_parser_argcpy(&arg_len, NULL, str, len) < 0)
			return (-1);
		argument = malloc(sizeof(char) * (arg_len + 1));
		if (!argument)
			return (-1);
		i = t_parser_argcpy(&arg_len, argument, str, len);
		if (argv)
			wild_len = t_parser_wildcard(argv + argc[0], argument, arg_len);
		else
			wild_len = t_parser_wildcard(NULL, argument, arg_len);
		free(argument);
		if (wild_len < 0)
			return (-1);
		argc[0] += wild_len;
	}
	return (i);
}

int	t_parser_argvsplit_helper(char **argv, const char *str, int len)
{
	int		i;
	int		argc;
	int		argument_length;

	i = 0;
	argc = 0;
	while (!t_parser_eos(i, str, len))
	{
		while (!t_parser_eos(i, str, len) && ft_isspace(str[i]))
			i++;
		if (t_parser_eos(i, str, len))
			break ;
		argument_length = t_parser_argument(&argc, argv, str + i, len - i);
		if (argument_length < 0)
			return (-1);
		i += argument_length;
	}
	return (argc);
}

char	**t_parser_argvsplit(const char *str, int len)
{
	int		argc;
	char	**argv;

	argc = t_parser_argvsplit_helper(NULL, str, len);
	if (argc < 0)
		return (NULL);
	argv = malloc(sizeof(char *) * (argc + 1));
	if (!argv)
		return (NULL);
	if (t_parser_argvsplit_helper(argv, str, len) < 0)
	{
		argv[argc] = NULL;
		ft_strsfree(argv);
		return (NULL);
	}
	if (argv)
		argv[argc] = NULL;
	return (argv);
}
