
#include "get_next_line_bonus.h"

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
	ssize_t	len; //guardar la cantidad de bytes leídos en cada lectura
	char	*aux; //puntero auxiliar para gestionar la concatenación de cadenas

	len = 1;
	while (!(str && ft_strchr(str, '\n')) && len > 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			//free(buffer); no poner
			//return (free(str), NULL);
			free(str);
			return (NULL);
		}
		buffer[len] = '\0';
		aux = ft_strjoin(str, buffer);
		if (!aux)
		{
			//free(buffer); no poner
			//return (free(str), NULL);
			free(str);
			return (NULL);
		}
		free(str); //libera el antoguo str
		str = aux;
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
/*void	ffft_exclude_line(char *line, char *rest)
{ // Esta funcion tambien funciona correctamente
    int	i = 0;
    int	j = 0;

    while (line[i] && line[i] != '\n')
        i++;
    if (line[i] == '\n')
        i++;
    while (line[i])
        rest[j++] = line[i++];
    rest[j] = '\0';
    free(line);
}*/
 void	ft_exclude_line(char *line, char *rest)
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
			rest[j++] = line[i++];
		rest[j] = '\0';
	}
	free(line);
}

/*
//SE PUEDE PONER OPEN_MAX EN VEZ DE UN NUMERO FIJO al igual que BUFFER_SIZE
static char rest[OPEN_MAX][BUFFER_SIZE + 1];
significa que se declara una **variable estática** llamada `rest`, que es un **arreglo bidimensional** de caracteres.

static: la variable conserva su valor entre llamadas a la función y solo existe en ese archivo.
char rest[OPEN_MAX][BUFFER_SIZE + 1]`: es un array de `OPEN_MAX` filas, 
y cada fila es un array de `BUFFER_SIZE + 1` caracteres.

**¿Para qué sirve?**  
Se usa para guardar, para cada posible descriptor de archivo (`fd`), 
los caracteres "restantes" que no se han procesado aún (por ej, lo que queda después de un salto de línea). 
Así, puedes leer de varios archivos a la vez y mantener el estado de cada uno por separado.

**Problema:**  
Si `OPEN_MAX` y `BUFFER_SIZE` son grandes, este array ocupa mucha memoria, 
lo que puede causar errores como el que viste con Valgrind. 
Por eso, es mejor usar memoria dinámica para cada `fd`.*/

char	*get_next_line(int fd)
{
	char	*line_read;
	char	*line; 
	//OPEN_MAX es una constante del sistema 
	//que indica el número máximo de descriptores de archivos 
	//que un proceso puede tener abiertos simultáneamente
	static char rest[OPEN_MAX][BUFFER_SIZE + 1];

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	line = ft_read_file(fd, line, rest[fd]);
	if (!line)
		return (NULL);
	line_read = ft_extract_line(line);
	ft_exclude_line(line, rest[fd]);
	return (line_read);
}

//PARA LA FUNCION ft_read_file
/* 
int main(void)
{
	int		fd;
	char	*line;
	char	rest[BUFFER_SIZE + 1]; // Para guardar sobrantes entre llamadas
	char	*str = NULL;

	// Inicializamos rest vacío
	rest[0] = '\0';

	// Abrimos un archivo para leer
	fd = open("file1.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el archivo");
		return (1);
	}

	// Leemos una "línea extendida" con ft_read_file
	line = ft_read_file(fd, str, rest);
	if (line)
	{
		printf("Contenido leído:\n%s\n", line);
		free(line);
	}
	else
	{
		printf("No se pudo leer o EOF.\n");
	}

	close(fd);
	return (0);
}
	*/

//PARA LA FUNCION ft_read_and_join
/* 
int main(void)
{
	int     fd;
	char    *line;
	char    buffer[BUFFER_SIZE + 1]; // +1 para el null terminator
	char    *str = NULL;
	
	// Abrimos el archivo a leer
	fd = open("file1.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir archivo");
		return (1);
	}
	// Llamamos a ft_read_and_join para leer hasta \n
	line = ft_read_and_join(fd, str, buffer);
	if (line)
	{
		printf("Resultado leído:\n%s\n", line);
		free(line);
	}
	else
		printf("Error o fin de archivo.\n");
	close(fd);

	return (0);
}
*/

//PARA LA FUNCION ft_extract_line
/* 
int main(void)
{
	// Simulamos contenido leído del archivo
	char *linea1 = "Primera línea\nSegunda línea\nTercera línea";
	char *linea2 = "Una línea sin salto";
	char *linea3 = "";

	char *result;

	// Caso 1: línea con \n
	result = ft_extract_line(linea1);
	if (result)
	{
		printf("Extraído (linea 1): \"%s\"\n", result);
		free(result);
	}
	else
		printf("No se extrajo nada (linea 1)\n");

	// Caso 2: sin \n
	result = ft_extract_line(linea2);
	if (result)
	{
		printf("Extraído (linea 2): \"%s\"\n", result);
		free(result);
	}
	else
		printf("No se extrajo nada (linea 2)\n");

	// Caso 3: cadena vacía
	result = ft_extract_line(linea3);
	if (result)
	{
		printf("Extraído (linea 3): \"%s\"\n", result);
		free(result);
	}
	else
		printf("No se extrajo nada (linea 3)\n");

	return 0;
}
*/

//PARA LA FUNCION ft_exclude_line
/* 
int main(void)
{
	char *line1 = strdup("Primera línea\nSegunda línea\nTercera línea");
	char *line2 = strdup("Sin salto de línea");
	char rest[1024];  // Tamaño grande por simplicidad

	// Caso 1: línea con '\n'
	printf("Original:\n%s\n", line1);
	ft_exclude_line(line1, rest);
	printf("Contenido en rest (caso 1):\n%s\n", rest);

	// Caso 2: línea sin '\n'
	printf("\nOriginal sin salto:\n%s\n", line2);
	ft_exclude_line(line2, rest);
	printf("Contenido en rest (caso 2):\n%s\n", rest);  // Esperamos cadena vacía

	return (0);
}

*/