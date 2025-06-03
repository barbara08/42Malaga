/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:05:28 by bmartin-          #+#    #+#             */
/*   Updated: 2025/06/03 14:30:24 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *str)
{
	char	*buffer;
	char	*aux;
	ssize_t	len;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	len = 1;
	while (!(str && ft_strchr(str, '\n')) && len > 0)	
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			free(buffer);
			if (str)
				free(str);
			return (NULL);
		}
		buffer[len] = '\0';
		aux = ft_strjoin(str, buffer);
		if (!aux)
		{
			free(buffer);
			if (str)
				free(str);
			return (NULL);
		}
		if (str)
			free(str);
		str = aux;
	}
	free(buffer);
	if (len == 0 && (str == NULL || *str == '\0'))
	{
		if (str)
			free(str);
		return (NULL);
	}
	return (str);
}

char	*ft_extract_line(char *line)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!line || line[i] == 0)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	new_line = malloc((i + 2) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		new_line[i] = '\n';
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_exclude_line(char *line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	i++;
	str = malloc((ft_strlen(line + i) + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line_read;
	static char	*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (line)
		{
			free(line);
			line = NULL;
		}
		return (NULL);
	}
	line = ft_read_file(fd, line);
	if (!line)
		return (NULL);
	line_read = ft_extract_line(line);
	line = ft_exclude_line(line);
	if (!line_read)
			line = NULL;
	return (line_read);
}
