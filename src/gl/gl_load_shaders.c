/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_load_shaders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 20:50:08 by fxst1             #+#    #+#             */
/*   Updated: 2018/04/24 21:48:47 by fxst1            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static char	*get_source(const char *path)
{
	ssize_t	ret;
	int		fd;
	char	*buf;
	char	*tmp;
	size_t	bufsize;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	bufsize = 1024;
	tmp = ft_strnew(bufsize);
	buf = NULL;
	while (1)
	{
		ret = read(fd, tmp, 1024);
		if (ret < 0)
		{
			write(STDERR_FILENO, "Cannot open shader ", 19);
			write(STDERR_FILENO, path, ft_strlen(path));
			write(STDERR_FILENO, "\n", 1);
			exit(EXIT_FAILURE);
		}
		else if (ret == 0)
			return (buf);
		buf = ft_strnew(bufsize);
		ft_strcat(buf, tmp);
		bufsize += 1024;
	}
	return (buf);
}

static void	check_error(GLuint id, const char *shader_path)
{
	int		infoLogLength;
	GLint	result;
	char	*err;

	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(id, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0)
	{
		err = ft_strnew(infoLogLength);
		glGetShaderInfoLog(id, infoLogLength, NULL, err);
		write(STDERR_FILENO, shader_path, ft_strlen(shader_path));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, err, infoLogLength);
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
}

static void	check_error2(GLuint id)
{
	int		infoLogLength;
	GLint	result;
	char	*err;

	glGetProgramiv(id, GL_LINK_STATUS, &result);
	glGetProgramiv(id, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (infoLogLength > 0)
	{
		err = ft_strnew(infoLogLength);
		glGetProgramInfoLog(id, infoLogLength, NULL, err);
		write(STDERR_FILENO, err, infoLogLength);
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
}

GLuint		gl_load_shaders(const char *path_vertex, const char *path_fragment)
{
	GLuint	vertShId;
	GLuint	fragShId;
	GLuint	progId;
	char	*source;

	vertShId = glCreateShader(GL_VERTEX_SHADER);
	fragShId = glCreateShader(GL_FRAGMENT_SHADER);
	source = get_source(path_vertex);
	glShaderSource(vertShId, 1, (const GLchar * const*)&source, NULL);
	glCompileShader(vertShId);
	check_error(fragShId, path_vertex);
	free(source);
	source = get_source(path_fragment);
	glShaderSource(fragShId, 1, (const GLchar * const*)&source, NULL);
	glCompileShader(fragShId);
	check_error(fragShId, path_fragment);
	free(source);
	progId = glCreateProgram();
	glAttachShader(progId, vertShId);
	glAttachShader(progId, fragShId);
	glLinkProgram(progId);
	check_error2(progId);
	glDetachShader(progId, vertShId);
	glDetachShader(progId, fragShId);
	glDeleteShader(vertShId);
	glDeleteShader(fragShId);
	return (progId);
}
