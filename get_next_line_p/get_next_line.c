/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:10:47 by bmartin-          #+#    #+#             */
/*   Updated: 2025/05/29 18:42:39 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line_read;
	static char	*line;
	//char		BUFFER_SIZE;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free(line);
		line_read = NULL;
		return (NULL);
	}
	line = ft_read_file(fd, line);
	if (!line)
		return (NULL);
	line_read = ft_extract_line(line);
	line = ft_exclude_line(line);
	return (line_read);
}

