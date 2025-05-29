
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
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

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (size <= dst_len)
		return (src_len + size);
	while (src[i] != '\0' && (dst_len + i) < size - 1)
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

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	reserve_join = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
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

// ssize_t se utiliza para representar el tamaño de un bloque de datos 
// o el número de bytes leídos o escritos, permitiendo valores negativos en caso de error.

// Read File
    // Lee fichero en bloques (BUFFER_SIZE) y acumula lo leido en str
    // hasta encontar \n o el final del file

char    *ft_read_file(int fd, char *str)
{
    char    *buffer;
    ssize_t len;
    int xx = 0;

    //BUFFER_SIZE, se puede definir en el .h
    buffer = malloc((xx + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    len = 1;
    while (!(ft_strchr(str, '\n')) && len > 0)
    {
        len = read(fd, buffer, xx);
        if (len == -1)
        {
            free(buffer);
            return(NULL);
        }
        buffer[len] = '\0';
        str = ft_strjoin(str, buffer);
    }
    free (buffer);
    return (str);
}

// Extract Line
    // Extrae la 1º linea incluyendo \n
    // Copia los caracteres de str a new_str hasta \n o el final de la linea

char    *ft_extract_line(char *line)
{
    char    *new_line;
    int     i;

    i = 0;
    if (line[i] == 0)
        return (NULL);
        //Busca el indice del primer \n o el final de la linea
    while (line[i] && line[i] != '\n')
        i++;
        // i => (caracteres antes del \n) el 2 => (1 para el posible \n y 1 para el \0)
    new_line = (char *)malloc((i + 2) * sizeof(char));
    if (!new_line)
        return (NULL);
    i = 0;
        //Copia caracter por caracter hasta llegar '\n'
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

// Exclude Line
    // Elimina la 1º linea y retorna el resto de la linea

char    *ft_exclude_line(char *line)
{
    char    *str;
    int     i;
    int     j;

    i = 0;
    while (!line[i] && line[i] != '\n')
        i++;
        //Si no hay \n, significa que no hay más líneas
    if (!line[i])
    {
        //Libera la cadena original y retorna NULL
        free(line);
        return (NULL);
    }
    //Reserva memoria para copiar desde después del \n hasta el final
    // - i salta los caracteres de la primera línea
    str = (char *)malloc((ft_strlen(line) - i + 1) * sizeof(char));
    if (!str)
        return (NULL);
    //Copiar el resto del string
    i++;
    j = 0;
    while (line[i])
        //Empieza justo después del \n (i++) y Copia el resto del contenido a str
        str[j++] = line[i++];
    str[j] = '\0';
    free(line);
    return (str);
}



