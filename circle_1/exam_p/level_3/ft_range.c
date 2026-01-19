#include "libft3.h"
/*
Write the following function:
int *ft_range(int start, int end);
It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.
Examples
- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.

//También funciona para rangos inversos
//como ft_range(10, 5) → imprime: 10 9 8 7 6 5
*/

int	*ft_range(int start, int end)
{
	int *range;
	int size;
	int i;
	//Calculamos el tamaño del array (end - start) + 1
	size = end - start;
	if (size < 0)
		size = -size;
	size += 1;
	//Reservamos tamaño del array
	range = (int *)malloc(sizeof(int) * size);
	if(!range)
		return (NULL);
	//while para llenar el array desde start hasta end, 
	//o desde start hasta end decreciendo
	i = 0;
	while (i < size)
	{
		if (start <= end)
			range[i] = start + i;
		else
			range[i] = start - i;
		i++;
	}
	return (range);
}

int main(void)
{
	int *arrayint;

	int i = 0;
	int start = 1;
	int end = 3;

	int size = end - start;
	if (size < 0)
		size = -size;
	size += 1;

	arrayint = ft_range(start, end);
	if (!arrayint)
		return (1);

	while (i < size)
	{
		printf("%d ", arrayint[i]);
		i++;
	}
	printf("\n");
	free(arrayint);
	return (0);
}