/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_executor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 04:28:16 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_EXECUTOR_H
# define T_EXECUTOR_H

# include "t_precedence.h"

int		t_executor_append_output(char *left, char *right, int llen, int rlen);
int		t_precedence_init(t_precedence *p, char *str, int len);
int		t_executor_exec(char *command, int command_len);
int		t_executor_execone(char *cmd, int cmd_len);
int		t_executor_here_document(char *left, char *right, int llen, int rlen);
char	*t_executor_joinargs(char *left, char *right, int llen, int rlen);
int		t_executor_logical_and(char *left, char *right, int llen, int rlen);
int		t_executor_logical_or(char *left, char *right, int llen, int rlen);
int		t_executor_pipe(char *left, char *right, int left_len, int right_len);
int		t_executor_redirect_input(char *left, char *right, int llen, int rlen);
int		t_executor_redirect_output(char *left, char *right, int llen, int rlen);
int		t_executor_redirections_getfd(const char *str, int len);
int		t_executor_skip_blanks(int pos, const char *str, int len);

#endif //!T_EXECUTOR_H