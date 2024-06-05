/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_signalshandler.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:34:21 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_SIGNALSHANDLER_H
# define T_SIGNALSHANDLER_H

void	t_signalshandler_init(void);
int		t_signalshandler_catch(int signal);
void	t_signalshandler_fini(void);

#endif //!T_SIGNALSHANDLER_H
