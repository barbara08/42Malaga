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
    
    len_extension = ft_strlen(extension);
    len_file_path = ft_strlen(file_path);
    
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
    pos = 0;
    // printf("pos %d - line[pos] %c\n", pos, line[pos]);
    // printf("info_map->num_columns %d\n", info_map->num_columns);
    pos = info_map->num_columns - 1;
        // printf("pos %d - line[pos] %c\n", pos, line[pos]);
    // 1. Validar muros laterales (primera y última columna)
    if(line[0] != '1' || line[info_map->num_columns - 1] != '1')
        return(0);
    pos = 1;
    while(pos < info_map->num_columns - 1)
    {
        // 2. Validar caracteres permitidos
        // printf("pos %d - line[pos] %c\n", pos, line[pos]);
        if (line[pos] != '1' && line[pos] != 'P' 
            && line[pos] != 'E' && line[pos] != 'C' && line[pos] != '0')
            return(0);
        // 3. Gestión del Jugador ('P')
        if (line[pos] =='P')
        {
            if (info_map->player == 1)
            {
                perror("Error more than 1 Player"); //Solo Error
                return (0);
            }
            else
            {
                info_map->player = 1;
                //Cuando ft_validate_line encuentra el jugador ('P'),
                // guardamos su posición actual (pos para la columna x, 
                // y info_map->num_rows para la fila y)
                // La fila es el número de filas leídas hasta ahora
                info_map->player_start_x = pos;
                info_map->player_start_y = info_map->num_rows;
            }
        }
        // 4. Gestión de la Salida ('E')
        if(line[pos] == 'E')
        {
            if(info_map->exit == 1)
            {
                perror("Error more than 1 Exit");
                return(0);
            }
            else
            {
                info_map->exit = 1;
                // GUARDAR AQUÍ: Necesitas estas coordenadas para redibujar la E 
                // cuando P pase por encima sin finalizar el juego.
                info_map->exit_x = pos;
                info_map->exit_y = info_map->num_rows;
            }
        }
        // 5. Gestión de Coleccionables ('C')
        if(line[pos] == 'C')
            info_map->collections++;
        pos++;
    }
    /* Ver este codigo
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
//Función NO necesaria, la tengo para ver el mapa
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

// Función Auxiliar para cortar el '\n'
void ft_cut_newline(char *line)
{
    int len;

    if (!line)
        return ;
    
    // Calcula la longitud física de la CADENA, incluyendo el \n.
    // Aquí usa ft_strlen normal para saber la longitud LOGICA 
    // //y usarla para cortar la cadena.
    
    // Usamos una lógica simple: si la última posición de la cadena es '\n', la cortamos.
    len = 0;
    while (line[len])
        len++;

    // Si la última posición no-nula es '\n', la reemplazamos con '\0'.
    if (len > 0 && line[len - 1] == '\n')
        line[len - 1] = '\0';
}


int ft_is_only_one(char *line)
{
    int i;
    i = 0;
    while(line[i])
    {
        // Si el carácter es '\n' y es el último de la línea (antes de '\0')
        //if (line[i] == '\n' && line[i + 1] == '\0')
          //  break; // Es el final esperado, salimos del bucle
        
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
    char **temp_map;
    int i;

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    info_map->num_rows = 0;
    while ((line = get_next_line(fd)))
    {
		printf("%s con \n", line); //  11111111 o 10001E001
        // 1. CORTAR EL '\n' INMEDIATAMENTE.
        ft_cut_newline(line);
		printf("%s sin \n", line); //  11111111 o 10001E001

        // 2. Calcular la longitud LÓGICA
        tmp_num_columns =ft_strlen(line);
        printf("tmp_num_columns %d --- %s\n", tmp_num_columns, line);
        // tmp_num_columns =ft_strlenn(line);
        // printf("tmp_num_columns %d --- %s\n", tmp_num_columns, line);
        //    - mismo número de columnas

        // 3. Establecer/Validar la longitud del mapa
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
        /* INICIO DE LA MODIFICACIÓN: Reemplazo realloc por malloc y copia */
        
        // 1. Asignar memoria para el nuevo array de punteros (con espacio para la nueva fila)
        // El tamaño es (número actual de filas + 1) * sizeof(char *)
        temp_map = (char **)malloc(sizeof(char *) * (info_map->num_rows + 1));
        if (temp_map == NULL)
        {
            perror("Error malloc map");
            // Aquí no solo hay que liberar 'line', también el mapa existente
            i = 0;
            while(i < info_map->num_rows)
            {
                free(info_map->map[i]);
                i++;
            }
            free(info_map->map);
            free(line);
            return (0);
        }
        
        // 2. Copiar los punteros de las filas existentes al nuevo array
        // Usamos ft_memcpy (o memcpy) para copiar los punteros ya almacenados.
        // La copia se hace sobre los punteros, no sobre el contenido de las líneas.
        if (info_map->num_rows > 0)
        {
            ft_memcpy(temp_map, info_map->map, sizeof(char *) * info_map->num_rows);
            // 3. Liberar el array de punteros ANTIGUO (el que apuntaba info_map->map)
            free(info_map->map);
        }
        
        // 4. Actualizar el puntero del mapa para que apunte al nuevo array
        info_map->map = temp_map;
        
        /* FIN DE LA MODIFICACIÓN */
        
        // 5. Guardar una COPIA de la línea en la nueva posición.
        // Esto previene problemas con GNL
        // Asumiendo que ft_strdup existe y funciona como strdup
        info_map->map[info_map->num_rows] = ft_strdup(line); 
        
        if (info_map->map[info_map->num_rows] == NULL)
        {
             perror("Error duplicating line");
             free(line);
             return (0);
        }
        
        // 6. Liberar la línea devuelta por GNL
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
    //La 1º fila lo hemos verificado arriba
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
    info_map->player_start_x = 0;
    info_map->player_start_y = 0;
    info_map->exit_x = 0;
    info_map->exit_y = 0;
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
    // 1. Validar la extensión del archivo.
    ok = ft_validate_file(file_path);
    printf("nt %d\n", ok);
    if (!ok)
    {
        write(1, "Error file\n", 11);
        return(0);
    }
	// 2. Leer el archivo y validar el formato del mapa (muros, caracteres, un P, un E, coleccionables).
    ok = ft_readd_file(file_path, info_map);
	if (!ok)
    {
        write(1, "Error file\n", 11);
        return(0);
    }
    printf("file read ? %d\n", ok);
	//3. Verificar si 'P' puede alcanzar todas las 'C' y la 'E'.
    if (!ft_flood_fill(info_map))
    {
        write(1, "Error: Map is not beatable (C or E unreachable)\n", 48);
        // Debe haber una función de limpieza aquí si ft_load_map falla.
        return (0);
    }


    // Leer file 
    // Guardar map

    return (ok);
}





/* CODIGO ORIGINAL OK, PERO ESTA CON REALOC QUE NO PUEDO USAR

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
		printf("%s con \n", line); //  11111111 o 10001E001
        // 1. CORTAR EL '\n' INMEDIATAMENTE.
        ft_cut_newline(line);
		printf("%s sin \n", line); //  11111111 o 10001E001

        // 2. Calcular la longitud LÓGICA
        tmp_num_columns =ft_strlenn(line);
        printf("tmp_num_columns %d --- %s\n", tmp_num_columns, line);
        // tmp_num_columns =ft_strlenn(line);
        // printf("tmp_num_columns %d --- %s\n", tmp_num_columns, line);
        //    - mismo número de columnas

        // 3. Establecer/Validar la longitud del mapa
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

    
    cuando termina verificar
    - minimo 3 filas
    - hay solo un player
    - hay solo una salida
    - hay al menos un C
    // guardar la información en la estructura
    return(1);
}

*/

