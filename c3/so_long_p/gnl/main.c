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
	/*if(fd < 0)
    {
        printf("Error to open file.");
        return (1);
    }*/
   // printf("fd vale: %d", fd);
    //Con este if sale el mensaje autómatico del sistema
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return (1);
    }
    
    while ((line = get_next_line(fd)))
    {
		printf("%s", line);
		free(line);
	}
	//printf("no imprime nada");
    close(fd);
    return (0);
}





/* 

	char *primera_linea = ft_extract_line(strchr);
    printf("Primera: %s", primera_linea);

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
