
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




//ANTIGUO CODIGO PARA VER LA DIFERENCIA



// ssize_t se utiliza para representar el tamaño de un bloque de datos 
// o el número de bytes leídos o escritos, permitiendo valores negativos en caso de error.

// Read File
    // Lee fichero en bloques (BUFFER_SIZE) y acumula lo leido en str
    // hasta encontar \n o el final del file

char    *ft_read_file(int fd, char *str)
{
    char    *buffer; //para leer bloques de datos desde el file
    char    *aux; //aux para hacer strjoin
    ssize_t len; //cantidad leida por read

    //BUFFER_SIZE, está definida en el .h
    //reservamos memoria para leer hasta BUFFER_SIZE bytes + 1 que es el \0
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    len = 1;
    //No encontramos '\n' en str, y la última lectura sea mayor que 0 (NO estamos en EOF)
    while (!(str && ft_strchr(str, '\n')) && len > 0)
    {
        //Lee hasta BUFFER_SIZE bytes del fd al buffer
        //devuelve la cantidad de bytes que se leyeron
        //EOF = 0; error = -1
        len = read(fd, buffer, BUFFER_SIZE);
        //Si hay error de lectura libera buffer y devuelve NULL
        if (len == -1)
        {
            free(buffer);
            return(NULL);
        }
        //Nos aseguramos que buffer termina con '\0'
        //Luego join de str con lo que acaba de leer
        //Libera memoria anterior de str y actualiza con el nuevo string
        buffer[len] = '\0';
        aux = ft_strjoin(str, buffer);
        if (str)
            free(str);
        str = aux;
    }
    //libera buffer antes de salir
    free(buffer);
    // Si llegamos al EOF y no hay nada leído (str es NULL o cadena vacía)
    //también se libera str y devuelve NULL
    if (len == 0 && (str == NULL || *str == '\0'))
    {
        if (str)
            free(str);
        return (NULL);
    }
    //si se leyó algo (aunque no haya '\n') devulve str acumulado
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
    int     i; //recorrer line hasta el primer '\n'
    int     j; //para copiar después del '\n' al new_line

    i = 0;
    //Busca hasta encontrar el primer '\n' o el final
    while (line[i] && line[i] != '\n')
        i++;
    //Si no hay \n, significa que no hay más líneas
    if (!line[i])
    {
        //Libera la cadena original y retorna NULL
        free(line);
        return (NULL);
    }
    //Reserva memoria para el nuevo str
    // - i salta los caracteres de la primera línea
    //str = (char *)malloc((ft_strlen(line) - i + 1) * sizeof(char));
    //line + 1 apunta justo donde está el '\n'
    str = malloc((ft_strlen(line + i) + 1) * sizeof(char));
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


//Funciona correctamente con un BUFFER_SIZE grande como 9999
//porque la lógica no depende del tamaño del buffer para detectar 
//los saltos de línea, sino del contenido leído.

char    *get_next_line(int fd)
{
    char        *line_read;
    static char *line;
    //char    BUFFER_SIZE;
    if (BUFFER_SIZE <= 0 || fd < 0)
    {
        /*if (line)
        {
            free(line);
            line = NULL;
        }*/
        return (NULL);
    }
    // Leer del archivo y acumular
    //line = ft_read_file(fd, line);
    if (!line)
        return (NULL);
    // Extraer la siguiente línea (incluyendo \n si hay)
    line_read = ft_extract_line(line);
    // Actualizar 'line' con el contenido restante
    line = ft_exclude_line(line);
    if (!line_read)
    {
        free(line);
        line = NULL;
    }
    return (line_read);
}
