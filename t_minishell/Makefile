#  **************************************************************************  #
#                                                                              #
#                                                          :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 05:07:06 by ahabachi          #+#    #+#              #
#    Updated: 2023/03/15 23:01:57 by ahabachi         ###   ########.fr        #
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

ifndef T_MINISHELL_MAKEFILE

T_MINISHELL_MAKEFILE	=	1

ifndef T_MINISHELL_DIRECTORY
T_MINISHELL_DIRECTORY	=	.
endif #!T_MINISHELL_DIRECTORY
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
T_MINISHELL_SOURCES_DIRECTORY	=	$(T_MINISHELL_DIRECTORY)/sources
T_MINISHELL_OBJECTS_DIRECTORY	=	$(T_MINISHELL_DIRECTORY)/objects
T_MINISHELL_INCLUDE_DIRECTORY	=	$(T_MINISHELL_DIRECTORY)/include

T_MINISHELL_SOURCES	=	\
	$(T_MINISHELL_SOURCES_DIRECTORY)/ft_getoperator.c\
	$(T_MINISHELL_SOURCES_DIRECTORY)/ft_readline.c\
	$(T_MINISHELL_SOURCES_DIRECTORY)/minishell.c\
	$(T_MINISHELL_SOURCES_DIRECTORY)/minishell_configure.c\
	$(T_MINISHELL_SOURCES_DIRECTORY)/minishell_configure_environment.c\
	$(T_MINISHELL_SOURCES_DIRECTORY)/minishell_configure_shell_level.c\
	$(T_MINISHELL_SOURCES_DIRECTORY)/minishell_execline.c\
	$(T_MINISHELL_SOURCES_DIRECTORY)/minishell_exit.c\
	$(T_MINISHELL_SOURCES_DIRECTORY)/minishell_files_fini.c\
	$(T_MINISHELL_SOURCES_DIRECTORY)/minishell_files_init.c\
	$(T_MINISHELL_SOURCES_DIRECTORY)/minishell_init_input_files.c\
	$(T_MINISHELL_SOURCES_DIRECTORY)/minishell_init_output_files.c\
	$(T_MINISHELL_SOURCES_DIRECTORY)/minishell_mode.c\
	$(T_MINISHELL_SOURCES_DIRECTORY)/minishell_usage.c\
	$(T_MINISHELL_SOURCES_DIRECTORY)/t_deprecated_outfile.c\
	$(T_MINISHELL_SOURCES_DIRECTORY)/t_redirection_last.c\
	$(T_MINISHELL_SOURCES_DIRECTORY)/t_redirection_setfd.c


T_MINISHELL_OBJECTS	=	$(subst .c,.o, $(subst $(T_MINISHELL_SOURCES_DIRECTORY), $(T_MINISHELL_OBJECTS_DIRECTORY), $(T_MINISHELL_SOURCES)))

T_MINISHELL_HEADERS	=	$(T_MINISHELL_INCLUDE_DIRECTORY)/minishell.h\
						$(T_TERMINAL_INCLUDE_DIRECTORY)/t_terminal.h\
						$(T_PRECEDENCE_INCLUDE_DIRECTORY)/t_precedence.h\
						$(T_PARSER_INCLUDE_DIRECTORY)/t_parser.h\
						$(T_ERRORHANDLER_INCLUDE_DIRECTORY)/t_errorhandler.h\
						$(T_EXECUTOR_INCLUDE_DIRECTORY)/t_executor.h\
						$(T_HEREDOC_INCLUDE_DIRECTORY)/t_heredoc.h\
						$(T_SIGNALSHANDLER_INCLUDE_DIRECTORY)/t_signalshandler.h\
						$(MINILIBC_INCLUDE_DIRECTORY)/minilibc.h

T_MINISHELL_INCLUDE	=	-I$(T_MINISHELL_INCLUDE_DIRECTORY)\
						-I$(T_TERMINAL_INCLUDE_DIRECTORY)\
						-I$(T_PRECEDENCE_INCLUDE_DIRECTORY)\
						-I$(T_PARSER_INCLUDE_DIRECTORY)\
						-I$(T_ERRORHANDLER_INCLUDE_DIRECTORY)\
						-I$(T_EXECUTOR_INCLUDE_DIRECTORY)\
						-I$(T_HEREDOC_INCLUDE_DIRECTORY)\
						-I$(T_SIGNALSHANDLER_INCLUDE_DIRECTORY)\
						-I$(MINILIBC_INCLUDE_DIRECTORY)

ifndef CFLAGS
CFLAGS				=	-Wall -Wextra -Werror
endif # !CFLAGS

$(T_MINISHELL_OBJECTS_DIRECTORY)/%.o: $(T_MINISHELL_SOURCES_DIRECTORY)/%.c $(T_MINISHELL_HEADERS)
	@mkdir -p $(T_MINISHELL_OBJECTS_DIRECTORY)
	cc $(CFLAGS) $(T_MINISHELL_INCLUDE) -c $< -o $@

ifndef DONT_MAKE

NAME	=	objects

$(NAME): $(T_MINISHELL_HEADERS) $(T_MINISHELL_OBJECTS)

all: $(NAME)

clean:
	rm -rf $(T_MINISHELL_OBJECTS_DIRECTORY)

fclean: clean

re: fclean all

endif # !DONT_MAKE

endif # !T_MINISHELL_MAKEFILE
