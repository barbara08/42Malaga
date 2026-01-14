
#include "push_swap.h"

//EXPLICACION LINEA POR LINEA solo con 2 Nodos

// Definición de la estructura del nodo
typedef struct Nodo
{
    int data;  //almacenará un número entero
	//Define un puntero llamado next que apunta a otro nodo de tipo struct Nodo.
	//Esto es la clave para crear la lista enlazada, porque cada nodo apunta al siguiente
    struct Nodo *next;  
} Nodo;  //alias Nodo para struct Nodo, para no tener que escribir struct Nodo todo el tiempo

int main()
{
	//Declara un puntero a Nodo llamado lista y lo inicializa en NULL.
	//Este puntero representará el comienzo de la lista. Al principio la lista está vacía.
    Nodo *list = NULL;  // Aquí se crea la list (puntero al primer nodo)

    // Crear el primer nodo
	//Reserva memoria en el heap para un nuevo nodo. 
	//malloc devuelve un puntero a esa memoria. 
	//Se castea (Nodo *) para indicar que ese puntero es del tipo Nodo *
    list = (Nodo *)malloc(sizeof(Nodo));
    list->data = 10; //Asigna el valor 10 al campo dato del primer nodo
    list->next = NULL;  //Como es el primer nodo, no hay un siguiente, así que apunta a NULL

    // Agregar otro nodo
    Nodo *new = (Nodo *)malloc(sizeof(Nodo)); //Reserva memoria para un segundo nodo y crea un puntero nuevo para apuntar a él
    new->data = 20;  //Asigna el valor 20 al campo dato del nuevo nodo
    new->next = NULL; //El nuevo nodo será el último de la lista, así que apunta a NULL

    // Enlazar el new nodo al final
	//Enlaza el primer nodo con el segundo nodo. 
	//El campo siguiente del primer nodo apunta ahora al segundo nodo.
    list->next = new;

    // Imprimir datas
    Nodo *actual = list; //Declara un puntero actual para recorrer la lista, comenzando desde el primer nodo
	// Inicia un bucle que se repite mientras actual no sea NULL, es decir, mientras haya nodos por recorrer.
    while (actual != NULL)
	{
        printf("%d\n", actual->data); //Imprime el dato del nodo actual
        actual = actual->next;  //Avanza el puntero al siguiente nodo
    }

    // Liberar memoria (importante)
	//Comienza un bucle para liberar la memoria de todos los nodo
    while (list != NULL)
	{
        Nodo *temp = list;   //Guarda el nodo actual en temp
        list = list->next;  //Avanza list al siguiente nodo
        free(temp);  //Libera la memoria del nodo guardado en temp
    }

    return (0);
}

//EXPLICACION LINEA POR LINEA con más de 4 Nodos
