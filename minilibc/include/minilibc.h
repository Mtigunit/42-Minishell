/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 23:42:32 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBC_H
# define MINILIBC_H

# include <stddef.h>

typedef struct s_minilibc
{
	int		pid;
	int		status;
	int		argc;
	char	**argv;
	char	**env;
}	t_minilibc;

# if defined(__unix__) || defined(__linux__)
#  define PLATFORM_LINUX
# elif defined(__APPLE__) && defined(__MACH__)
#  define PLATFORM_MACOS
# elif defined(_WIN32) || defined(_WIN64)
#  define PLATFORM_WINDOWS
# endif

# if defined PLATFORM_MACOS
#  define OS_UNICODE_LOGO ""
# elif defined(PLATFORM_WINDOWS)
#  define OS_UNICODE_LOGO "🖥️ "
# else
#  define OS_UNICODE_LOGO "🐧"
# endif

# define MAX_HOSTNAME_LEN 255
# define DEFAULT_HOSTNAME "unknown"

# define MINILIBC_REQUEST_SET        0
# define MINILIBC_REQUEST_GET        1337
# define MINILIBC_REQUEST_INIT       9998
# define MINILIBC_REQUEST_FINI       9999
# define MINILIBC_REQUEST_GETENVIRON 1338

# define GREATER_THAN_SCHAR_MAX    0b000000000000000000001
# define GREATER_THAN_UCHAR_MAX    0b000000000000000000010
# define GREATER_THAN_CHAR_MAX     0b000000000000000000100
# define GREATER_THAN_SHRT_MAX     0b000000000000000001000
# define GREATER_THAN_USHRT_MAX    0b000000000000000010000
# define GREATER_THAN_INT_MAX      0b000000000000000100000
# define GREATER_THAN_UINT_MAX     0b000000000000001000000
# define GREATER_THAN_LONG_MAX     0b000000000000010000000
# define GREATER_THAN_ULONG_MAX    0b000000000000100000000
# define GREATER_THAN_LLONG_MAX    0b000000000001000000000
# define LOWER_THAN_SCHAR_MIN      0b000000000010000000000
# define LOWER_THAN_UCHAR_MIN      0b000000000100000000000
# define LOWER_THAN_CHAR_MIN       0b000000001000000000000
# define LOWER_THAN_SHRT_MIN       0b000000010000000000000
# define LOWER_THAN_USHRT_MIN      0b000000100000000000000
# define LOWER_THAN_INT_MIN        0b000001000000000000000
# define LOWER_THAN_UINT_MIN       0b000010000000000000000
# define LOWER_THAN_LONG_MIN       0b000100000000000000000
# define LOWER_THAN_ULONG_MIN      0b001000000000000000000
# define LOWER_THAN_LLONG_MIN      0b010000000000000000000
# define NOT_A_NUMBER              0b100000000000000000000
# define DO_NOT_OVERWRITE 		0
# define OVERWRITE 				1
# define IGNORE_VALUE 			2
# define VIRTUAL_FILENAME_MAX	5
# define NUMERIC2STRING_MAX 	21
# define FILE_DESCRIPTOR_MAXLEN 5

char			*ft_relapath(char *dest, char *filename);
char			*ft_abspath(char *dest, char *filename);
char			*ft_pathof(char *to, const char *filename);
char			*ft_command_path(char *dest, char *command);
void			ft_exit(int status);
char			**ft_getargv(void);
char			*ft_getenv(const char *name);
char			**ft_getenviron(void);
char			*ft_strnjoin(char *s1, char *s2, int l1, int l2);
int				ft_getstatus(void);
unsigned long	ft_gettime(void);
char			*ft_getvar(const char *name);
char			*ft_hostname(void);
int				ft_isdigit(int c);
int				ft_isdir(const char *dirname);
int				ft_isfilename(const char *str);
int				ft_isquote(char c);
int				ft_isspace(int c);
int				ft_isvchar(char c);
int				ft_isvstart(char c);
int				ft_matched(const char *s1, const char *s2, int l1, int l2);
char			*ft_numeric2string(char *string, long long numeric);
int				ft_baselen(const char *base);
char			*ft_numeric2stringbase(char *string, long long numeric,
					const char *base);
long long		ft_parse_numeric(const char *str, int *flags);
char			*ft_progname(void);
char			*ft_prompt(void);
void			ft_putendl_fd(const char *str, int fd);
void			ft_putstr_fd(const char *str, int fd);
int				ft_setenv(char *name, char *value, int flag);
char			**ft_setenviron(char **environ);
int				ft_setstatus2(int status);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char **strs, char *delim);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strndup(const char *const src, size_t size);
char			**ft_strscpy(char **dest, char **src);
char			**ft_strsdup(char **strs);
char			**ft_strsenv(const char *name);
void			ft_strsfree(char **strs);
char			**ft_strsjoin(char **dest, char **src);
size_t			ft_strslen(char **strs);
char			*ft_timecpy(char *dest);
int				ft_unsetenv(const char *name);
int				ft_varlen(const char *str);
t_minilibc		*__minilibc(int argc, char **argv, char **env, int request);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memmove(void *s1, const void *s2, size_t n);
int				ft_getpid(void);
char			*ft_strncpy(char *dest, const char *src, size_t n);

#endif//MINILIBC_H
