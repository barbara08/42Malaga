#include "libft4.h"
#include "flood_fill.h"

/*
Expected files   : *.c, *.h
Allowed functions: -

Write a function that takes a char ** as a 2-dimensional array of char, a 
t_point as the dimensions of this array and a t_point as the starting point.
Starting from the given 'begin' t_point, this function fills an entire zone 
by replacing characters inside with the character 'F'. A zone is an group of 
the same character delimitated horizontally and vertically by other characters
or the array boundry.
The flood_fill function won't fill diagonally.
The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);
The t_point structure is prototyped like this:
  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;
Example:
$> cat test_main.c
#include "test_functions.h"
#include "flood_fill.h"
int main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	}
	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	putc('\n');
	print_tab(area);
	return (0);
}
$> gcc flood_fill.c test_main.c test_functions.c -o flood_fill; ./flood_fill
1 1 1 1 1 1 1 1
1 0 0 0 1 0 0 1
1 0 0 1 0 0 0 1
1 0 1 0 0 0 0 1
1 1 0 0 0 0 0 0

1 1 1 1 1 1 1 1
1 F F F 1 0 0 1
1 F F 1 0 0 0 1
1 F 1 0 0 0 0 1
1 1 0 0 0 0 0 0
$> 
*/
int ft_strlen(char *str)
{
	int len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return(len);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

// **zone o *zone[] (es lo mismo)
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
		"10110001",
		"11100001",
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




