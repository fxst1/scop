/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_divide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 12:10:03 by fxst1             #+#    #+#             */
/*   Updated: 2018/04/25 12:35:41 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vector3	vector3_divide(t_vector3 a, float factor)
{
	if (factor)
	{
		a.data[0] *= factor;
		a.data[1] *= factor;
		a.data[2] *= factor;
	}
	return (a);
}
