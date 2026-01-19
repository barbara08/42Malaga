#include "ft_list.h"
#include "libft3.h"
/* 
Write a function that returns the number of elements in the linked list that's
passed to it.
It must be declared as follows:
int	ft_list_size(t_list *begin_list);
You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/

// Función que cuenta el número de elementos en la lista
int	ft_list_size(t_list *begin_list)
{
	int num_elements = 0;
	while(begin_list)
	{
		begin_list = begin_list->next;
		num_elements++;
	}
	return(num_elements);
}
//FUNCION PARA PROBAR MAIN

// Crea un nuevo nodo
t_list *create_node(void *data)
{
	t_list *new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

int main(void)
{
	// Crear nodos de ejemplo
	t_list *node1 = create_node("Hola");
	t_list *node2 = create_node("Mundo");
	t_list *node3 = create_node("!");
	t_list *node4 = create_node("!");


	// Enlazar nodos
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;


	// Usar la función
	int size = ft_list_size(node1);
	printf("El tamaño de la lista es: %d\n", size);

	// Liberar memoria
	free(node4);
	free(node3);
	free(node2);
	free(node1);

	return (0);
}