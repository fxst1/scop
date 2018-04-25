/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blender_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:57:47 by fxst1             #+#    #+#             */
/*   Updated: 2018/04/24 18:11:01 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	blender_error(const char *msg)
{
	ssize_t	tmp;

	tmp = write(STDERR_FILENO, msg, ft_strlen(msg));
	(void)tmp;
}
