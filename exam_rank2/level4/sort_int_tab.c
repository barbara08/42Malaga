#include "../level.h"
/*
Write the following function:
void sort_int_tab(int *tab, unsigned int size);
It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.
Doubles must be preserved.
Input is always coherent.
*/

void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	int tmp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - 1)
		{
			if(tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
		j = 0;
	}
}


int main(void)
{
    int arr[] = {-5, 2, 8, 1, 0, 3, 8};
    unsigned int size = sizeof(arr) / sizeof(arr[0]);
    unsigned int i = 0;

    // Imprimir array original con while
    printf("Original array: ");
    i = 0;
    while (i < size)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");

    // Ordenar array
    sort_int_tab(arr, size);

    // Imprimir array ordenado con while
    printf("Sorted array:   ");
    i = 0;
    while (i < size)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");

    return (0);
}