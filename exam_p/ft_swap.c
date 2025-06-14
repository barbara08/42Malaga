#include <unistd.h>
#include <stdio.h>
/*
Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.
Your function must be declared as follows:

void	ft_swap(int *a, int *b);
*/

void	ft_swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    int a = 8;
    int b = 9;
    ft_swap(&a, &b);
    printf("ft_swap: %d %d", a, b);
    return(0);
}