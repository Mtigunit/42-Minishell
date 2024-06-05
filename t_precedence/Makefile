#  **************************************************************************  #
#                                                                              #
#                                                          :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 13:17:34 by ahabachi          #+#    #+#              #
#    Updated: 2023/03/15 23:04:19 by ahabachi         ###   ########.fr        #
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

ifndef T_PRECEDENCE_MAKEFILE

T_PRECEDENCE_MAKEFILE	=	1

ifndef T_PRECEDENCE_DIRECTORY
T_PRECEDENCE_DIRECTORY	=	.
endif

ifndef MINILIBC_INCLUDE_DIRECTORY
MINILIBC_INCLUDE_DIRECTORY	=	../minilibc/include/
endif

ifndef T_PARSER_INCLUDE_DIRECTORY
T_PARSER_INCLUDE_DIRECTORY	=	../t_parser/include/
endif

T_PRECEDENCE_SOURCES_DIRECTORY	=	$(T_PRECEDENCE_DIRECTORY)/sources
T_PRECEDENCE_OBJECTS_DIRECTORY	=	$(T_PRECEDENCE_DIRECTORY)/objects
T_PRECEDENCE_INCLUDE_DIRECTORY	=	$(T_PRECEDENCE_DIRECTORY)/include

T_PRECEDENCE_SOURCES	=	\
	$(T_PRECEDENCE_SOURCES_DIRECTORY)/t_precedence_operation.c\
	$(T_PRECEDENCE_SOURCES_DIRECTORY)/t_precedence_parse.c\
	$(T_PRECEDENCE_SOURCES_DIRECTORY)/t_precedence_parse_parenthesis.c\
	$(T_PRECEDENCE_SOURCES_DIRECTORY)/t_precedence_parse_pipe.c\
	$(T_PRECEDENCE_SOURCES_DIRECTORY)/t_precedence_redirections.c\
	$(T_PRECEDENCE_SOURCES_DIRECTORY)/t_precedence_utils.c


T_PRECEDENCE_OBJECTS	=	$(subst .c,.o, $(subst $(T_PRECEDENCE_SOURCES_DIRECTORY), $(T_PRECEDENCE_OBJECTS_DIRECTORY), $(T_PRECEDENCE_SOURCES)))
T_PRECEDENCE_HEADERS	=	$(T_PRECEDENCE_INCLUDE_DIRECTORY)/t_precedence.h\
							$(T_PARSER_INCLUDE_DIRECTORY)/t_parser.h\
							$(MINILIBC_INCLUDE_DIRECTORY)/minilibc.h
T_PRECEDENCE_INCLUDE	=	-I$(T_PRECEDENCE_INCLUDE_DIRECTORY)\
							-I$(T_PARSER_INCLUDE_DIRECTORY)\
							-I$(MINILIBC_INCLUDE_DIRECTORY)

ifndef CFLAGS
CFLAGS				=	-Wall -Wextra -Werror
endif # !CFLAGS

$(T_PRECEDENCE_OBJECTS_DIRECTORY)/%.o: $(T_PRECEDENCE_SOURCES_DIRECTORY)/%.c $(T_PRECEDENCE_HEADERS)
	@mkdir -p $(T_PRECEDENCE_OBJECTS_DIRECTORY)
	cc $(CFLAGS) $(T_PRECEDENCE_INCLUDE) -c $< -o $@

ifndef DONT_MAKE

NAME	=	objects

$(NAME): $(T_PRECEDENCE_HEADERS) $(T_PRECEDENCE_OBJECTS)

all: $(NAME)

clean:
	rm -rf $(T_PRECEDENCE_OBJECTS_DIRECTORY)

fclean: clean

re: fclean all

endif # !DONT_MAKE

endif # !T_PRECEDENCE_MAKEFILE
