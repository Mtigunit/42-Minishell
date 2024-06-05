#  **************************************************************************  #
#                                                                              #
#                                                          :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 13:13:20 by ahabachi          #+#    #+#              #
#    Updated: 2023/03/15 23:07:41 by ahabachi         ###   ########.fr        #
#                                                                              #
#  **************************************************************************  #
#                                                                              #
#   █████████            ██████████         ██████████         ██████████      #
#   ██     ██                    ██                 ██         ██      ██      #
#          ██                    ██                 ██         ██      ██      #
#          ██                    ██                 ██                 ██      #
#          ██            ██████████         ██████████                 ██      #
#          ██                    ██                 ██                 ██      #
#          ██                    ██                 ██                 ██      #
#          ██                    ██                 ██                 ██      #
#       ████████         ██████████         ██████████                 ██      #
#                                                                              #
#  **************************************************************************  #

ifndef T_TERMINAL_MAKEFILE

T_TERMINAL_MAKEFILE	=	1

ifndef T_TERMINAL_DIRECTORY
T_TERMINAL_DIRECTORY	=	.
endif#!T_TERMINAL_DIRECTORY

T_TERMINAL_SOURCES_DIRECTORY	=	$(T_TERMINAL_DIRECTORY)/sources
T_TERMINAL_OBJECTS_DIRECTORY	=	$(T_TERMINAL_DIRECTORY)/objects
T_TERMINAL_INCLUDE_DIRECTORY	=	$(T_TERMINAL_DIRECTORY)/include

ifndef MINILIBC_INCLUDE_DIRECTORY
MINILIBC_INCLUDE_DIRECTORY	=	../minilibc/include/
endif #!MINILIBC_INCLUDE_DIRECTORY

ifndef T_SIGNALSHANDLER_INCLUDE_DIRECTORY
T_SIGNALSHANDLER_INCLUDE_DIRECTORY	=	../t_signalshandler/include/
endif #!T_SIGNALSHANDLER_INCLUDE_DIRECTORY

ifndef T_MINISHELL_INCLUDE_DIRECTORY
T_MINISHELL_INCLUDE_DIRECTORY	=	../t_minishell/include/
endif #!T_MINISHELL_INCLUDE_DIRECTORY

T_TERMINAL_SOURCES	=	\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_bufferlen.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_clearbuffer.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_drawbuffer.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_fini.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_getbuffer.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_history.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_init.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_inject.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_insertchar.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_ldelete.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_movecolumn.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_putbuffer.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_putprompt.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_rdelete.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_readcode.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_readline.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_readline_fini.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_readline_init.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_request.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_resetline.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_resizebuffer.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_setbuffer.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_setcolumn.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_setlength.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_setprompt.c\
	$(T_TERMINAL_SOURCES_DIRECTORY)/t_terminal_utils.c


T_TERMINAL_OBJECTS	=	$(subst .c,.o, $(subst $(T_TERMINAL_SOURCES_DIRECTORY), $(T_TERMINAL_OBJECTS_DIRECTORY), $(T_TERMINAL_SOURCES)))
T_TERMINAL_HEADERS	=	$(T_TERMINAL_INCLUDE_DIRECTORY)/t_terminal.h\
						$(T_SIGNALSHANDLER_INCLUDE_DIRECTORY)/t_signalshandler.h\
						$(MINILIBC_INCLUDE_DIRECTORY)/minilibc.h\
						$(T_MINISHELL_INCLUDE_DIRECTORY)/minishell.h
T_TERMINAL_INCLUDE	=	-I$(T_TERMINAL_INCLUDE_DIRECTORY)\
						-I$(T_SIGNALSHANDLER_INCLUDE_DIRECTORY)\
						-I$(MINILIBC_INCLUDE_DIRECTORY)\
						-I$(T_MINISHELL_INCLUDE_DIRECTORY)
						
ifndef CFLAGS
CFLAGS				=	-Wall -Wextra -Werror
endif # !CFLAGS

$(T_TERMINAL_OBJECTS_DIRECTORY)/%.o: $(T_TERMINAL_SOURCES_DIRECTORY)/%.c $(T_TERMINAL_HEADERS)
	@mkdir -p $(T_TERMINAL_OBJECTS_DIRECTORY)
	cc $(CFLAGS) $(T_TERMINAL_INCLUDE) -c $< -o $@

ifndef DONT_MAKE

NAME	=	objects

$(NAME): $(T_TERMINAL_HEADERS) $(T_TERMINAL_OBJECTS)

all: $(NAME)

clean:
	rm -rf $(T_TERMINAL_OBJECTS_DIRECTORY)

fclean: clean

re: fclean all

endif # !DONT_MAKE

endif # !T_TERMINAL_MAKEFILE
