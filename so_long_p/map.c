#include "so_long.h"

int ft_validate_file(char *file_path)
{
    char *extension;
    int len_extension;
    int len_file_path;
    int i;
    
    if(file_path == NULL)
        return(0);
    extension = ".ber";
    
    len_extension = ft_strlenn(extension);
    len_file_path = ft_strlenn(file_path);
    
    if (len_file_path <= len_extension)
        return(0);
    i = 0;
    while(i < len_extension)
    {
        if (file_path[len_file_path - len_extension + i] != extension[i])
            return(0);
        i++;
    }
    return(1);
}

int ft_validate_line(char *line, t_info_map *info_map)
{
    /*
    line = 111111
    line = 101011
    line = 1EC001
    line = 111111

    - Primera y última fila tiene que ser 1
    - Resto de filas:
        1º y ultima columna tiene que ser 1
        1º y última pos de fila tiene que ser 1
    - Ver que no hay caracters no permitidos
    */
    int pos;
    pos=0;
        // printf("pos %d - line[pos] %c\n", pos, line[pos]);

    // printf("info_map->num_columns %d\n", info_map->num_columns);
    pos = info_map->num_columns - 1;
        // printf("pos %d - line[pos] %c\n", pos, line[pos]);

    if(line[0] != '1' || line[info_map->num_columns - 1] != '1')
        return(0);
    pos = 1;
    while(pos < info_map->num_columns - 1)
    {
        // printf("pos %d - line[pos] %c\n", pos, line[pos]);
        if (line[pos] != '1' && line[pos] != 'P' 
            && line[pos] != 'E' && line[pos] != 'C' && line[pos] != '0')
            return(0);
        if (line[pos] =='P')
        {
            if (info_map->player == 1)
            {
                perror("hay mas de un Player");
                return (0);
            }
            else
                info_map->player = 1;
        }
        if(line[pos] == 'E')
        {
            if(info_map->exit == 1)
            {
                perror("Hay mas de un Exit");
                return(0);
            }
            else
                info_map->exit = 1;
        }
        if(line[pos] == 'C')
            info_map->collections++;
        pos++;
    }
    /* Eliminar este codigo
    printf("a\n");
    if (info_map->map == NULL){
        info_map->map = malloc(sizeof(int));
    }else{
        char **map = malloc(sizeof(int) * (info_map->num_rows));
        int j=0;
        while(j<info_map->num_rows){
            map[j] = info_map->map[j];
            j++;
        }
        free(info_map->map);
        info_map->map = map;
    }
    printf("%s--%d\n", line, *line);
    info_map->map[info_map->num_rows] = line;
    printf("b\n");
    */
    return(1);

}
void ft_print_map(t_info_map *info_map)
{
    int i;
    i = 0;
    while (i < info_map->num_rows)
    {
        printf("%d -> %s!\n", i, info_map->map[i]);
        i++;
    }
    printf("FIN PRINT\n");
}

// En tu archivo map.c
int ft_is_only_one(char *line)
{
    int i;
    i = 0;
    while(line[i])
    {
        // Si el carácter es '\n' y es el último de la línea (antes de '\0')
        if (line[i] == '\n' && line[i + 1] == '\0')
            break; // Es el final esperado, salimos del bucle
        
        if(line[i] != '1')
            return (0); // Cualquier otro carácter que no sea '1' es un fallo
        i++;
    }
    return (1); // Si llegamos aquí, pasó la prueba.
}

int ft_readd_file(char *file_path, t_info_map *info_map)
{
    // abrir fichero
    // linea por linea , comprobar
    int     fd;
    char    *line;
    int     tmp_num_columns;
    int     ok;

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    info_map->num_rows = 0;
    while ((line = get_next_line(fd)))
    {
		printf("%s", line); //  11111111 o 10001E001
        tmp_num_columns =ft_strlenn(line);
        printf("tmp_num_columns %d --- %s\n", tmp_num_columns, line);
        // tmp_num_columns =ft_strlenn(line);
        // printf("tmp_num_columns %d --- %s\n", tmp_num_columns, line);
        //    - mismo número de columnas
        if (info_map->num_rows == 0)
        {
            info_map->num_columns = tmp_num_columns;
            // Para la última linea se Verifica después de leer el file
            // Verificando si toda la 1º linea es 1
            ok = ft_is_only_one(line); 
            if (!ok)
            {
                free(line);
                return (0);
            }
        }
        else if (info_map->num_columns != tmp_num_columns)
        {
            printf("no coincide el número de columna en la fila %d\n", info_map->num_rows+1);
            return (0);
        }
        ok = ft_validate_line(line, info_map);
        if (!ok)
        {
            free(line);
            return (0);
        }

        /* AÑADIDO*/
        // 1. Realocar espacio para un puntero char* adicional
        char **temp_map = (char **)realloc(info_map->map, sizeof(char *) * (info_map->num_rows + 1));
        if (temp_map == NULL)
        {
            perror("Error reallocating map");
            free(line);
            return (0);
        }
        info_map->map = temp_map;
        
        // 2. Guardar una COPIA de la línea. Esto previene problemas con GNL
        // Asumiendo que ft_strdup existe y funciona como strdup
        info_map->map[info_map->num_rows] = ft_strdup(line); 
        
        if (info_map->map[info_map->num_rows] == NULL)
        {
             perror("Error duplicating line");
             free(line);
             return (0);
        }
        
        // 3. Liberar la línea devuelta por GNL
        free(line); 
        line = NULL; // Buena práctica

        info_map->num_rows++;
        // guardo line en info_map->map
		// free(line);
        ft_print_map(info_map);

        line = NULL;
	}
    close(fd);
    // la 1º y la ultima fila todo 1??
    //Verificando la última fila 
    //(tiene que ser después de la lectura del file que es cuando sabemos cuantas rows hay)
    ok = ft_is_only_one(info_map->map[info_map->num_rows - 1]);
    if (!ok)
        return (0);
    printf("===============\n");
    ft_print_map(info_map);

    /*
    cuando termina verificar
    - minimo 3 filas
    - hay solo un player
    - hay solo una salida
    - hay al menos un C
    */
    // guardar la información en la estructura
    return(1);
}

void ft_init_map(t_info_map *info_map)
{
    info_map->num_columns = 0;
    info_map->num_rows = 0;
    info_map->player = 0;
    info_map->exit = 0;
    info_map->collections = 0;
    info_map->map = NULL;
}


int ft_load_map(char *file_path, t_info_map *info_map)
{
    int ok;
    //t_info_map *info_map;
    //// No hace falta malloc aquí si lo hacemos en main
    //info_map = malloc(sizeof(t_info_map));
    ft_init_map(info_map);
    // Validar file

    printf("Loazzzzzzding file %s\n", file_path);
    printf("S0000\n");
    
    ok = ft_validate_file(file_path);
    printf("nt %d\n", ok);
    if (!ok)
    {
        printf("no valid");
        return(0);
    }

    ok = ft_readd_file(file_path, info_map);
    printf("file read ? %d\n", ok);
    // Leer file 



    // Guardar map
    // 
    return (ok);
}



