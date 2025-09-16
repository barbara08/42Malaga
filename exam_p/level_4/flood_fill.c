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
	char **area = malloc(sizeof(char *) * size.y);
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


int main(void)
{
	char **area;
	t_point size = {8, 5};
	//t_point begin = {2, 2};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};
	area = make_area(zone, size);
	//print_tab(area); //No hace falta función auxiliar, Lo he hecho con el while
	int i = 0;
	while (i < size.y)
	{
		printf("%s\n", area[i]);
		i++;
	}
	//flood_fill(area, size, begin);
	ft_putchar('\n');
	print_tab(area);
	return (0);
}






// -------------------------------------------- 
//MAIN OK
int xxmain(){
	char **area;
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};
	printf("%s", zone[1]);
	printf("\n");
	//Hay que calcular cuantas filas hay que no lo sabemos
	int num_filas = sizeof(zone) / sizeof(zone[0]);
	int num_columnas = strlen(zone[1]);

	printf("hay %d filas y %d columnas", num_filas, num_columnas);
	area = malloc(sizeof(char) * num_filas);

	int fila = 0;
	// while (zone[fila] != '\0'){. mmirar como hacerlo
	while (fila<5){
		printf("%d zone %s",fila, zone[fila]);
		printf("\n");
		char *col;
		col = malloc(sizeof(char) * num_columnas);
		for (int i = 0; i<num_columnas; i++){
			col[i] = zone[fila][i];
		}
		area[fila] = col;
		fila++;
	}
	print_tab(area);
	return 0;
}
// -------------------------------------------- 

/* OTROS EJEMPLOS, PRUEBAS, OK

int xmain()
{
	char **area;
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};
	area = make_area(zone);
	return(0);
}

int main__de_string_a_lista(){
	char columna[]="1234";
	printf("col: %s", columna);
	printf("\n");

	char *col;
	int size =  strlen(columna);
	printf("size: %d", size);
	
	printf("\n");
	col = malloc(sizeof(char) * size);

	if (col==NULL){
		printf("ERRRR");
		return 1;
	}

	for (int i=0; i<size; i++){
		printf("-i %d", i);
		printf("-c %c", columna[i]);
	printf("\n");
		col[i] = columna[i];
	}

	printf("\n");
	printf("col: %s", col);

	printf("\n");
	free(col);
	return 0;
}
// -------------------------------------------- 

FUNCION OK, SIN USAR LISTAS
CON SU MAIN

char **make_area(char **zone, int num_rows)
{
	//1. Calcular cuantas filas hay => Si pasamos por parámetro int num_rows no hace falta calcularlo
	//Para calcularlo =ª zone debe terminar en NULL (eso no se pide en el subject)
	//int num_rows = 0;
	//while (zone[num_rows] != NULL)
		//num_rows++; // no sirve si lo pasamos por parametro
	//2. Calcular cuantas columnas hay
	int num_columns = ft_strlen(zone[0]);
	//3. Reservamos memory para las filas
	char **area = malloc(sizeof(char *) * (num_rows + 1));
	if (area == NULL)
		return(NULL);
	//4. Recorremos la fila
	int r = 0;
	while (r < num_rows)
	{
		//5. Reservamos memory para columna
		//char *total_columns = malloc(sizeof(char) * num_columns + 1); NO FUNCIONA
		area[r] = malloc(sizeof(char) * (num_columns + 1));
		if (area[r] == NULL)
			return (NULL);	
		//6. Recorremos la columna (para guardar en las filas)
		int c = 0;
		while (c < num_columns)
		{
			area[r][c] = zone[r][c];
			c++;
		}
		area[r][c] = '\0'; //Para terminar cada string
		r++;
	}
	area[r] = NULL;  // Para terminar el array de cadenas
	return(area);
}

int main()
{
char **area;
	//t_point size = {8, 5};
	//t_point begin = {2, 2};
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};
	int num_rows = sizeof(zone) / sizeof(zone[0]);
	area = make_area(zone, num_rows);
	print_tab(area);
	//flood_fill(area, size, begin);
	ft_putchar('\n');
	print_tab(area);
	return (0);
}
*/
