/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_multiply.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 12:10:03 by fxst1             #+#    #+#             */
/*   Updated: 2018/04/25 12:36:18 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vector3	vector3_multiply(t_vector3 a, float factor)
{
	a.data[0] *= factor;
	a.data[1] *= factor;
	a.data[2] *= factor;
	return (a);
}
