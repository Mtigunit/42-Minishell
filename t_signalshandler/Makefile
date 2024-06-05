#  **************************************************************************  #
#                                                                              #
#                                                          :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 13:08:42 by ahabachi          #+#    #+#              #
#    Updated: 2023/03/15 23:05:49 by ahabachi         ###   ########.fr        #
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

ifndef T_SIGNALSHANDLER_MAKEFILE

T_SIGNALSHANDLER_MAKEFILE	=	1

ifndef T_SIGNALSHANDLER_DIRECTORY
T_SIGNALSHANDLER_DIRECTORY	=	.
endif
#
ifndef MINILIBC_INCLUDE_DIRECTORY
MINILIBC_INCLUDE_DIRECTORY			=	../minilibc/include
endif  #!MINILIBC_INCLUDE_DIRECTORY
#
ifndef T_PARSER_INCLUDE_DIRECTORY
T_PARSER_INCLUDE_DIRECTORY			=	../t_parser/include
endif  #!T_PARSER_INCLUDE_DIRECTORY
#
ifndef T_BUILTINS_INCLUDE_DIRECTORY
T_BUILTINS_INCLUDE_DIRECTORY		=	../t_builtins/include
endif  #!T_BUILTINS_INCLUDE_DIRECTORY
#
ifndef T_EXECUTOR_INCLUDE_DIRECTORY
T_EXECUTOR_INCLUDE_DIRECTORY		=	../t_executor/include
endif  #!T_EXECUTOR_INCLUDE_DIRECTORY
#
ifndef T_MINISHELL_INCLUDE_DIRECTORY
T_MINISHELL_INCLUDE_DIRECTORY		=	../t_minishell/include
endif  #!T_MINISHELL_INCLUDE_DIRECTORY
#
ifndef T_PRECEDENCE_INCLUDE_DIRECTORY
T_PRECEDENCE_INCLUDE_DIRECTORY		=	../t_precedence/include
endif  #!T_PRECEDENCE_INCLUDE_DIRECTORY
#
ifndef T_TERMINAL_INCLUDE_DIRECTORY
T_TERMINAL_INCLUDE_DIRECTORY		=	../t_terminal/include
endif  #!T_TERMINAL_INCLUDE_DIRECTORY
#
ifndef T_ERRORHANDLER_INCLUDE_DIRECTORY
T_ERRORHANDLER_INCLUDE_DIRECTORY	=	../t_errorhandler/include
endif  #!T_ERRORHANDLER_INCLUDE_DIRECTORY
#
ifndef T_HEREDOC_INCLUDE_DIRECTORY
T_HEREDOC_INCLUDE_DIRECTORY			=	../t_heredoc/include
endif  #!T_HEREDOC_INCLUDE_DIRECTORY
#
ifndef T_SIGNALSHANDLER_INCLUDE_DIRECTORY
T_SIGNALSHANDLER_INCLUDE_DIRECTORY	=	../t_signalshandler/include
endif  #!T_SIGNALSHANDLER_INCLUDE_DIRECTORY
#
T_SIGNALSHANDLER_SOURCES_DIRECTORY	=	$(T_SIGNALSHANDLER_DIRECTORY)/sources
T_SIGNALSHANDLER_OBJECTS_DIRECTORY	=	$(T_SIGNALSHANDLER_DIRECTORY)/objects
T_SIGNALSHANDLER_INCLUDE_DIRECTORY	=	$(T_SIGNALSHANDLER_DIRECTORY)/include

T_SIGNALSHANDLER_SOURCES	=	\
							$(T_SIGNALSHANDLER_SOURCES_DIRECTORY)/t_signalshandler.c


T_SIGNALSHANDLER_OBJECTS	=	$(subst .c,.o, $(subst $(T_SIGNALSHANDLER_SOURCES_DIRECTORY), $(T_SIGNALSHANDLER_OBJECTS_DIRECTORY), $(T_SIGNALSHANDLER_SOURCES)))

T_SIGNALSHANDLER_HEADERS	=	$(T_SIGNALSHANDLER_INCLUDE_DIRECTORY)/t_signalshandler.h\
								$(MINILIBC_INCLUDE_DIRECTORY)/minilibc.h\
								$(T_TERMINAL_INCLUDE_DIRECTORY)/t_terminal.h\
								$(T_HEREDOC_INCLUDE_DIRECTORY)/t_heredoc.h\
								$(T_MINISHELL_INCLUDE_DIRECTORY)/minishell.h

T_SIGNALSHANDLER_INCLUDE	=	-I$(T_SIGNALSHANDLER_INCLUDE_DIRECTORY)\
								-I$(MINILIBC_INCLUDE_DIRECTORY)\
								-I$(T_TERMINAL_INCLUDE_DIRECTORY)\
								-I$(T_HEREDOC_INCLUDE_DIRECTORY)\
								-I$(T_MINISHELL_INCLUDE_DIRECTORY)

ifndef CFLAGS
CFLAGS				=	-Wall -Wextra -Werror
endif # !CFLAGS

$(T_SIGNALSHANDLER_OBJECTS_DIRECTORY)/%.o: $(T_SIGNALSHANDLER_SOURCES_DIRECTORY)/%.c $(T_SIGNALSHANDLER_HEADERS)
	@mkdir -p $(T_SIGNALSHANDLER_OBJECTS_DIRECTORY)
	cc $(CFLAGS) $(T_SIGNALSHANDLER_INCLUDE) -c $< -o $@

ifndef DONT_MAKE

NAME	=	objects

$(NAME): $(T_SIGNALSHANDLER_HEADERS) $(T_SIGNALSHANDLER_OBJECTS)

all: $(NAME)

clean:
	rm -rf $(T_SIGNALSHANDLER_OBJECTS_DIRECTORY)

fclean: clean

re: fclean all

endif # !DONT_MAKE

endif # !T_SIGNALSHANDLER_MAKEFILE
