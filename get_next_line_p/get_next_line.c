
#include "get_next_line.h"

//Esta función gestiona la lectura de un archivo en fragmentos, 
//manejando casos donde hay datos "restantes" 
//y asegurándose de liberar memoria correctamente en caso de errores.
char	*ft_read_file(int fd, char *str, char *rest)
{
	char	*buffer;

	//reservamos memoria para leer fragmentos del archivo
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	//Si rest no está vacío une esa cadena con str usando ft_strjoin
	//Esto es porque si hay datos "restantes" de una lectura anterior
	//y queremops agregar.
	if (*rest)
	{
		str = ft_strjoin(str, rest);
		if (!str)
		{
			free(buffer);
			return (NULL);
		}
		//Después de unir, pone el carácter nulo en rest[0], limpiándolo
		rest[0] = '\0';
	}
	//Llamamos a la función ft_read_and_join, 
	//que lee del archivo descriptor fd 
	//y va agregando los datos a str, usando el buffer.
	str = ft_read_and_join(fd, str, buffer);
	free(buffer);
	//Si str es NULL o está vacío libera str y devuelve NULL
	if (!str || *str == '\0')
	{
		free(str);
		return (NULL);
	}
	//Devuelve la cadena leida
	return (str);
}

//esta función lee del archivo en bloques, 
//los va concatenando en una sola cadena 
//y se detiene cuando encuentra un salto de línea 
//o cuando ya no hay más datos para leer
char	*ft_read_and_join(int fd, char *str, char *buffer)
{
	ssize_t	len; //guardar la cantidad de bytes leídos en cada lectura
	char	*aux; //puntero auxiliar para gestionar la concatenación de cadenas

	len = 1;
	//El ciclo continúa mientras no se haya encontrado un salto de línea
	//en str y mientras len sea mayor que 0 (es decir, mientras sigan llegando datos)
	//significa: "si str no es NULL y no contiene un salto de línea,
	//y todavía hay datos que leer"
	while (!(str && ft_strchr(str, '\n')) && len > 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		//Si hubo error (-1) sse libera str
		if (len == -1)
		{
			//free(buffer); no poner
			//return (free(str), NULL);
			free(str);
			return (NULL);
		}
		buffer[len] = '\0';
		//Se une la cadena actual (str) con el contenido de buffer
		//usando ft_strjoin
		aux = ft_strjoin(str, buffer);
		if (!aux)
		{
			//free(buffer); no poner
			//return (free(str), NULL);
			free(str);
			return (NULL);
		}
		//Actualizar, la variable str ahora apunta a la nueva cadena concatenada
		str = aux;
	}
	return (str);
}

//Extrae una línea del texto, incluyendo el salto de línea si hay.
char	*ft_extract_line(char *line)
{
	char	*new_line;
	int		i;

	i = 0;
	//Si el puntero es nulo o si la cadena está vacía
	//Si se cumple es porque no hay ninguna linea a extraer
	if (!line || line[i] == 0)
		return (NULL);
	//Recorrer la cadena hasta que encuentre \n
	while (line[i] && line[i] != '\n')
		i++;
	//Si encontró un salto de línea, 
	//avanza una posición más para incluirlo en la línea extraída.
	if (line[i] == '\n')
		i++;
	new_line = malloc((i + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	//Para copiar la linea
	//copia los caracteres desde line a new_line hasta llegar a \n o al final de la cadena
	while (line[i] && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	//Agregar el salto de línea si existe
	//Si la línea original tenía un \n, 
	//lo añade al final de new_line
	if (line[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	//Devuelve el puntero a la nueva cadena que contiene la línea extraída
	return (new_line);
}

//Para cuando se quiere procesar un texto linea por linea 
//y seguir trabajando con las partes restantes.
//La funcion lo que hace es eliminar la primera línea de line
//y guardar el resto en rest
void	ft_exclude_line(char *line, char *rest)
{
	int		i;
	int		j;

	i = 0;
	//Busca el final de la primera línea
	//Esto identifica dónde termina la primera línea
	while (line[i] && line[i] != '\n')
		i++;
	//Si en la posición i hay un '\n',
	//entonces: Incrementa i para saltar ese \n
	if (line[i] == '\n')
	{
		i++;
		//Usamos j para copiar desde esa posición en adelante 
		//en line hacia rest
		j = 0;
		while (line[i])
			//Copia todos los caracteres después del \n
			rest[j++] = line[i++];
		//ponemos el \0 al final de rest para el final de la cadena
		rest[j] = '\0';
	}
	free(line);
}

//Cada vez que llamas a get_next_line(fd), se obtiene
//la siguiente línea del archivo, 
//gestionando internamente el buffer y las partes no leídas. 
//Es una función muy útil para leer archivos línea por línea 
//de manera eficiente.

//Leer una linea completa desde un fd
char	*get_next_line(int fd)
{
	char	*line_read;
	//almacena la linea leida actual
	char	*line; 
	//Array estático para guardar la parte del texto 
	//que quedó después de la última lectura, 
	//para usarla en la siguiente llamada.
	static char rest[BUFFER_SIZE + 1];

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	//LLama a la funcion para leer fd y guardar el contenido en line
	line = ft_read_file(fd, line, rest);
	if (!line)
		return (NULL);
	//Llama a la funcion para obtener la linea completa includo el \n 
	//y lo guarda en line_read
	line_read = ft_extract_line(line);
	//Actualizar el resto
	//Llama a la funcion para eliminar la linea 
	//que ya fue leida de line y guarda el resto en rest
	//Esto prepara rest para la próxima llamada,
	//asegurando que la siguiente lectura continua desde donde se quedó
	ft_exclude_line(line, rest);
	//Devuelve variable que contiene la linea completa leida del fd
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