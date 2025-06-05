
#include "get_next_line.h"
#include <string.h>

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
	int		flag;

	flag = 1;
	if (!s1)
	{
		s1 = "";
		flag = 0;
	}
	if (!s2)
		s2 = "";
	//if (!s1 || !s2)
	//	return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	reserve_join = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!reserve_join)
		return (NULL);
	ft_strlcpy(reserve_join, s1, s1_len + s2_len + 1);
	ft_strlcat(reserve_join, s2, s1_len + s2_len + 1);
	if (flag)
		free((void *)s1);
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
    //char *linea = strdup("Hola\nMundo\nFinal");
    char *str = "Hola\nMundo\nFinal";
    char *linea = ft_strdup(str);
    char *primera = ft_extract_line(linea);
    printf("Primera: %s", primera);

    linea = ft_exclude_line(linea);
    char *segunda = ft_extract_line(linea);
    printf("Segunda: %s", segunda);
    
    char *linea_completa = "Primera parte\nSegunda parte\nTercera parte";
    char *lc = ft_strdup(linea_completa);
    char *linea_extraida = ft_extract_line(lc);
    char *linea_excluida = ft_exclude_line(lc);
    if (linea_extraida || linea_excluida)
    {
        //printf("Línea extraída: \"%s\"\n", linea_extraida);
        printf("Línea extraída: %s", linea_extraida);
        printf("Línea excluida: %s", linea_excluida);

        free(linea_extraida);
        //free(linea_excluida);

    }
    else
        printf("No se pudo extraer ninguna línea.\n");
    return (0);
}

*/
