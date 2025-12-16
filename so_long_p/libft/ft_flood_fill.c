#include "libft.h"

typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;
char **make_area(char **zone, t_point size)
{
	//x => column;  y => row
	//3. Reservamos memory para las filas
	char **area = malloc(sizeof(char *) * (size.y + 1));
	if (area == NULL)
		return(NULL);
	//4. Recorremos la fila
	int r = 0;
	while (r < size.y)
	{
		//5. Reservamos memory para columna
		area[r] = malloc(sizeof(char) * (size.x + 1));
		if (area[r] == NULL)
			return (NULL);	
		//6. Recorremos la columna (para guardar en las filas)
		int c = 0;
		while (c < size.x)
		{
			area[r][c] = zone[r][c];
			c++;
		}
		area[r][size.x] = '\0'; //Para terminar cada string
		r++;
	}
	area[r] = NULL;  // Para terminar el array de cadenas
	return(area);
}

void print_tab(char **area)
{
	int row = 0;
	while (area[row] != NULL)
	{
		int column = 0;
		while(area[row][column] != '\0')
		{
			printf("%c", area[row][column]);
			column ++;
		}
		printf("\n");
		//ft_putchar('\n'); No sale ver el porque
		row++;
	}
}

void ft_fill(char **tab, t_point size, int y, int x)
{
    // 1. Verificar límites
    if (x < 0 || x >= size.x || y < 0 || y >= size.y)
        return;
    
    // 2. Detener si es un muro ('1') o ya fue visitado ('F').
    // Si es la salida ('E'), un coleccionable ('C'), un espacio vacío ('0') o el jugador ('P'), ¡AVANZA!
    if (tab[y][x] == '1' || tab[y][x] == 'F')
        return;

    // 3. Cambiamos la posicion actual a 'F' (Visitado)
    // No usamos la variable 'letter' porque queremos que pase por P, 0, C, y E.
    tab[y][x] = 'F';

    // 4. Llamada recursiva de la función para cada dirección (¡Descomentarlas!)
    ft_fill(tab, size, y, x + 1); // Derecha (x => column)
    ft_fill(tab, size, y + 1, x); // Abajo (y => fila)
    ft_fill(tab, size, y, x - 1); // izquierda (x => column)
    ft_fill(tab, size, y - 1, x); // Arriba (y => fila)
}

int ft_flood_fill(t_info_map *info_map)
{
    t_point size;
    t_point begin;
    char **map_copy;
    int validation_result;
    
    // 1. Configurar datos
    size.x = info_map->num_columns;
    size.y = info_map->num_rows;
    begin.x = info_map->player_x; // Coordenadas 0-basadas (CORRECTO)
    begin.y = info_map->player_y; // Coordenadas 0-basadas (CORRECTO)

    // 2. Crear COPIA del mapa
    map_copy = make_area(info_map->map, size);
    if (!map_copy)
        return (0); // Error de malloc

    // 3. Ejecutar el Flood Fill con coordenadas 0-basadas
    ft_fill(map_copy, size, begin.y, begin.x); // Usando fill(tab, size, y, x)

    // 4. Comprobar jugabilidad
    validation_result = ft_is_map_playable(map_copy, size);

    // 5. Liberar memoria
    ft_free_area(map_copy, size.y); // Asegúrate de que esta función exista
    
    return (validation_result);
}



//función que comprueba los resultados
//Si después de rellenar, aún quedan caracteres 'C' o 'E' en el mapa copiado,
//significa que el mapa no es jugable
int ft_is_map_playable(char **map_copy, t_point size)
{
    int i = 0;
    int j;
    
    while (i < size.y)
    {
        j = 0;
        while (j < size.x)
        {
            if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
            {
                // Un coleccionable o la salida no fueron alcanzados ('F')
                return (0); 
            }
            j++;
        }
        i++;
    }
    return (1); // Éxito: todos los 'C' y la 'E' fueron visitados
}

// Lógica para llamar:
/*
int validation_result = 0;
// ... (Buscar la posición del jugador 'P' y guardarla en begin)
char **area_copy = make_area(info_map->map, size);
if (area_copy)
{
    flood_fill(area_copy, size, begin);
    validation_result = ft_is_map_playable(area_copy, size);
    // ... (Liberar area_copy)
}
*/







/* Funcion original del exam_p

void fill(char **tab, t_point size, int y, int x, char letter)
{
	//tab => el área que se está rellenando
	//size => contine el num filas y num column
	//x, y => la posición actual
	//letter => caracter a reemplazar

	//1. Verificar que el area está dentro del rango
		//Si está fuera de rango no hacemos nada
	if(x < 0 || x >= size.x || y < 0 || y >= size.y)
		return;
	//2. Si la letra en la posicion actual es distinto a la letra, no hacemos nada
	printf("----%d/%d   %c\n", y, x, tab[y][x]);
	if(tab[y][x] != letter)
		return;
	//3. Cambiamos la posicion actual al caracter relleno 'F'
	tab[y][x] = 'F';
	//4. 


	//4. Llamada recursiva de la función para cada dirección (No sale)
	//fill(tab, size, y, x + 1, letter); // Derecha (x => column)
	//fill(tab, size, y + 1, x, letter); // Abajo (y => fila)
	//fill(tab, size, y, x - 1, letter); // izquierda (x => column)
	//fill(tab, size, y - 1, x, letter); // Arriba (y => fila)

}

void ft_flood_fill(char **tab, t_point size, t_point begin)
{
    // Usamos las coordenadas iniciales (y, x) restando 1.
    // Asumimos que 'begin' apunta a la posición del jugador 'P'.
    fill(tab, size, begin.y - 1, begin.x - 1);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char letter = tab[begin.y-1][begin.x-1];
	
	printf("letter en fllood_fill %c\n", letter);
	if(letter == 'F')
		return;
	fill(tab, size, begin.y - 1, begin.x - 1, letter);
}


int main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {1, 1};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10100001",
		"11000000",
	};
	printf("linea 170\n");
	area = make_area(zone, size);
	printf("linea 172\n");
	//print_tab(area); //No hace falta función auxiliar, Lo he hecho con el while
	int i = 0;
	while (i < size.y)
	{
		printf("%s\n", area[i]);
		i++;
	}
	printf("linea 180\n");
	flood_fill(area, size, begin);
	printf("linea 182\n");
	ft_putchar('\n');
	printf("linea 184\n");
	print_tab(area);
	printf("linea 186\n");
	return (0);
}

*/
