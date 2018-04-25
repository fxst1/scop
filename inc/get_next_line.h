/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjacquem <fjacquem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:04:30 by fjacquem          #+#    #+#             */
/*   Updated: 2018/04/24 17:31:07 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFF_SIZE
#  define BUFF_SIZE 1024
# endif
# ifndef DELIM
#  define DELIM '\n'
# endif
#  define BIN_MODE 0
# include <fcntl.h>
# include "libft.h"
typedef struct	s_gnl
{
	int			fd;
	char		*buffer;
}				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
