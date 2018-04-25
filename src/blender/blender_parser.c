/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blender_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 14:14:16 by fxst1             #+#    #+#             */
/*   Updated: 2018/04/25 10:12:51 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void				add_vertex(t_blender_obj *o, char **tab)
{
	GLfloat				*new_array;
	size_t				i;

	i = 0;
	new_array = (GLfloat*)ft_memalloc(sizeof(GLfloat) * (o->n_vertices + 3));
	if (!new_array)
		blender_error("Out of memory\n");
	if (o->vertices)
		ft_memcpy(new_array, o->vertices, sizeof(GLfloat) * o->n_vertices);
	free(o->vertices);
	o->vertices = new_array;
	while (tab[i] && i < 3)
	{
		o->vertices[o->n_vertices + i] = ft_atof(tab[i]);
		i++;
	}
	o->n_vertices += 3;
}

static size_t			get_n_vertices(char **tab)
{
	size_t				i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static void				add_polygone(t_blender_obj *o, char **tab)
{
	GLuint				*new_array;
	size_t				i;
	size_t				index;
	size_t				n_vertices;

	i = 0;
	index = 0;
	n_vertices = get_n_vertices(tab);
	new_array = (GLuint*)malloc(sizeof(GLuint) * (o->n_points + n_vertices));
	if (!new_array)
		blender_error("add_face: 1: Out of memory\n");
	if (o->points)
		ft_memcpy(new_array, o->points, sizeof(GLuint) * o->n_points);
	free(o->points);
	o->points = new_array;
	while (tab[i])
	{
		index = ft_atoi(tab[i]);
		if (index <= o->n_vertices / 3)
			o->points[o->n_points + i] = index;
		else
			blender_error("Vertex index into a face declaration is bigger than number of vertices\n");
		i++;
	}
	o->n_points += i;
}

int						blender_parser(t_blender_obj *o, const char *line)
{
	char				**split;
	char				**tmp;

	if (!line)
		return (0);
	split = ft_strsplit(line, ' ');
	if (!split)
		blender_error("Cannot split instruction\n");
	if (!split[0])
	{
		free(split);
		return (0);
	}
	if (ft_strcmp(split[0], "v") == 0)
		add_vertex(o, split + 1);
	else if (ft_strcmp(split[0], "f") == 0)
		add_polygone(o, split + 1);
	tmp = split;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(split);
	return (0);
}
