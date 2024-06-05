/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_precedence.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:46:56 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PRECEDENCE_H

# define T_PRECEDENCE_H

typedef struct s_precedence
{
	int		pos;
	char	*str;
	int		len;

	int		operation;

	int		left_len;
	char	*left;

	int		right_len;
	char	*right;

}	t_precedence;

# define T_OPERATOR_PIPE				1
# define T_OPERATOR_OR					2
# define T_OPERATOR_AND					4
# define T_PRENTHESIS					8
# define T_OPERATOR_REDIRECT_OUTPUT		16
# define T_OPERATOR_REDIRECT_INPUT		32
# define T_OPERATOR_APPEND_REDIRECTION	64
# define T_OPERATOR_HERE_DOCUMENT		128
# define T_OPERATOR_UNKNOWN				256

int		t_precedence_operation(t_precedence *p,
			int operation, int (*prev)(t_precedence *p));
int		t_precedence_parse(t_precedence *p);
int		t_precedence_parse_parenthesis(t_precedence *p);
int		t_precedence_parse_pipe(t_precedence *p);
int		t_precedence_redirections(t_precedence *p);
char	ft_peek(t_precedence *p, int at);
void	ft_move(t_precedence *p, int by);
void	t_precedence_skip_spaces(t_precedence *p);
void	h_precedence_copy(t_precedence *dest, t_precedence *src);
int		ft_operator_len(int oper);

#endif // !T_PRECEDENCE_H
