/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:53:29 by fxst1             #+#    #+#             */
/*   Updated: 2018/04/25 11:59:26 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vector3	vector3_init(float x, float y, float z)
{
	t_vector3	v;

	v.data[0] = x;
	v.data[1] = y;
	v.data[2] = z;
	return (v);
}