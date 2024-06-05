#  **************************************************************************  #
#                                                                              #
#                                                          :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 13:38:58 by ahabachi          #+#    #+#              #
#    Updated: 2023/03/15 22:52:13 by ahabachi         ###   ########.fr        #
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

ifndef T_BUILTINS_MAKEFILE

T_BUILTINS_MAKEFILE	=	1

ifndef T_BUILTINS_DIRECTORY
T_BUILTINS_DIRECTORY	=	.
endif #!T_BUILTINS_DIRECTORY
#
ifndef MINILIBC_INCLUDE_DIRECTORY
MINILIBC_INCLUDE_DIRECTORY			=	../minilibc/include/
endif #!MINILIBC_INCLUDE_DIRECTORY
#
ifndef T_ERRORHANDLER_INCLUDE_DIRECTORY
T_ERRORHANDLER_INCLUDE_DIRECTORY	=	../t_errorhandler/include/
endif #!T_ERRORHANDLER_INCLUDE_DIRECTORY
#
T_BUILTINS_SOURCES_DIRECTORY	=	$(T_BUILTINS_DIRECTORY)/sources
T_BUILTINS_OBJECTS_DIRECTORY	=	$(T_BUILTINS_DIRECTORY)/objects
T_BUILTINS_INCLUDE_DIRECTORY	=	$(T_BUILTINS_DIRECTORY)/include
#
T_BUILTINS_SOURCES	=	\
	$(T_BUILTINS_SOURCES_DIRECTORY)/t_builtins_cd.c\
	$(T_BUILTINS_SOURCES_DIRECTORY)/t_builtins_echo.c\
	$(T_BUILTINS_SOURCES_DIRECTORY)/t_builtins_env.c\
	$(T_BUILTINS_SOURCES_DIRECTORY)/t_builtins_execute.c\
	$(T_BUILTINS_SOURCES_DIRECTORY)/t_builtins_exit.c\
	$(T_BUILTINS_SOURCES_DIRECTORY)/t_builtins_export.c\
	$(T_BUILTINS_SOURCES_DIRECTORY)/t_builtins_pwd.c\
	$(T_BUILTINS_SOURCES_DIRECTORY)/t_builtins_unset.c

T_BUILTINS_OBJECTS	=	$(subst .c,.o, $(subst $(T_BUILTINS_SOURCES_DIRECTORY), $(T_BUILTINS_OBJECTS_DIRECTORY), $(T_BUILTINS_SOURCES)))
T_BUILTINS_HEADERS	=	$(T_BUILTINS_INCLUDE_DIRECTORY)/t_builtins.h\
						$(T_ERRORHANDLER_INCLUDE_DIRECTORY)/t_errorhandler.h\
						$(MINILIBC_INCLUDE_DIRECTORY)/minilibc.h

T_BUILTINS_INCLUDE	=	-I$(T_BUILTINS_INCLUDE_DIRECTORY)\
						-I$(MINILIBC_INCLUDE_DIRECTORY)\
						-I$(T_ERRORHANDLER_INCLUDE_DIRECTORY)

ifndef CFLAGS
CFLAGS				=	-Wall -Wextra -Werror
endif # !CFLAGS

$(T_BUILTINS_OBJECTS_DIRECTORY)/%.o: $(T_BUILTINS_SOURCES_DIRECTORY)/%.c $(T_BUILTINS_HEADERS)
	@mkdir -p $(T_BUILTINS_OBJECTS_DIRECTORY)
	cc $(CFLAGS) $(T_BUILTINS_INCLUDE) -c $< -o $@

ifndef DONT_MAKE

NAME	=	objects

$(NAME): $(T_BUILTINS_HEADERS) $(T_BUILTINS_OBJECTS)

all: $(NAME)

clean:
	rm -rf $(T_BUILTINS_OBJECTS_DIRECTORY)

fclean: clean

re: fclean all

endif # !DONT_MAKE

endif # !T_BUILTINS_MAKEFILE
