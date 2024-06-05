/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 05:04:53 by ahabachi          #+#    #+#             */
/*   Updated: 2024/01/02 08:50:39 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibc.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

unsigned long	ft_gettime(void)
{
	char		*filename;
	struct stat	st;
	int			fd;

	filename = "\1337-chaba7-and-segfaulter";
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd >= 0)
	{
		stat(filename, &st);
		close(fd);
		unlink(filename);
		return ((unsigned long) st.st_ctime);
	}
	return (0);
}
