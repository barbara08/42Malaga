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


/* ft_sort_three
Sirve para ordenar una pila (stack) de exactamente 3 elementos con el menor número de movimientos.
Ordenar 3 números es un caso pequeño y muy común en push_swap, y se puede hacer con pocas instrucciones.
Esta función contiene la lógica para mover los elementos de forma óptima: usando solo sa, ra, rra.
Así evitas hacer algoritmos generales complejos para solo 3 números.
Se llama cuando la pila tiene 3 o menos elementos para ordenar rápido.
*/
/*ft_sort_five
Sirve para ordenar pilas de hasta 5 elementos (caso pequeño).
La estrategia típica es:
Pasar 2 números de stack_a a stack_b con la instrucción pb (push b), para reducir el problema a ordenar 3 elementos en stack_a.
Llamar a ft_sort_three para ordenar esos 3 elementos en stack_a.
Luego insertar los elementos de stack_b de vuelta a stack_a con pa, ya ordenados.
Esta es una solución común y eficiente para pilas pequeñas, y se aprovecha que ordenar 3 es sencillo.
*/
/*Resumen:
ft_sort_three: ordena rápido 3 elementos.
ft_sort_five: ordena hasta 5 elementos usando sort_three y moviendo elementos entre pilas.
Se usan para casos pequeños donde un algoritmo simple es mejor que uno complejo.
*/