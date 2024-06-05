/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_heredoc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:38:35 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_HEREDOC_H
# define T_HEREDOC_H

# define T_HEREDOC_IS_ENABLED	12634
# define T_HEREDOC_IS_DISABLED	12434
# define T_HEREDOC_ENABLE		64512
# define T_HEREDOC_DISABLE		74555

int		t_heredoc_deprecated(char *dest, int pos, char *str, int len);
void	t_heredoc_fini(char *str, int len);
int		t_heredoc_get_delimiter(char **delimiter, int pos,
			const char *str, int len);
int		t_heredoc_getfd(const char *str, int len);
char	*t_heredoc_init(char *str, int len);
int		t_heredoc_last(int pos, char *str, int len);
char	*t_heredoc_read(int *at, char *str, int len);
int		t_heredoc_mode(int req);
int		t_heredoc_redirect(int fd, const char *delimiter);
int		t_heredoc_setfd(char *dest, int herdoc_fd);
int		t_heredoc_should_expand(const char *str, int len);

#endif //!T_HEREDOC_H
