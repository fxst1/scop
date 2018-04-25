/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:52:44 by fxst1             #+#    #+#             */
/*   Updated: 2018/04/25 11:58:52 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H
# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include "libft.h"
# include <unistd.h>
# define VERTEX_SHADER "shaders/vertex.glsl"
# define FRAGMENT_SHADER "shaders/fragment.glsl"

typedef struct		s_vector3
{
	float			data[3];
}					t_vector3;

typedef struct		s_vector4
{
	float			data[4];
}					t_vector4;

typedef struct		s_matrix4
{
	float			data[16];
}					t_matrix4;

typedef struct		s_blender_obj
{
	char			*filename;
	size_t			n_vertices;
	size_t			n_points;
	GLfloat			*vertices;
	GLuint			*points;
}					t_blender_obj;

typedef struct		s_prog
{
	GLFWwindow		*window;
	GLuint			width;
	GLuint			height;
	t_blender_obj	model;
	GLuint			prog_id;
	GLuint			vao_id;
	GLuint			vbo_id;
}					t_prog;

void				blender_error(const char *msg);
int					blender_open(const char *filename, t_blender_obj *data);
int					blender_parser(t_blender_obj *o, const char *line);
void				blender_delete(t_blender_obj *o);

void				gl_loop(t_prog *p);
void				gl_draw(t_prog *p, t_blender_obj *o);
GLuint				gl_load_shaders(const char *path_vertex,
									const char *path_fragment);

#endif
