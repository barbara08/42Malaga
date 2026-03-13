#include "libft4.h"
#include "ft_list.h"
/*
Write the following functions:
t_list	*sort_list(t_list* lst, int (*cmp)(int, int));
This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.
Duplications must remain.
Inputs will always be consistent.
You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.
Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.
For example, the following function used as cmp will sort the list
in ascending order:
int ascending(int a, int b)
{
	return (a <= b);
}
    // Lo que hace la función: ordenar una lista enlazada simple (t_list)
Vamos a usar un Bubble Sort (burbuja) para listas enlazadas:
Recorrer la lista con un puntero.
Comparar el nodo actual con el siguiente usando cmp.
Si están fuera de orden (cmp(a, b) == 0), intercambiar sus valores.
Repetir hasta que no haya intercambios.
*/

/* PARA PROBAR MAIN (necesitamos las 4 funciones auxiliares)
1. ft_putnbr
2. ft_pint_list
3. ft_cmp
4. create_node
La función cmp para definir orden ascendente.
Una función auxiliar para:
    - Crear la lista enlazada manualmente.
    - Imprimir la lista (print_list).
    - Probar sort_list.
*/

// Función para imprimir un número con write
void	ft_putnbr(int n)
{
	char	c;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

// Función para imprimir la lista
void	print_list(t_list *lst)
{
	while (lst)
	{
		//Hay que castear, en la estructura está tipo void
		//debe ser tipo int, ya que son numeros enteros
		ft_putnbr((int)(intptr_t)lst->data);
		//ft_putnbr(lst->data);  sin castear
		if (lst->next)
			write(1, " -> ", 4);
		lst = lst->next;
	}
	write(1, "\n", 1);
}

// Función cmp para orden ascendente
int	ft_cmp(int a, int b)
{
	return (a <= b);
}

// Función para crear un nuevo nodo
t_list	*create_node(int data)
{
	t_list *node = malloc(sizeof(t_list));
	if (node)
	{
		//castear, ya que en la estructura es tipo void
		//hay que pasarlo a int, ya que son enteros
		node->data = (void *)(intptr_t)data;
		//node->data = data; //sin castear
		node->next = NULL;
	}
	return (node);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		sorted;
	t_list	*tmp;
	int		swap;
	if (!lst)
		return (lst);
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		tmp = lst;
		while (tmp->next)
		{
			//hay que castear, en la estructura está tipo void
			//hay que pasarlo a int, ya que son numeros enteros
			if (!cmp((int)(intptr_t)tmp->data, (int)(intptr_t)tmp->next->data))
			//if (!cmp(tmp->data, tmp->next->data)) //sin castear
			{
				// Intercambiar valores de los nodos
				swap = (int)(intptr_t)tmp->data;
				//swap = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = (void *)(intptr_t)swap;

				sorted = 0;
			}
			tmp = tmp->next;
		}
	}
	return (lst);
}

//Para main necesita las 4 funciones auxiliares
int	main(void)
{
	// Creamos nodos manualmente: 4 -> 2 -> 3 -> 1
	t_list *n1 = create_node(4);
	t_list *n2 = create_node(2);
	t_list *n3 = create_node(3);
	t_list *n4 = create_node(1);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	write(1, "Before: ", 8);
	print_list(n1);

	t_list *sorted = sort_list(n1, ft_cmp);

	write(1, "After:  ", 8);
	print_list(sorted);

	return (0);
}


