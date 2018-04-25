/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:28:08 by fxst1             #+#    #+#             */
/*   Updated: 2018/04/24 17:10:15 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	float_part(const char *str)
{
	float		dec;
	float		factor;

	dec = 0.0;
	factor = 1;
	while (*str <= '9' && *str >= '0')
	{
		factor /= 10;
		dec *= 10;
		dec += *str - '0';
		str++;
	}
	return (dec * factor);
}

float			ft_atof(const char *str)
{
	float		dec;
	int			ent;
	int			neg;

	dec = 0.0;
	ent = 0;
	neg = 0;
	if (*str == '-')
		neg = 1;
	while (*str <= '9' && *str >= '0')
	{
		ent *= 10;
		ent += (*str - '0');
		str++;
	}
	if (*str != '.')
		return ((float)ent);
	dec = float_part(str + 1);
	return (!neg ? ((float)ent) + dec : -((float)ent) + dec);
}
