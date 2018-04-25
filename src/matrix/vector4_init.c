/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:53:29 by fxst1             #+#    #+#             */
/*   Updated: 2018/04/25 12:05:08 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vector4	vector4_init(float x, float y, float z, float w)
{
	t_vector4	v;

	v.data[0] = x;
	v.data[1] = y;
	v.data[2] = z;
	v.data[3] = w;
	return (v);
}