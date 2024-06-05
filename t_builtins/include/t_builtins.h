/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_builtins.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 05:36:09 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_BUILTINS_H
# define T_BUILTINS_H

int	t_builtins_cd(int argc, char **argv,
		__attribute__ ((unused)) char **env);
int	t_builtins_echo(int argc, char **argv,
		__attribute__ ((unused)) char **env);
int	t_builtins_env(
		__attribute__ ((unused)) int	argc,
		__attribute__ ((unused)) char	**argv,
		char							**env
		);

int	t_builtins_execute(int *status, char **argv, char **env);
int	t_builtins_exit(int argc, char **argv, __attribute__ ((unused)) char **env);
int	t_builtins_export(int argc, char **argv);
int	t_builtins_pwd(
		__attribute__ ((unused)) int	argc,
		__attribute__ ((unused)) char	**argv,
		__attribute__ ((unused)) char	**env
		);
int	t_builtins_unset(int argc, char **argv,
		__attribute__ ((unused)) char **env);

#endif //!T_BUILTINS_H
