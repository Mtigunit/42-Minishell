#  **************************************************************************  #
#                                                                              #
#                                                          :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 13:37:55 by ahabachi          #+#    #+#              #
#    Updated: 2023/03/15 22:54:15 by ahabachi         ###   ########.fr        #
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

ifndef T_ERRORHANDLER_MAKEFILE

T_ERRORHANDLER_MAKEFILE	=	1

ifndef T_ERRORHANDLER_DIRECTORY
T_ERRORHANDLER_DIRECTORY	=	.
endif
#
ifndef MINILIBC_INCLUDE_DIRECTORY
MINILIBC_INCLUDE_DIRECTORY	=	../minilibc/include/
endif #!MINILIBC_INCLUDE_DIRECTORY
#
T_ERRORHANDLER_SOURCES_DIRECTORY	=	$(T_ERRORHANDLER_DIRECTORY)/sources
T_ERRORHANDLER_OBJECTS_DIRECTORY	=	$(T_ERRORHANDLER_DIRECTORY)/objects
T_ERRORHANDLER_INCLUDE_DIRECTORY	=	$(T_ERRORHANDLER_DIRECTORY)/include

T_ERRORHANDLER_SOURCES	=	\
	$(T_ERRORHANDLER_SOURCES_DIRECTORY)/t_errorhandler.c\
	$(T_ERRORHANDLER_SOURCES_DIRECTORY)/t_errorhandler_developer.c\
	$(T_ERRORHANDLER_SOURCES_DIRECTORY)/t_errorhandler_perror.c


T_ERRORHANDLER_OBJECTS	=	$(subst .c,.o, $(subst $(T_ERRORHANDLER_SOURCES_DIRECTORY), $(T_ERRORHANDLER_OBJECTS_DIRECTORY), $(T_ERRORHANDLER_SOURCES)))
T_ERRORHANDLER_HEADERS	=	$(T_ERRORHANDLER_INCLUDE_DIRECTORY)/t_errorhandler.h\
							$(MINILIBC_INCLUDE_DIRECTORY)/minilibc.h
T_ERRORHANDLER_INCLUDE	=	-I$(T_ERRORHANDLER_INCLUDE_DIRECTORY)\
							-I$(MINILIBC_INCLUDE_DIRECTORY)

ifndef CFLAGS
CFLAGS				=	-Wall -Wextra -Werror
endif # !CFLAGS

$(T_ERRORHANDLER_OBJECTS_DIRECTORY)/%.o: $(T_ERRORHANDLER_SOURCES_DIRECTORY)/%.c $(T_ERRORHANDLER_HEADERS)
	@mkdir -p $(T_ERRORHANDLER_OBJECTS_DIRECTORY)
	cc $(CFLAGS) $(T_ERRORHANDLER_INCLUDE) -c $< -o $@

ifndef DONT_MAKE

NAME	=	objects

$(NAME): $(T_ERRORHANDLER_HEADERS) $(T_ERRORHANDLER_OBJECTS)

all: $(NAME)

clean:
	rm -rf $(T_ERRORHANDLER_OBJECTS_DIRECTORY)

fclean: clean

re: fclean all

endif # !DONT_MAKE

endif # !T_ERRORHANDLER_MAKEFILE
