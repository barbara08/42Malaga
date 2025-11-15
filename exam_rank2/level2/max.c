#include "../level.h"
/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:
int		max(int* tab, unsigned int len);
The first parameter is an array of int, the second is the number of elements in
the array.
The function returns the largest number found in the array.
If the array is empty, the function returns 0.
*/

int max(int* tab, unsigned int len)
{
	int num_max;
	unsigned int i;

	if(len == 0)
		return(0);
	
	num_max = tab[0];
	i = 1;
	while (i < len)
	{
		if(tab[i] > num_max)
			num_max = tab[i];
		i++;
	}
	return(num_max);
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