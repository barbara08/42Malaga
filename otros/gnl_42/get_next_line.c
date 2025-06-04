/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:05:28 by bmartin-          #+#    #+#             */
/*   Updated: 2025/06/04 16:37:29 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *str, char *resto)
{
	char	*buffer;
	char	*aux;
	ssize_t	len;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (*resto)
	{
		str = ft_strjoin(str, resto);
		if (!str)
		{
			free(buffer);
			return (NULL);
		}
		resto[0] = '\0';
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

void	ft_exclude_line(char *line, char *resto)
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
			resto[j++] = line[i++];
		resto[j] = '\0';
	}
	free(line);
}

char	*get_next_line(int fd)
{
	char	*line_read;
	char	*line;
	static char resto[BUFFER_SIZE + 1];

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = ft_read_file(fd, line, resto);
	if (!line)
		return (NULL);
	line_read = ft_extract_line(line);
	ft_exclude_line(line, resto);
	return (line_read);
}

/* --------------------------------------- */
/*

void	validate_pointer_and_free(char *str)
{
	if (str)
		free(str);
}


FUNCION DIVIDIDA EN 2  (ft_read_and_strjoin) y (ft_read_file)

char *ft_read_and_strjoin(int fd, char *str, char *buffer)
{
    ssize_t len;
    char *aux;

    len = read(fd, buffer, BUFFER_SIZE);
	// controla error (-1) y EOF (0)
    if (len <= 0)
    {
        free(buffer);		
        if (str)
            free(str);
        return NULL;
    }
    buffer[len] = '\0';
    aux = ft_strjoin(str, buffer);
    if (!aux)
    {
        free(buffer);
        if (str)
            free(str);
        return NULL;
    }	
    if (str)
        free(str);
    return (aux);
}


char	*ft_read_file(int fd, char *str)
{
	char	*buffer;
	ssize_t	len;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	len = 1;
	while (!(str && ft_strchr(str, '\n')) && len > 0)	
	{
		str = ft_read_and_strjoin(fd, str, buffer);
		if (!str)
    		return (NULL);
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
*/


/* --------------------------------------- */

/* ORIGINAL SIN DIVIDIR

char	*fSSSft_read_file(int fd, char *str)
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
*/