#  **************************************************************************  #
#                                                                              #
#                                                          :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 13:30:44 by ahabachi          #+#    #+#              #
#    Updated: 2023/03/15 23:00:07 by ahabachi         ###   ########.fr        #
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

ifndef T_HEREDOC_MAKEFILE

T_HEREDOC_MAKEFILE	=	1

ifndef T_HEREDOC_DIRECTORY
T_HEREDOC_DIRECTORY	=	.
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
T_HEREDOC_SOURCES_DIRECTORY	=	$(T_HEREDOC_DIRECTORY)/sources
T_HEREDOC_OBJECTS_DIRECTORY	=	$(T_HEREDOC_DIRECTORY)/objects
T_HEREDOC_INCLUDE_DIRECTORY	=	$(T_HEREDOC_DIRECTORY)/include

T_HEREDOC_SOURCES	=	\
	$(T_HEREDOC_SOURCES_DIRECTORY)/t_heredoc_deprecated.c\
	$(T_HEREDOC_SOURCES_DIRECTORY)/t_heredoc_fini.c\
	$(T_HEREDOC_SOURCES_DIRECTORY)/t_heredoc_get_delimiter.c\
	$(T_HEREDOC_SOURCES_DIRECTORY)/t_heredoc_getfd.c\
	$(T_HEREDOC_SOURCES_DIRECTORY)/t_heredoc_init.c\
	$(T_HEREDOC_SOURCES_DIRECTORY)/t_heredoc_last.c\
	$(T_HEREDOC_SOURCES_DIRECTORY)/t_heredoc_read.c\
	$(T_HEREDOC_SOURCES_DIRECTORY)/t_heredoc_redirect.c\
	$(T_HEREDOC_SOURCES_DIRECTORY)/t_heredoc_setfd.c\
	$(T_HEREDOC_SOURCES_DIRECTORY)/t_heredoc_should_expand.c


T_HEREDOC_OBJECTS	=	$(subst .c,.o, $(subst $(T_HEREDOC_SOURCES_DIRECTORY), $(T_HEREDOC_OBJECTS_DIRECTORY), $(T_HEREDOC_SOURCES)))
T_HEREDOC_HEADERS	=	$(T_HEREDOC_INCLUDE_DIRECTORY)/t_heredoc.h\
						$(T_ERRORHANDLER_INCLUDE_DIRECTORY)/t_errorhandler.h\
						$(T_MINISHELL_INCLUDE_DIRECTORY)/minishell.h\
						$(MINILIBC_INCLUDE_DIRECTORY)/minilibc.h\
						$(T_PARSER_INCLUDE_DIRECTORY)/t_parser.h
T_HEREDOC_INCLUDE	=	-I$(T_HEREDOC_INCLUDE_DIRECTORY)\
						-I$(T_ERRORHANDLER_INCLUDE_DIRECTORY)\
						-I$(T_MINISHELL_INCLUDE_DIRECTORY)\
						-I$(MINILIBC_INCLUDE_DIRECTORY)\
						-I$(T_PARSER_INCLUDE_DIRECTORY)

ifndef CFLAGS
CFLAGS				=	-Wall -Wextra -Werror
endif # !CFLAGS

$(T_HEREDOC_OBJECTS_DIRECTORY)/%.o: $(T_HEREDOC_SOURCES_DIRECTORY)/%.c $(T_HEREDOC_HEADERS)
	@mkdir -p $(T_HEREDOC_OBJECTS_DIRECTORY)
	cc $(CFLAGS) $(T_HEREDOC_INCLUDE) -c $< -o $@

ifndef DONT_MAKE

NAME	=	objects

$(NAME): $(T_HEREDOC_HEADERS) $(T_HEREDOC_OBJECTS)

all: $(NAME)

clean:
	rm -rf $(T_HEREDOC_OBJECTS_DIRECTORY)

fclean: clean

re: fclean all

endif # !DONT_MAKE

endif # !T_HEREDOC_MAKEFILE
