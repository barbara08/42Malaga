

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include <fcntl.h> 
# include <stdio.h>

/*
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
 */

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char    *ft_read_file(int fd, char *str);
char    *ft_extract_line(char *line);
char    *ft_exclude_line(char *line);
char    *get_next_line(int fd);

#endif
