
#include "get_next_line.h"

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
    line = ft_read_file(fd, line);
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