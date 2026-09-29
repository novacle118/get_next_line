/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstadler <fstadler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:17:57 by fstadler          #+#    #+#             */
/*   Updated: 2026/07/09 14:47:13 by fstadler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_memory(char *line, char *next_line)
{
	char	*new_line;
	char	*result;
	size_t	len;
	size_t	rest;

	new_line = ft_strchr(line, '\n');
	if (!new_line)
	{
		next_line[0] = '\0';
		return (line);
	}
	len = ((ft_strlen(line) - ft_strlen(new_line)) + 1);
	rest = ft_strlen(line) - len;
	if (line)
		ft_memcpy(next_line, &line[len], rest);
	if (next_line)
		next_line[rest] = '\0';
	result = malloc(len + 1);
	if (!result)
		return (free(line), NULL);
	ft_memcpy(result, line, len);
	if (result)
		result[len] = '\0';
	free(line);
	return (result);
}

static char	*ft_join(char *line, char *next_line, int bytes_read)
{
	int		i;
	char	*temp;

	i = bytes_read;
	while (i < BUFFER_SIZE)
		next_line[i++] = '\0';
	temp = ft_strjoin(line, next_line);
	if (!temp)
		return (free(line), NULL);
	free(line);
	return (temp);
}

static char	*ft_read(char *next_line, int fd)
{
	int		bytes_read;
	char	*line;

	line = NULL;
	if (next_line[0] != '\0')
		line = ft_strdup(next_line);
	while (!ft_strchr(line, '\n'))
	{
		bytes_read = read(fd, next_line, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(line), next_line[0] = '\0', NULL);
		if (bytes_read == 0)
			return (line);
		line = ft_join(line, next_line, bytes_read);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	next_line[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read(next_line, fd);
	if (!line)
		return (NULL);
	line = ft_memory(line, next_line);
	return (line);
}
