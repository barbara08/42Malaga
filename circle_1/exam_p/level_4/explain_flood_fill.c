#include "libft4.h"
#include "flood_fill.h"

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
