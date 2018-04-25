/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:00:40 by fxst1             #+#    #+#             */
/*   Updated: 2018/04/24 21:50:38 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"
void	ft_memdel(void **ap);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strnew(size_t size);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strchr(const char *str, int c);
int		ft_atoi(const char *str);
float	ft_atof(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strcat(char *dst, const char *src);

#endif
