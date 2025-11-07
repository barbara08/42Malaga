#include "../level.h"

/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.
This function returns 1 if the given number is a power of 2, otherwise it returns 0.
Your function must be declared as follows:
int is_power_of_2(unsigned int n);
*/

int is_power_of_2(unsigned int n)
{
	if(n == 0)
		return(0);
	if(n % 2 == 0)
		n /= 2;
	return(n == 1);
}

int main() 
{
	printf("1 -> %d\n", is_power_of_2(11));   // 1
	printf("2 -> %d\n", is_power_of_2(22));   // 1
	printf("3 -> %d\n", is_power_of_2(33));   // 0
	printf("4 -> %d\n", is_power_of_2(44));   // 1
	printf("5 -> %d\n", is_power_of_2(55));   // 0
	printf("0 -> %d\n", is_power_of_2(00));   // 0

	printf("\n");

	return(0);
}
