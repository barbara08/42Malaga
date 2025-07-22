#include "libft3.h"
/*
Write the following function:
int *ft_rrange(int start, int end);
It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.
Examples:
- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/

int	*ft_rrange(int start, int end)
{
	int size;
	int *rrange;
	int i;

	// calcular tamaño absoluto del rango + 1
	if (start > end)
		size = start - end + 1;
	else
		size = end - start + 1;
	//Reservar el tamaño del array int
	rrange = (int *)malloc(size * sizeof(int));
	if (!rrange)
		return (NULL);
	//Se llena el array desde end hacia start, 
	//incrementando o decrementando según corresponda
	i = 0;
	while(i < size)
	{
		rrange[i] = end;
		if(end < start)
			end++;
		else
			end--;
		i++;
	}
	return (rrange);
}
//FUNCION PARA PROBAR EL MAIN

// Función para imprimir un número entero con write
void	ft_putnbr(int n)
{
    char c;

    if (n == -2147483648) // límite de int
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

int main(void)
{
	int start = -1;
	int end = 2;
	int *arrayint;
	int size = 0;
	int i;

	if (start > end)
		size = start - end + 1;
	else
		size = end - start + 1;

	arrayint = ft_rrange(start, end);
	if (!arrayint)
		return (1);

	i = 0;
	while (i < size)
	{
		ft_putnbr(arrayint[i]);
		write(1, " ", 1);
		i++;
	}
	free(arrayint);
	return (0);
}