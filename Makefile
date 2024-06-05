#  **************************************************************************  #
#                                                                              #
#                                                          :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 13:40:27 by ahabachi          #+#    #+#              #
#    Updated: 2023/03/15 23:41:43 by ahabachi         ###   ########.fr        #
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

CC									=	cc
CFLAGS								=	-Wall -Wextra -Werror
DONT_MAKE							=	1
REMOVE								=	rm -rf
#
MINILIBC_DIRECTORY					=	./minilibc
T_PARSER_DIRECTORY					=	./t_parser
T_BUILTINS_DIRECTORY				=	./t_builtins
T_EXECUTOR_DIRECTORY				=	./t_executor
T_MINISHELL_DIRECTORY				=	./t_minishell
T_PRECEDENCE_DIRECTORY				=	./t_precedence
T_TERMINAL_DIRECTORY				=	./t_terminal
T_ERRORHANDLER_DIRECTORY			=	./t_errorhandler
T_HEREDOC_DIRECTORY					=	./t_heredoc
T_SIGNALSHANDLER_DIRECTORY			=	./t_signalshandler
#
MINILIBC_INCLUDE_DIRECTORY			=	./minilibc/include
T_PARSER_INCLUDE_DIRECTORY			=	./t_parser/include
T_BUILTINS_INCLUDE_DIRECTORY		=	./t_builtins/include
T_EXECUTOR_INCLUDE_DIRECTORY		=	./t_executor/include
T_MINISHELL_INCLUDE_DIRECTORY		=	./t_minishell/include
T_PRECEDENCE_INCLUDE_DIRECTORY		=	./t_precedence/include
T_TERMINAL_INCLUDE_DIRECTORY		=	./t_terminal/include
T_ERRORHANDLER_INCLUDE_DIRECTORY	=	./t_errorhandler/include
T_HEREDOC_INCLUDE_DIRECTORY			=	./t_heredoc/include
T_SIGNALSHANDLER_INCLUDE_DIRECTORY	=	./t_signalshandler/include
#
MINILIBC_SOURCES_DIRECTORY			=	./minilibc/sources
T_PARSER_SOURCES_DIRECTORY			=	./t_parser/sources
T_BUILTINS_SOURCES_DIRECTORY		=	./t_builtins/sources
T_EXECUTOR_SOURCES_DIRECTORY		=	./t_executor/sources
T_MINISHELL_SOURCES_DIRECTORY		=	./t_minishell/sources
T_PRECEDENCE_SOURCES_DIRECTORY		=	./t_precedence/sources
T_TERMINAL_SOURCES_DIRECTORY		=	./t_terminal/sources
T_ERRORHANDLER_SOURCES_DIRECTORY	=	./t_errorhandler/sources
T_HEREDOC_SOURCES_DIRECTORY			=	./t_heredoc/sources
T_SIGNALSHANDLER_SOURCES_DIRECTORY	=	./t_signalshandler/sources
#
include minilibc/Makefile
include t_builtins/Makefile
include t_executor/Makefile
include t_minishell/Makefile
include t_precedence/Makefile
include t_terminal/Makefile
include t_errorhandler/Makefile
include t_heredoc/Makefile
include t_parser/Makefile
include t_signalshandler/Makefile
#
INCLUDE	=	-I$(T_MINISHELL_INCLUDE_DIRECTORY)
SOURCES	=	main.c
OBJECTS	=	$(SOURCES:.c=.o)
HEADERS	=	$(T_MINISHELL_INCLUDE_DIRECTORY)/minishell.h
#
NAME	=	minishell
objects	=	$(OBJECTS) $(T_BUILTINS_OBJECTS) $(MINILIBC_OBJECTS) $(T_EXECUTOR_OBJECTS) $(T_MINISHELL_OBJECTS) $(T_PRECEDENCE_OBJECTS) $(T_TERMINAL_OBJECTS) $(T_ERRORHANDLER_OBJECTS)$(T_HEREDOC_OBJECTS) $(T_PARSER_OBJECTS) $(T_SIGNALSHANDLER_OBJECTS)

$(NAME): $(objects)
	${CC} $(CFLAGS) -o $(NAME) $(objects)

%.o: %.c $(HEADERS)
	${CC} ${FLAGS} $(INCLUDE) -c $< -o ${<:.c=.o}

all: $(NAME)

run: $(NAME)
	@clear
	@./$(NAME)

clean:
	@make -C $(MINILIBC_DIRECTORY) clean
	@make -C $(T_BUILTINS_DIRECTORY) clean
	@make -C $(T_EXECUTOR_DIRECTORY) clean
	@make -C $(T_MINISHELL_DIRECTORY) clean
	@make -C $(T_PRECEDENCE_DIRECTORY) clean
	@make -C $(T_TERMINAL_DIRECTORY) clean
	@make -C $(T_ERRORHANDLER_DIRECTORY) clean
	@make -C $(T_HEREDOC_DIRECTORY) clean
	@make -C $(T_PARSER_DIRECTORY) clean
	@make -C $(T_SIGNALSHANDLER_DIRECTORY) clean
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) minishell

bonus: all
b: bonus

mandatory: all

mand: mandatory

m: mandatory

re: fclean all

norm:
	@norminette

n: norm

push:
	@git add .
	@git commit -m "committed on '`date`' by '`whoami`', hostname = '`hostname`'"
	@git push

# leaks:
# 	

# install:
