#include "push_swap.h"

int ft_atoi_validate(const char *str, int *error)
{
	long num = 0;
	int sign = 1;
	*error = 0;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
	{
		*error = 1;
		return (0);
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if ((num * sign) >= 2147483647 || (num * sign) <= -2147483648)
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	if (*str != '\0')
	{
		*error = 1;
		return (0);
	}
	return (int)(num * sign);
}

int ft_number_duplicate(int *stack, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
				return (1);  // ¡Duplicado encontrado!
			j++;
		}
		i++;
	}
	return (0);  // No hay duplicados
}

int ft_is_sorted(int *stack, int size)
{
	int i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0); // Encontró que no está ordenado
		i++;
	}
	return (1); // Está ordenado
}

void ft_print_error_and_free(int *a, int *b)
{
	write(2, "Error\n", 6);
	free(a);
	free(b);
}


//No piden esta función, la tengo para ver si los stacks están ordenados
//Falta cambiar printf por ft_printf
//Y anotarlo en el .h
void ft_print_stack(char *name, int stack[], int len)
{
	int i = 0;
	printf("%s: ", name);
	while (i < len) {
		printf("%d ", stack[i]);
		i++;
	}
	printf("\n");
}


// EXPLICACION DE LAS FUNCIONES 
/* ft_atoi_validate
El programa debe detectar errores y manejarlos mostrando "Error\n" 
y saliendo con error cuando:
El argumento no sea un número válido (por ejemplo "123abc").analizadortiene duplicados
El número esté fuera del rango de un entero (más grande que INT_MAX o menor que INT_MIN).
Hay caracteres inválidos después del número.
La función:
Devuelve un error si encuentra caracteres inválidos.
Controla el overflow para que no se salga de rango int.
Permite validar la entrada para cumplir con las especificaciones del proyecto.
Resumen: 
Detecta errores y puedes mostrar "Error\n" y salir, 
que es obligatorio para el proyecto.
*/

/* ft_number_duplicate
Detectar si hay números repetidos (duplicados) en el array stack de tamaño size.
Primero, con el índice i recorre todo el array desde 0 hasta size - 1.
Para cada elemento stack[i], con el índice j revisa los elementos que están después de i (desde i + 1 hasta size - 1).
Si encuentra que stack[i] es igual a stack[j], significa que hay un número repetido.
En ese momento retorna 1 indicando que sí hay duplicados.
Si termina de revisar todo el array sin encontrar ningún duplicado, devuelve 0.
Resumen:
La función devuelve:
1 si encuentra al menos un número repetido en el array.
0 si todos los números son únicos.
Esto sirve para validar que el stack no tenga valores duplicados.
*/
/*ft_is_sorted
La función recorre el array desde el primer elemento hasta el penúltimo.
En cada paso, compara el elemento actual stack[i] con el siguiente stack[i + 1].
Si en algún momento encuentra que un elemento es mayor que el siguiente, 
entonces el array no está ordenado de forma ascendente.
En ese caso, devuelve 0.
Si termina el recorrido sin encontrar ningún caso de desorden, devuelve 1 indicando que el array sí está ordenado.
Se usa en el programa para:
Antes de hacer cualquier operación para ordenar, comprobamos si el stack ya está ordenado.
Si ya está ordenado, no hay que imprimir instrucciones ni hacer nada, el programa termina rápido.
Esto optimiza y evita instrucciones innecesarias.
*/