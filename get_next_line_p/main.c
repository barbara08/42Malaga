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