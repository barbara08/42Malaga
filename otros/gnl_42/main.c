#include "get_next_line.h"

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    if (argc != 2)
    {
        printf("Add a file\n");
        return (1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
	//if(fd < 0)
    {
        printf("Error to open file.");
        return (1);
    }
   // printf("fd vale: %d", fd);
    /* Con este if sale el mensaje autómatico del sistema
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return (1);
    }
    */
    while ((line = get_next_line(fd)))
    {
		printf("%s", line);
		free(line);
	}
	//printf("no imprime nada");
    close(fd);
    return (0);
}

/* Mi main, no correcto del todo 
int main(int argc, char **argv)
{
    //dentificador del archivo abierto
    int fd;
    //Puntero que almacenará cada línea leída 
    char    *line;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
            perror("Error opening file");
            return (1);
        }
        printf("Lo que vale fd: %d\n", fd);
        line = get_next_line(fd);
        //Llamaremos a get_next_line(fd) repetidamente hasta que ya no queden líneas
        //line se actualizará con cada nueva línea leída del archivo
        //Terminaremos cuando retorne NULL (termina el archivo o ha habido error)
        while ((line != NULL))
        {
            printf("%s", line);
            free(line);
            line = get_next_line(fd);
        }
        close(fd);
    }
    return (0);
    // gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
    // ./gnl file1.txt
}
*/