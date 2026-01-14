
#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	//if (!src || !dst)
	if (!src)
		return (0);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	/*if (!src)
		return (0);
	if (!dst && size == 0)
		return (ft_strlen(src));
	if (!dst)
		return (0);*/
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (src_len + size);
	i = 0;
	//while (src[i] != '\0' && (dst_len + i) < size - 1)
	while (src[i] && (dst_len + i) < size - 1)

	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*reserve_join;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	reserve_join = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!reserve_join)
		return (NULL);
	ft_strlcpy(reserve_join, s1, s1_len + s2_len + 1);
	ft_strlcat(reserve_join, s2, s1_len + s2_len + 1);
	return (reserve_join);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*aux;
	char	char_c;

	i = 0;
	char_c = (char)c;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == char_c)
		{
			aux = (char *) &s[i];
			return (aux);
		}
		i++;
	}
	if (char_c == '\0')
	{
		aux = (char *) &s[i];
		return (aux);
	}
	else
		return (NULL);
}


/* OTRA VERSION DE ft_strchr */

/*
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
*/

/* 
int main(void)
{
    char *str = "Hola\nsoy\nBarbara";
	char dst[12];
	char src[22] = "Periquito los palotes";
	int size = 10;
	//char const *s1 = "A ver que sale";
	//char const *s2 = "no se porque";

	size_t str_len = ft_strlen(str);
	size_t strl_cpy = ft_strlcpy(dst, src, size);
	size_t strl_cat = ft_strlcat(dst, src, size);
	//char *str_join = ft_strjoin(s1, s2);
    char *str_chr = ft_strchr(str, '\n');

	printf("dst: %s", dst);
	printf("\n");
	printf("src %s", src);
	printf("\n");

	printf("El resultado de ft_strlen es: %zu", str_len);
	printf("\n");

	printf("El resultado de ft_strlcpy es: %zu", strl_cpy);
	printf("\n");
	printf("Lo que vale dst después de llamar a la funcion: %s", dst);
	printf("\n");
	printf("Lo que vale src después de llamar a la funcion: %s", src);
	printf("\n");

	printf("El resultado de ft_strlcat es: %zu", strl_cat);
	printf("\n");
	printf("Lo que vale dst después de llamar a la funcion: %s", dst);
	printf("\n");
	printf("Lo que vale src después de llamar a la funcion: %s", src);
	printf("\n");

	//printf("El resultado de ft_strjoin es: %s", str_join);
	//printf("\n");

	printf("El resultado de ft_strchr es: %s", str_chr);
	printf("\n");
	

	return(0);

}

*/
