#include "libft2.h"
/*
Write the following function:
int		max(int* tab, unsigned int len);
The first parameter is an array of int, the second is the number of elements in
the array.
The function returns the largest number found in the array.
If the array is empty, the function returns 0.
*/


int		max(int* tab, unsigned int len)
{
    int max_value = tab[0];  // Valor máximo inicial
    unsigned int i = 1;      // Empezamos desde el segundo elemento

    // Si el array está vacío, devolvemos 0
    if (len == 0)
        return (0);
    // Recorremos el array con while
    while (i < len) 
    {
        //Compara el elemento actual del array (tab[i]) con el valor máximo encontrado hasta ahora (max_value)
        if (tab[i] > max_value)
            //Si el valor actual es mayor, se actualiza max_value con este nuevo value
            max_value = tab[i];
        i++;
    }
    return (max_value);
}

int main()
{
	int int_tab1[] = {1, 3, 12, 10, 9};
	int int_tab2[] = {1, 3, 12, 10, 9};

	printf("%d\n", max(int_tab1, 2));
	printf("%d\n", max(int_tab2, 5));

}