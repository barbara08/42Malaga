#include "push_swap.h"

void ft_sort_three(int *stack_a, int size_a)
{
	if (size_a != 3)
		return;
	if (ft_is_sorted(stack_a, size_a))
		return;

	int a = stack_a[0];
	int b = stack_a[1];
	int c = stack_a[2];

	if (a > b && b < c && a < c)
		sa_swap(stack_a, size_a);
	else if (a > b && b > c)
	{
		sa_swap(stack_a, size_a);
		rra_reverse_rotate(stack_a, size_a);
	}
	else if (a > b && b < c && a > c)
		ra_rotate(stack_a, size_a);
	else if (a < b && b > c && a < c)
	{
		sa_swap(stack_a, size_a);
		ra_rotate(stack_a, size_a);
	}
	else if (a < b && b > c && a > c)
		rra_reverse_rotate(stack_a, size_a);
}

void ft_sort_five(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
	while (*size_a > 3)
		pb_push(stack_a, size_a, stack_b, size_b);
	ft_sort_three(stack_a, *size_a);
	while (*size_b > 0)
		pa_push(stack_a, size_a, stack_b, size_b);
}

//Función auxiliar para poder ordenar más de 6 elementos
void ft_index_stack(int *stack, int size)
{
	int i;
	int j;
	int *sorted = malloc(size * sizeof(int));

	// Copiar elementos
	i = 0;
	while (i < size)
	{
		sorted[i] = stack[i];
		i++;
	}
	// Ordenar (bubble sort)
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (sorted[j] > sorted[j + 1])
			{
				int tmp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	// Asignar índices
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (stack[i] == sorted[j])
			{
				stack[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
	free(sorted);
}

void ft_sort_big(int *a, int *len_a, int *b, int *len_b)
{
	int max_bits = 0;
	int max_num = *len_a - 1;
	int i = 0;

	// Calcular el número de bits necesarios
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		int j = 0;
		int size = *len_a;
		while (j < size)
		{
			if (((a[0] >> i) & 1) == 0)
				pb_push(a, len_a, b, len_b);
			else
				ra_rotate(a, *len_a);
			j++;
		}
		while (*len_b > 0)
			pa_push(a, len_a, b, len_b);
		i++;
	}
}




/* ft_sort_three
Sirve para ordenar una pila (stack) de exactamente 3 elementos con el menor número de movimientos.
Ordenar 3 números es un caso pequeño y muy común en push_swap, y se puede hacer con pocas instrucciones.
Esta función contiene la lógica para mover los elementos de forma óptima: usando solo sa, ra, rra.
Así evitas hacer algoritmos generales complejos para solo 3 números.
Se llama cuando la pila tiene 3 o menos elementos para ordenar rápido.
*/
/* ft_sort_five
Sirve para ordenar pilas de hasta 5 elementos (caso pequeño).
La estrategia típica es:
Pasar 2 números de stack_a a stack_b con la instrucción pb (push b), para reducir el problema a ordenar 3 elementos en stack_a.
Llamar a ft_sort_three para ordenar esos 3 elementos en stack_a.
Luego insertar los elementos de stack_b de vuelta a stack_a con pa, ya ordenados.
Esta es una solución común y eficiente para pilas pequeñas, y se aprovecha que ordenar 3 es sencillo.
*/
/* Resumen:
ft_sort_three: ordena rápido 3 elementos.
ft_sort_five: ordena hasta 5 elementos usando sort_three y moviendo elementos entre pilas.
Se usan para casos pequeños donde un algoritmo simple es mejor que uno complejo.
*/
/* index_stack
Porque hay que indexar
Radix Sort funciona con números binarios en rangos pequeños, y no con valores reales grandes o desordenados
El stack puede tener valores muy grandes o desordenados, por ejemplo:
stack_a = [98, 3, -42, 999, 17]

Estos números:
No están en orden ni tienen una relación directa entre sí.
Sus valores pueden ser muy altos o negativos, lo que complica compararlos bit a bit
Solución: Indexar
Convertimos los valores reales a índices ordenados, es decir:
Original:  [98, 3, -42, 999, 17]
Ordenado:  [-42, 3, 17, 98, 999]
Índices:   [  3, 1,  0,  4,   2]
sto hace que:
Los números estén todos en el rango 0 a n-1 (donde n es la cantidad de elementos).
Puedas trabajar con valores compactos y positivos.
Puedas usar Radix Sort directamente, porque funciona con bits binarios.


Ejemplo:
stack_a = [98, 3, 999, 17]

Si no indexas, tendrías que trabajar con los bits de 98, 3, 999, 17:
98   = 01100010
3    = 00000011
999  = 001111100111
17   = 00010001

Pero si indexas:
stack_a = [98, 3, 999, 17]

Los valores serán [2, 0, 3, 1] y solo necesitas trabajar con:
2 = 10
0 = 00
3 = 11
1 = 01
Número original		Índice en ordenado		Explicación
98					2						98 	es el tercer número ordenado
3					0						3 	es el primero en orden
999					3						999 es el cuarto (último)
17					1						17 	es el segundo en orden

Ahora sí, puedes aplicar Radix Sort por bits de forma clara, rápida y predecible.
*/