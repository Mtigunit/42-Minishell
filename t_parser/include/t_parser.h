/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:42:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PARSER_H
# define T_PARSER_H

# include <dirent.h>

typedef struct s_wildcard
{
	int				argc;
	char			**argv;
	char			*dirname;
	int				last_slash;
	struct dirent	*e;
}	t_wildcard;

# define CHAR_FAKE_STAR			-20
# define CHAR_FAKE_DOLLAR_SIGN	-21

char	*t_parser_argclear(char *src, int len);
int		t_parser_weak_string(int *pos, char *dest, const char *src, int len);
int		t_parser_strong_string(int *pos, char *dest, const char *src, int len);
int		t_parser_arg(int *pos, char *dest, const char *src, int len);
int		t_parser_argcpy(int *arglen, char *dest, const char *src, int len);
int		t_parser_argend(char c);
int		t_parser_argexp(char *dest, const char *src, int len);
int		t_parser_eos(int pos, const char *str, int len);
int		t_parser_argument(int *argc, char **argv, const char *str, int len);
int		t_parser_argvsplit_helper(char **argv, const char *str, int len);
char	**t_parser_argvsplit(const char *str, int len);
int		t_isoperator(char c);
int		t_parser_string(int i, char *dest, const char *src, int len);
int		t_parser_cmdcpy(char *dest, const char *src, int len);
int		t_parser_skip_spaces(int pos, const char *str, int len);
int		t_parser_skip_string(int pos, char *str, int len);
char	*t_parser_trim(char *str, int *len);
int		t_expand_isenabled(void);
void	t_expand_enable(void);
void	t_expand_disable(void);
void	t_parser_append_char(int at, char *dest, char c);
int		t_wildcard_ignore(const char *name, char *dr, const char *schema,
			int slen);
int		t_wildcard_readdir(t_wildcard *p, char *basename, int b_len,
			int maxlen);
int		t_wildcard_prepare(char **dest, const char *src, int len);
int		t_parser_wildcard(char **argv, const char *src, int len);
int		t_parser_wildcard_clear(char **argv);
int		t_wildcard_valid_entry(t_wildcard *p, t_wildcard *q, char *base,
			int b_len);
int		t_wildcard_appenddir(t_wildcard *p, char *base, int b_len, int maxlen);
int		t_wildcard_hlp1(t_wildcard *p, int pos, const char *src, int len);
int		t_wildcard_hlp(char **argv, const char *src, int len);

#endif //!T_PARSER_H
