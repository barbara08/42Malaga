#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_putnbr_fd(int n, int fd);
int ft_flood_fill(t_info_map *info_map);


#endif
