#  **************************************************************************  #
#                                                                              #
#                                                          :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 01:19:12 by ahabachi          #+#    #+#              #
#    Updated: 2023/03/15 22:57:19 by ahabachi         ###   ########.fr        #
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

ifndef T_EXECUTOR_MAKEFILE

T_EXECUTOR_MAKEFILE	=	1

ifndef T_EXECUTOR_DIRECTORY
T_EXECUTOR_DIRECTORY	=	.
endif

ifndef T_BUILTINS_INCLUDE_DIRECTORY
T_BUILTINS_INCLUDE_DIRECTORY		=	../t_builtins/include/
endif #!T_BUILTINS_INCLUDE_DIRECTORY

ifndef T_PRECEDENCE_INCLUDE_DIRECTORY
T_PRECEDENCE_INCLUDE_DIRECTORY		=	../t_precedence/include/
endif #!T_PRECEDENCE_INCLUDE_DIRECTORY

ifndef T_ERRORHANDLER_INCLUDE_DIRECTORY
T_ERRORHANDLER_INCLUDE_DIRECTORY	=	../t_errorhandler/include/
endif #!T_ERRORHANDLER_INCLUDE_DIRECTORY

ifndef MINILIBC_INCLUDE_DIRECTORY
MINILIBC_INCLUDE_DIRECTORY			=	../minilibc/include/
endif #!MINILIBC_INCLUDE_DIRECTORY

ifndef T_PARSER_INCLUDE_DIRECTORY
T_PARSER_INCLUDE_DIRECTORY			=	../t_parser/include/
endif #!T_PARSER_INCLUDE_DIRECTORY

ifndef T_SIGNALSHANDLER_INCLUDE_DIRECTORY
T_SIGNALSHANDLER_INCLUDE_DIRECTORY	=	../t_signalshandler/include/
endif #!T_SIGNALSHANDLER_INCLUDE_DIRECTORY

ifndef T_HEREDOC_INCLUDE_DIRECTORY
T_HEREDOC_INCLUDE_DIRECTORY			=	../t_heredoc/include/
endif #!T_HEREDOC_INCLUDE_DIRECTORY

T_EXECUTOR_SOURCES_DIRECTORY	=	$(T_EXECUTOR_DIRECTORY)/sources
T_EXECUTOR_OBJECTS_DIRECTORY	=	$(T_EXECUTOR_DIRECTORY)/objects
T_EXECUTOR_INCLUDE_DIRECTORY	=	$(T_EXECUTOR_DIRECTORY)/include

T_EXECUTOR_SOURCES	=	\
	$(T_EXECUTOR_SOURCES_DIRECTORY)/t_executor_append_output.c\
	$(T_EXECUTOR_SOURCES_DIRECTORY)/t_executor_exec.c\
	$(T_EXECUTOR_SOURCES_DIRECTORY)/t_executor_execone.c\
	$(T_EXECUTOR_SOURCES_DIRECTORY)/t_executor_here_document.c\
	$(T_EXECUTOR_SOURCES_DIRECTORY)/t_executor_joinargs.c\
	$(T_EXECUTOR_SOURCES_DIRECTORY)/t_executor_logical_and.c\
	$(T_EXECUTOR_SOURCES_DIRECTORY)/t_executor_logical_or.c\
	$(T_EXECUTOR_SOURCES_DIRECTORY)/t_executor_pipe.c\
	$(T_EXECUTOR_SOURCES_DIRECTORY)/t_executor_redirect_input.c\
	$(T_EXECUTOR_SOURCES_DIRECTORY)/t_executor_redirect_output.c\
	$(T_EXECUTOR_SOURCES_DIRECTORY)/t_executor_redirections_getfd.c\
	$(T_EXECUTOR_SOURCES_DIRECTORY)/t_executor_skip_blanks.c


T_EXECUTOR_OBJECTS	=	$(subst .c,.o, $(subst $(T_EXECUTOR_SOURCES_DIRECTORY), $(T_EXECUTOR_OBJECTS_DIRECTORY), $(T_EXECUTOR_SOURCES)))
T_EXECUTOR_HEADERS	=	$(T_EXECUTOR_INCLUDE_DIRECTORY)/t_executor.h\
						$(T_ERRORHANDLER_INCLUDE_DIRECTORY)/t_errorhandler.h\
						$(T_HEREDOC_INCLUDE_DIRECTORY)/t_heredoc.h\
						$(T_PRECEDENCE_INCLUDE_DIRECTORY)/t_precedence.h\
						$(T_PARSER_INCLUDE_DIRECTORY)/t_parser.h\
						$(T_BUILTINS_INCLUDE_DIRECTORY)/t_builtins.h\
						$(MINILIBC_INCLUDE_DIRECTORY)/minilibc.h\
						$(T_SIGNALSHANDLER_INCLUDE_DIRECTORY)/t_signalshandler.h

T_EXECUTOR_INCLUDE	=	-I$(T_EXECUTOR_INCLUDE_DIRECTORY)\
						-I$(T_ERRORHANDLER_INCLUDE_DIRECTORY)\
						-I$(T_HEREDOC_INCLUDE_DIRECTORY)\
						-I$(T_PRECEDENCE_INCLUDE_DIRECTORY)\
						-I$(T_PARSER_INCLUDE_DIRECTORY)\
						-I$(T_BUILTINS_INCLUDE_DIRECTORY)\
						-I$(MINILIBC_INCLUDE_DIRECTORY)\
						-I$(T_SIGNALSHANDLER_INCLUDE_DIRECTORY)

ifndef CFLAGS
CFLAGS				=	-Wall -Wextra -Werror
endif # !CFLAGS

$(T_EXECUTOR_OBJECTS_DIRECTORY)/%.o: $(T_EXECUTOR_SOURCES_DIRECTORY)/%.c $(T_EXECUTOR_HEADERS)
	@mkdir -p $(T_EXECUTOR_OBJECTS_DIRECTORY)
	cc $(CFLAGS) $(T_EXECUTOR_INCLUDE) -c $< -o $@

ifndef DONT_MAKE

NAME	=	objects

$(NAME): $(T_EXECUTOR_HEADERS) $(T_EXECUTOR_OBJECTS)

all: $(NAME)

clean:
	rm -rf $(T_EXECUTOR_OBJECTS_DIRECTORY)

fclean: clean

re: fclean all

endif # !DONT_MAKE

endif # !T_EXECUTOR_MAKEFILE
