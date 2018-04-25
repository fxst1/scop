/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:41:22 by fxst1             #+#    #+#             */
/*   Updated: 2018/04/25 11:41:45 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	gl_loop(t_prog *p)
{
	p->prog_id = gl_load_shaders(VERTEX_SHADER, FRAGMENT_SHADER);
	glfwSetInputMode(p->window, GLFW_STICKY_KEYS, GL_TRUE);
	while (1)
	{
		glClearColor(0.09f, 0.08f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(p->prog_id);
		gl_draw(p, &p->model);
		glfwPollEvents();
		glfwSwapBuffers(p->window);
		if (glfwGetKey(p->window, GLFW_KEY_ESCAPE) == GLFW_PRESS ||
			glfwWindowShouldClose(p->window) != 0)
			break ;
	}
}
