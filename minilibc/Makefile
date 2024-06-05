#  **************************************************************************  #
#                                                                              #
#                                                          :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahabachi <ahabachi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 23:42:32 by ahabachi          #+#    #+#              #
#    Updated: 2023/03/15 22:46:46 by ahabachi         ###   ########.fr        #
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

ifndef MINILIBC_MAKEFILE

MINILIBC_MAKEFILE	=	1

ifndef MINILIBC_DIRECTORY
MINILIBC_DIRECTORY	=	.
endif #!MINILIBC_DIRECTORY
#
REMOVE						=	rm -rf
CC							=	cc
#
MINILIBC_SOURCES_DIRECTORY	=	$(MINILIBC_DIRECTORY)/sources
MINILIBC_OBJECTS_DIRECTORY	=	$(MINILIBC_DIRECTORY)/objects
MINILIBC_INCLUDE_DIRECTORY	=	$(MINILIBC_DIRECTORY)/include

MINILIBC_SOURCES	=	\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_bzero.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_calloc.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_command_path.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_exit.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_getargv.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_getenv.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_getenviron.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_getpid.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_getstatus.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_gettime.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_getvar.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_hostname.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_isdigit.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_isdir.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_isfilename.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_isquote.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_isspace.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_isvchar.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_isvstart.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_matched.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_memmove.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_memset.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_numeric2string.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_numeric2stringbase.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_parse_numeric.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_progname.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_prompt.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_putendl_fd.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_putstr_fd.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_setenv.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_setenviron.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_setstatus.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strcat.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strchr.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strcmp.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strcpy.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strdup.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strjoin.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strlen.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strncat.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strncmp.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strncpy.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strndup.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strnjoin.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strscpy.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strsdup.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strsenv.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strsfree.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strsjoin.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_strslen.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_timecpy.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_unsetenv.c\
						$(MINILIBC_SOURCES_DIRECTORY)/ft_varlen.c\
						$(MINILIBC_SOURCES_DIRECTORY)/minilibc.c

MINILIBC_OBJECTS	=	$(subst .c,.o, $(subst $(MINILIBC_SOURCES_DIRECTORY), $(MINILIBC_OBJECTS_DIRECTORY), $(MINILIBC_SOURCES)))
MINILIBC_HEADERS	=	$(MINILIBC_INCLUDE_DIRECTORY)/minilibc.h
MINILIBC_INCLUDE	=	-I$(MINILIBC_INCLUDE_DIRECTORY)

ifndef CFLAGS
CFLAGS				=	-Wall -Wextra -Werror
endif # !CFLAGS

$(MINILIBC_OBJECTS_DIRECTORY)/%.o: $(MINILIBC_SOURCES_DIRECTORY)/%.c $(MINILIBC_HEADERS)
	@mkdir -p $(MINILIBC_OBJECTS_DIRECTORY)
	$(CC) $(CFLAGS) $(MINILIBC_INCLUDE) -c $< -o $@

ifndef DONT_MAKE

NAME	=	objects

$(NAME): $(MINILIBC_HEADERS) $(MINILIBC_OBJECTS)

all: $(NAME)

clean:
	$(REMOVE) $(MINILIBC_OBJECTS_DIRECTORY)

fclean: clean

re: fclean all

endif # !DONT_MAKE

endif # !MINILIBC_MAKEFILE
