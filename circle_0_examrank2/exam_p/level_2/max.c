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
    //If the array is empty, returns 0
    if (len == 0)
        return (0);
    
    int max_value = tab[0];  // Valor máximo inicial
    unsigned int i = 1;      // Empezamos desde el segundo elemento
    
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
	//int int_tab1[] = {1, 3, 12, 10, 9};
	int int_tab2[] = {1, 3, 12, 10, 9};
	//int int_tab3[] = {1, 3, 12, 10, 9};
	int int_tab4[] = {};


	//printf("%d\n", max(int_tab1, 0));
	printf("tab2: %d\n", max(int_tab2, 5));
	//printf("%d\n", max(int_tab3, 7)); //Resultado indefinido, ya que está fuera de rango
	printf("tab4: %d\n", max(int_tab4, 1));

    return(0);
}