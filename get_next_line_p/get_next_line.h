

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char    *ft_read_file(int fd, char *str);
char    *ft_extract_line(char *line);
char    *ft_exclude_line(char *line);

#endif
