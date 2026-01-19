/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:05:28 by bmartin-          #+#    #+#             */
/*   Updated: 2025/06/05 17:23:36 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *str, char *rest)
{
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (*rest)
	{
		str = ft_strjoin(str, rest);
		if (!str)
		{
			free(buffer);
			return (NULL);
		}
		rest[0] = '\0';
	}
	str = ft_read_and_join(fd, str, buffer);
	free(buffer);
	if (!str || *str == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*ft_read_and_join(int fd, char *str, char *buffer)
{
	ssize_t	len;
	char	*aux;

	len = 1;
	while (!(str && ft_strchr(str, '\n')) && len > 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			//free(buffer);
			free(str);
			return (NULL);
		}
			//return (free(str), NULL);
		buffer[len] = '\0';
		aux = ft_strjoin(str, buffer);
		if (!aux)
		{
			//free(buffer);
			free(str);
			return (NULL);
		}
			//return (free(str), NULL);
		str = aux;
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
	if (line[i] == '\n')
		i++;
	new_line = malloc((i + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

void	ft_exclude_line(char *line, char *rest)
{
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		i++;
		j = 0;
		while (line[i])
			rest[j++] = line[i++];
		rest[j] = '\0';
	}
	free(line);
}

char	*get_next_line(int fd)
{
	char	*line_read;
	char	*line;
	static char rest[BUFFER_SIZE + 1];

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = ft_read_file(fd, line, rest);
	if (!line)
		return (NULL);
	line_read = ft_extract_line(line);
	ft_exclude_line(line, rest);
	return (line_read);
}

/* --------------------------------------- */

//ESTE ES EL CODIGO PERFECTO, SIN DIVIDIR
/* 
char	*ft_read_file(int fd, char *str, char *rest)
{
	char	*buffer;
	char	*aux;
	ssize_t	len;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (*rest)
	{
		str = ft_strjoin(str, rest);
		if (!str)
		{
			free(buffer);
			return (NULL);
		}
		rest[0] = '\0';
	}
	len = 1;
	while (!(str && ft_strchr(str, '\n')) && len > 0)	
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[len] = '\0';
		aux = ft_strjoin(str, buffer);
		if (!aux)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		str = aux;
	}
	free(buffer);
	if (len == 0 && (str == NULL || *str == '\0'))
	{
		free(str);
		return (NULL);
	}
	return (str);
}*/
/* --------------------------------------- */

