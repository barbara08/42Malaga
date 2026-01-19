#include "libft4.h"
#include "../level_2/libft2.h"  //para usar función ft_strdup
#include "ft_list.h"  //Donde esta la estructura
/*
Write a function that takes a list and a function pointer, and applies this
function to each element of the list.
It must be declared as follows:
void    ft_list_foreach(t_list *begin_list, void (*f)(void *));
The function pointed to by f will be used as follows:
(*f)(list_ptr->data);
You must use the following structure, and turn it in as a file called
ft_list.h:
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
La función ft_list_foreach recorre una lista enlazada y aplica una función a cada uno de los elementos de la lista.
Esta función recorre toda una lista enlazada y aplica una función a los datos de cada nodo, siempre que esos datos no sean NULL
*/

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list != NULL)
	{
		if (begin_list->data != NULL)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

//Función auxiliar para probar main
void ft_putstr(void *data)
{
    char *str = (char *)data;
    while(*str)
        write(1, str++, 1);
    write(1, "\n", 1); //Si queremos poner \n
}

// Función para crear un nuevo nodo para probar main
t_list	*create_node(char *str)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = ft_strdup(str); // copiamos el string
	node->next = NULL;
	return (node);
}
//OJO.   PARA COMPILAR
//cc -Wall -Wextra -Werror ft_list_foreach.c ../level_2/ft_strdup.c
int	main(void)
{
	// Crear nodos
	t_list *node1 = create_node("Hola");
	t_list *node2 = create_node("mundo");
	t_list *node3 = create_node("desde C");

	// Enlazar nodos
	node1->next = node2;
	node2->next = node3;

	// Llamar a la función foreach con ft_putstr
	ft_list_foreach(node1, &ft_putstr);

	// Liberar memoria (opcional pero recomendado)
	free(node1->data);
	free(node1);
	free(node2->data);
	free(node2);
	free(node3->data);
	free(node3);

	return (0);
}


/* EXPLICACIÓN ft_putstr de porque void
void *data
El uso de void * permite pasar cualquier tipo de dato a la función.
Es un puntero genérico, es decir, no tiene un tipo específico hasta que tú lo conviertes (con un cast).
En listas genéricas como las de libft, los nodos guardan void *data para poder almacenar strings, números, structs, etc.
En este caso, sabemos que lo que se está pasando es un string (char *), así que dentro de la función lo convertimos.
char *str = (char *)data
//Hacemos un cast: convertimos data (que es void *) en char *.
//Es necesario porque no puedes usar aritmética de punteros (*, ++) sobre un void *.
//Ahora str apunta al string real que queremos imprimir.
*/

/*EXPLICACION create_node
Lo que hace:
Crea un nuevo nodo de una lista enlazada (estructura t_list)
Guarda dentro del nodo una copia del string str.
Devuelve un puntero al nuevo nodo.

node->data = ft_strdup(str)
Aquí copiamos el contenido del string str dentro del campo data del nodo,
Así, el nodo tiene su propia copia del string (no solo una referencia al original)
Esto es más seguro porque evita problemas si el string original cambia o se libera después.

node->next = NULL
Inicializa el campo next con NULL, indicando que este nodo no apunta a ningún otro nodo todavía.
Luego se podrá enlazar manualmente con otro nodo si estammos construyendo una lista.
*/

/*EXPLICACION FUNCIÓN ft_list_foreach
t_list *begin_list: es un puntero al primer nodo de una lista enlazada 
(asumimos que t_list es una estructura con al menos un campo void *data 
y un puntero al siguiente nodo, t_list *next
void (*f)(void *): es un puntero a una función que toma un void * como argumento y no devuelve nada. 
Esta función será aplicada a los datos de cada nodo.

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    //ecorrerá la lista mientras begin_list no sea NULL, es decir, mientras no se haya llegado al final de la lista.
	while (begin_list != NULL)
	{
        //Antes de aplicar la función, se verifica que el campo data del nodo actual no sea NULL.
        //Esta verificación es opcional, pero se hace para evitar aplicar la función a datos inexistentes o vacíos
		if (begin_list->data != NULL)
            //Aquí se llama a la función f, pasándole como argumento begin_list->data, 
            //es decir, los datos almacenados en el nodo actual.
			(*f)(begin_list->data);
        //Se avanza al siguiente nodo de la lista. Así se repite el proceso para todos los elementos
		begin_list = begin_list->next;
	}
}
*/