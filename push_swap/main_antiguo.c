#include "push_swap.h"


//Para ejecutar (con wc -l saldrá la cantidad de movimientos)
// ./push_swap números | wc -l

/*  100 números aleatorios en menos de 700
operaciones

500 números aleatorios, no
deberás superar las 5500 operaciones
*/

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0); // No argumentos, no imprimir nada

	int *stack_a;
	int size_a = argc - 1;
	int *stack_b;
	int size_b = 0;
	int i;
	int error = 0;

	stack_a = (int *)malloc(sizeof(int) * size_a);
	if (!stack_a)
		return 1;
	stack_b = (int *)malloc(sizeof(int) * size_a);
	if (!stack_b)
	{
		free(stack_a);
		return (1);
	}

	// Convertir argv a int con validación
	i = 0;
	while (i < size_a)
	{
		stack_a[i] = ft_atoi_validate(argv[i + 1], &error);
		if (error)
		{
			//ft_putstr_fd("Error\n", 2);
			write(2, "Error\n", 6);
			free(stack_a);
			free(stack_b);
			return (1);
		}
		i++;
	}

	// Duplicados
	if (ft_number_duplicate(stack_a, size_a))
	{
		//ft_putstr_fd("Error\n", 2);
		write(2, "Error\n", 6);  //El 2 es para los errores
		free(stack_a);
		free(stack_b);
		return (1);
	}

	// Si ya está ordenado no hace nada
	if (ft_is_sorted(stack_a, size_a))
	{
		free(stack_a);
		free(stack_b);
		return (0);
	}

	// Ordenación de: 
	//hasta 3 elementos, hasta 5 elementos y a partir del 6º elemento
	if (size_a <= 3)
		ft_sort_three(stack_a, size_a);
	else if (size_a <= 5)
		ft_sort_five(stack_a, &size_a, stack_b, &size_b);
	else
	{
		ft_index_stack(stack_a, size_a);
		ft_sort_big(stack_a, &size_a, stack_b, &size_b);
	}

	free(stack_a);
	free(stack_b);
	return (0);
}

/*
write(0, "Error\n", 6); 
0 es stdin (entrada estándar)

write(1, "Error\n", 6); 
1 es stdout (salida estándar, la consola normal)

write(2, "Error\n", 6); 
2 es stderr (salida de errores)
*/