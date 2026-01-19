#include "../level.h"

/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:
int     *ft_rrange(int start, int end);
It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.
Examples:
- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

int *ft_rrange(int start, int end)
{
	int size;
	int *rrange;
	int i;

	size = end - start;
	if(size < 0)
		size = -size;
	size += 1;

	rrange = (int *)malloc(sizeof(int) * size);
	if(!rrange)
		return(NULL);
	
	i = 0;
	while(i < size)
	{
		if (start <= end)
			rrange[i] = end - i;
		else
			rrange[i] = end + i;
		i++;
	}
	return(rrange);
}

int main(void)
{
	int *arrayint;

	int i = 0;
	int start = -3;
	int end = -3;

	int size = end - start;
	if (size < 0)
		size = -size;
	size += 1;

	arrayint = ft_rrange(start, end);
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