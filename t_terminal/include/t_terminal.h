/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_terminal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:40:24 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TERMINAL_H
# define T_TERMINAL_H

# include <termios.h>
# include <stddef.h>

# define T_TERMINAL_BUFFER_SIZE				1024
# define KEYCODE_ARROW_LEFT					9999
# define KEYCODE_ARROW_RIGHT				8888
# define KEYCODE_ARROW_UP					7777
# define KEYCODE_ARROW_DOWN					6666
# define KEYCODE_ENDL						'\n'
# define KEYCODE_DELETE						127
# define KEYCODE_CONTROL_L					12
# define T_TERMINAL_FAKE_INPUT				5741
# define T_TERMINAL_UNSET_FAKE_INPUT		8451
# define T_TERMINAL_IS_FAKE_INPUT			5625
# define KEYCODE_TAB						9
# define T_TERMINAL_READ_MODE_IS_ENABLED	-451245
# define T_TERMINAL_READ_MODE_ENABLE		-561645
# define T_TERMINAL_READ_MODE_DISABLE		-546455

typedef struct s_terminal
{
	int				fdin;
	int				fdout;
	int				fderr;
	char			*prompt;
	char			*buffer;
	int				length;
	int				prompt_len;
	int				size;
	int				column;
	char			bufferclear[10];
	struct termios	old_termios;
	struct termios	new_termios;
}	t_terminal;

int			t_terminal_bufferlen(void);
void		t_terminal_clearbuffer(void);
int			t_terminal_fini(void);
char		*t_terminal_getbuffer(void);
t_terminal	*t_terminal_init(char *prompt, int fdin, int fdout, int fderr);
int			t_terminal_inject(int nbytes);
int			t_terminal_insertchar(char c);
int			t_terminal_ldelete(int nbytes);
void		t_terminal_movecolumn(int by);
void		t_terminal_putbuffer(void);
void		t_terminal_putprompt(void);
int			t_terminal_rdelete(int nbytes);
int			t_terminal_input_request(char c, int req);
int			t_terminal_fakeinput(char c);
int			ft_read(int fildes, void *buf, size_t nbyte);
int			t_terminal_readcode(int fdin);
t_terminal	*t_terminal_readline_init(char *prompt);
int			t_terminal_readline_fini(void);
void		t_terminal_event(t_terminal *t, int keycode);
char		*t_terminal_readline(char *prompt);
t_terminal	*t_terminal_request(void);
void		t_terminal_resetline(void);
int			t_terminal_resizebuffer(int size);
int			t_terminal_setbuffer(const char *str);
void		t_terminal_setcolumn(int column);
int			t_terminal_setlength(int length);
void		t_terminal_setprompt(char *prompt);
int			t_terminal_getcol(int fdin);
void		t_terminal_drawbuffer(void);

#endif//!T_TERMINAL_H
