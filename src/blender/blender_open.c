/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blender_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:14:43 by fxst1             #+#    #+#             */
/*   Updated: 2018/04/24 18:19:43 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static char	*get_instruction(char *line)
{
	size_t	len;
	char	*tmp;

	tmp = (char*)line;
	len = 0;
	while (*tmp && *tmp != '#')
	{
		len++;
		tmp++;
	}
	if (*tmp)
	{
		tmp = ft_strsub(line, 0, len);
		free(line);
		line = tmp;
	}
	return (line);
}

int			blender_open(const char *filename, t_blender_obj *data)
{
	int		ret_gnl;
	int		fd;
	char	*line;

	ft_bzero(data, sizeof(t_blender_obj));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		blender_error("Open error\n");
		return (-1);
	}
	data->filename = (char*)filename;
	while ((ret_gnl = get_next_line(fd, &line)) > 0)
	{
		line = get_instruction(line);
		if (blender_parser(data, line) != 0)
		{
			close(fd);
			return (-1);
		}
		free(line);
		line = NULL;
	}
	if (ret_gnl == -1)
		blender_error("Read error\n");
	else
		free(line);
	close(fd);
	return (1);
}
