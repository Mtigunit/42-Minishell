#  **************************************************************************  #
#                                                                              #
#                                                          :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 23:42:32 by ahabachi          #+#    #+#              #
#    Updated: 2023/03/15 23:03:06 by ahabachi         ###   ########.fr        #
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

ifndef T_PARSER_MAKEFILE

T_PARSER_MAKEFILE	=	1

ifndef T_PARSER_DIRECTORY
T_PARSER_DIRECTORY	=	.
endif

ifndef MINILIBC_INCLUDE_DIRECTORY
MINILIBC_INCLUDE_DIRECTORY	=	../minilibc/include/
endif #!MINILIBC_INCLUDE_DIRECTORY

T_PARSER_SOURCES_DIRECTORY	=	$(T_PARSER_DIRECTORY)/sources
T_PARSER_OBJECTS_DIRECTORY	=	$(T_PARSER_DIRECTORY)/objects
T_PARSER_INCLUDE_DIRECTORY	=	$(T_PARSER_DIRECTORY)/include

T_PARSER_SOURCES	=	\
	$(T_PARSER_SOURCES_DIRECTORY)/t_parser_argclear.c\
	$(T_PARSER_SOURCES_DIRECTORY)/t_parser_argcpy.c\
	$(T_PARSER_SOURCES_DIRECTORY)/t_parser_argend.c\
	$(T_PARSER_SOURCES_DIRECTORY)/t_parser_argexp.c\
	$(T_PARSER_SOURCES_DIRECTORY)/t_parser_argvsplit.c\
	$(T_PARSER_SOURCES_DIRECTORY)/t_parser_cmdcpy.c\
	$(T_PARSER_SOURCES_DIRECTORY)/t_parser_skip_spaces.c\
	$(T_PARSER_SOURCES_DIRECTORY)/t_parser_skip_string.c\
	$(T_PARSER_SOURCES_DIRECTORY)/t_parser_trim.c\
	$(T_PARSER_SOURCES_DIRECTORY)/t_parser_utils.c\
	$(T_PARSER_SOURCES_DIRECTORY)/t_parser_wildcard.c\
	$(T_PARSER_SOURCES_DIRECTORY)/t_wildcard_utils.c


T_PARSER_OBJECTS	=	$(subst .c,.o, $(subst $(T_PARSER_SOURCES_DIRECTORY), $(T_PARSER_OBJECTS_DIRECTORY), $(T_PARSER_SOURCES)))
T_PARSER_HEADERS	=	$(T_PARSER_INCLUDE_DIRECTORY)/t_parser.h\
						$(MINILIBC_INCLUDE_DIRECTORY)/minilibc.h
T_PARSER_INCLUDE	=	-I$(T_PARSER_INCLUDE_DIRECTORY)\
						-I$(MINILIBC_INCLUDE_DIRECTORY)

ifndef CFLAGS
CFLAGS				=	-Wall -Wextra -Werror
endif # !CFLAGS

$(T_PARSER_OBJECTS_DIRECTORY)/%.o: $(T_PARSER_SOURCES_DIRECTORY)/%.c $(T_PARSER_HEADERS)
	@mkdir -p $(T_PARSER_OBJECTS_DIRECTORY)
	cc $(CFLAGS) $(T_PARSER_INCLUDE) -c $< -o $@

ifndef DONT_MAKE

NAME	=	objects

$(NAME): $(T_PARSER_HEADERS) $(T_PARSER_OBJECTS)

all: $(NAME)

clean:
	rm -rf $(T_PARSER_OBJECTS_DIRECTORY)

fclean: clean

re: fclean all

endif # !DONT_MAKE

endif # !T_PARSER_MAKEFILE
