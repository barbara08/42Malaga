#include "push_swap.h"

/*
pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack a.
	No hace nada si b está vacío.
pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack b.
	No hace nada si a está vacío.
*/

void pa(int a[], int *len_a, int b[], int *len_b)
{
    if (*len_b > 0)
    {
        int i = *len_a;

        // Mover A hacia abajo (desde len_a hasta 1)
        while (i > 0)
        {
            a[i] = a[i - 1];
            i--;
        }

        // Copiar el primer elemento de B a A
        a[0] = b[0];

        // Mover B hacia arriba (desde 0 hasta len_b-2)
        i = 0;
        while (i < *len_b - 1)
        {
            b[i] = b[i + 1];
            i++;
        }

        (*len_a)++;
        (*len_b)--;

        write(1, "pa\n", 3);
    }
}

void pb(int a[], int *len_a, int b[], int *len_b)
{
    if (*len_a > 0)
    {
        int i = *len_b;

        // Mover B hacia abajo (desde len_b hasta 1)
        while (i > 0)
        {
            b[i] = b[i - 1];
            i--;
        }

        // Copiar el primer elemento de A en B
        b[0] = a[0];

        // Mover A hacia arriba (desde 0 hasta len_a-2)
        i = 0;
        while (i < *len_a - 1)
        {
            a[i] = a[i + 1];
            i++;
        }

        (*len_b)++;
        (*len_a)--;

        write(1, "pb\n", 3);
    }
}


/*

int main()
{
	int a[10] = {1, 2, 3};
	int b[10] = {4, 5};
	int len_a = 3;
	int len_b = 2;

	printf("\nStacks pa y pb original:\n");
	ft_print_stack('a', a, len_a);
	ft_print_stack('b', b, len_b);

	pa(a, &len_a, b, &len_b); // mueve 4 de b a a

	printf("\nDespués de pa:\n");
	ft_print_stack('a', a, len_a);
	ft_print_stack('b', b, len_b);

	pb(a, &len_a, b, &len_b); // mueve 4 de a a b

	printf("\nDespués de pb:\n");
	ft_print_stack('a', a, len_a);
	ft_print_stack('b', b, len_b);

	return (0);
}
*/


