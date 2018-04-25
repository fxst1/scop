/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:05:16 by fxst1             #+#    #+#             */
/*   Updated: 2018/04/25 11:04:00 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	gl_draw(t_prog *p, t_blender_obj *o)
{
	//glEnableVertexAttribArray(0);
	glBindVertexArray(p->vao_id);
	glDrawArrays(GL_TRIANGLES, 0, o->n_vertices / 3);
	glBindVertexArray(0);
	//glEnableVertexAttribArray(0);
	(void)o;
}
