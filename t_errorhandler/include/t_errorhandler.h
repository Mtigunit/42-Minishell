/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_errorhandler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 03:15:10 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ERRORHANDLER_H
# define T_ERRORHANDLER_H 20230308

int		t_errorhandler_error(int argc, char **argv);
void	t_errorhandler_developer(int line, const char *file);
int		t_errorhandler_perror(char *message);

#endif // !T_ERRORHANDLER_H
