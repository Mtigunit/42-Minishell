/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 05:19:00 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef SUCCESS
#  define SUCCESS 0
# endif// !SUCCESS

# ifndef FAIL
#  define FAIL 1
# endif// !FAIL

# define MINISHELL_MODE_IGNORE_LINE	641
# define MINISHELL_MODE_RESET		528
# define MINISHELL_MODE_GET			512

int		is_an_isolated_operator(int pos, const char *str, int len, char *oper);
int		ft_getoperator(int pos, const char *str, int len);
char	*ft_readline(char *prompt);
int		minishell(int argc, char **argv, char **env);
int		minishell_configure(int argc, char **argv, char **env);
int		minishell_configure_environment(void);
void	minishell_configure_shell_level(int shlvl);
void	minishell_execline(char *line);
void	minishell_exit(void);
void	minishell_files_fini(char *str, int len);
char	*minishell_init_files(int error, char *str, int len);
char	*minishell_files_init(char *str, int len);
char	*minishell_init_input_files(int pos, char *str, int len);
char	*minishell_init_output_files(int error, int pos, char *str, int len);
int		minishell_mode(int req);
int		minishell_usage(int argc, char **argv);
int		t_deprecated_outfile(int pos, char *str, int len);
int		t_redirection_last(int pos, char *str, int len, char c);
int		t_redirection_setfd(char *dest, int herdoc_fd);

#endif //!MINISHELL_H
