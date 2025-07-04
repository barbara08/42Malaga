
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h> 
# include <stdio.h>
# include <string.h>

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_read_and_join(int fd, char *str, char *buffer);
/* char	*ft_read_file(int fd, char *str);
char	*ft_extract_line(char *line, char *rest);
char	*ft_exclude_line(char *line); */
char	*get_next_line(int fd);

#endif