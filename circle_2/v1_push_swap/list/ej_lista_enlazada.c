#include "push_swap.h"

typedef struct Nodo
{
    int data;
    struct Nodo *next;
} Nodo;

int main()
{
	//1. Crear la lista
    Nodo *list = NULL;

    //2. Crear el primer nodo (1)
    list = (Nodo *)malloc(sizeof(Nodo));
    list->data = 10;
    list->next = NULL;

    //3. Agregar otro nodo (2)
    Nodo *new2 = (Nodo *)malloc(sizeof(Nodo));
    new2->data = 20;
    new2->next = NULL;
	// Enlazar el new nodo al final
    list->next = new2;

	//4. Agregar otro nodo (3)
	Nodo *new3 = (Nodo *)malloc(sizeof(Nodo));
	new3->data = 30;
	new3->next = NULL;
	
	Nodo *actual = list;
    while (actual->next != NULL)
	{
        actual = actual->next;
    }
	// Enlazar el nuevo nodo al final
    actual->next = new3;

	//5. Agregar otro nodo (4)
	Nodo *new4 = (Nodo *)malloc(sizeof(Nodo));
	new4->data = 40;
	new4->next = NULL;

	actual = list;
    while (actual->next != NULL)
	{
        actual = actual->next;
    }
    actual->next = new4;

	//6. Agregar otro nodo (5)
	Nodo *new5 = (Nodo *)malloc(sizeof(Nodo));
	new5->data = 50;
	new5->next = NULL;

	actual = list;
    while (actual->next != NULL)
	{
        actual = actual->next;
    }
    actual->next = new5;
	
    // Imprimir datas
    actual = list;
    while (actual != NULL)
	{
        printf("%d\n", actual->data);
        actual = actual->next;
    }

    // Liberar memoria (importante)
    while (list != NULL)
	{
        Nodo *temp = list;
        list = list->next;
        free(temp);
    }
    return (0);
}
