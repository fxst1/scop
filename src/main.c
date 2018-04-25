/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:53:21 by fxst1             #+#    #+#             */
/*   Updated: 2018/04/25 11:35:09 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	create_buffers(t_prog *program)
{
	glGenVertexArrays(1, &program->vao_id);
	glBindVertexArray(program->vao_id);
	glGenBuffers(1, &program->vbo_id);
	glBindBuffer(GL_ARRAY_BUFFER, program->vbo_id);
	glBufferData(GL_ARRAY_BUFFER, program->model.n_vertices * sizeof(GLfloat),
				program->model.vertices,
				GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0); // Désactiver le VAO
	glBindVertexArray(0);
}

static void	init(t_prog *program)
{
	glewExperimental = GL_TRUE;
	if (!glfwInit())
	{
		write(STDERR_FILENO, "glfwInit failed\n", 16);
		exit(EXIT_FAILURE);
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	program->window = glfwCreateWindow(program->width, program->height,
										program->model.filename, NULL, NULL);
	if (program->window == NULL)
	{
		glfwTerminate();
		write(STDERR_FILENO, "Failed to open window\n", 21);
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(program->window);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		write(STDERR_FILENO, "glewInit failed\n", 16);
		exit(EXIT_FAILURE);
	}
}

int			main(int ac, char **av)
{
	t_prog			program;

	ft_bzero(&program, sizeof(t_prog));
	if (ac == 2)
	{
		program.width = 1000;
		program.height = 1000;
		blender_open(av[1], &program.model);
		init(&program);
		create_buffers(&program);
		gl_loop(&program);
		blender_delete(&program.model);
		glfwTerminate();
	}
	return (0);
	(void)av;
}
