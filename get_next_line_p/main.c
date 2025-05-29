#include "get_next_line.h"

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
        printf("Lo que vale fd: %d", fd);
        line = get_next_line(fd);
        //Llamaremos a get_next_line(fd) repetidamente hasta que ya no queden líneas
        //line se actualizará con cada nueva línea leída del archivo
        //Terminaremos cuando retorne NULL (termina el archivo o ha habido error)
        while ((line != NULL))
        {
            printf("%s\n", line);
            free(line);
            line = get_next_line(fd);
        }
        free(line);
        close(fd);
    }
    return (0);
}