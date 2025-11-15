#include "push_swap.h"


void ft_sort_three(int *stack_a, int size_a)
{
	if (size_a != 3)
		return;
	if (ft_is_sorted(stack_a, size_a))
		return;

	int a = stack_a[0];
	int b = stack_a[1];
	int c = stack_a[2];

	if (a > b && b < c && a < c)
		sa_swap(stack_a, size_a);
	else if (a > b && b > c)
	{
		sa_swap(stack_a, size_a);
		rra_reverse_rotate(stack_a, size_a);
	}
	else if (a > b && b < c && a > c)
		ra_rotate(stack_a, size_a);
	else if (a < b && b > c && a < c)
	{
		sa_swap(stack_a, size_a);
		ra_rotate(stack_a, size_a);
	}
	else if (a < b && b > c && a > c)
		rra_reverse_rotate(stack_a, size_a);
}


void ft_sort_five(int *a, int *size_a, int *b, int *size_b)
{
    int min, i, min_index, j;
    while (*size_a > 3)
    {
        min = a[0];
        min_index = 0;
        for (i = 1; i < *size_a; i++)
        {
            if (a[i] < min)
            {
                min = a[i];
                min_index = i;
            }
        }
        if (min_index <= *size_a / 2)
        {
            for (j = 0; j < min_index; j++)
                ra_rotate(a, *size_a);
        }
        else
        {
            for (j = min_index; j < *size_a; j++)
                rra_reverse_rotate(a, *size_a);
        }
        pb_push(a, size_a, b, size_b);
    }
    ft_sort_three(a, *size_a);
    while (*size_b > 0)
        pa_push(a, size_a, b, size_b);

}



int get_chunk_size(int total)
{
    if (total <= 100)
        return 20;       // para ~700-900 movimientos
    else if (total <= 500)
        return 45;       // para ~5500 movimientos
    else
        return 100;      // ajustable para stacks más grandes
}

int find_max_index(int b[], int len_b)
{
    int max = b[0];
    int idx = 0;
    for (int i = 1; i < len_b; i++)
    {
        if (b[i] > max)
        {
            max = b[i];
            idx = i;
        }
    }
    return idx;
}


void push_back_to_a(int a[], int *len_a, int b[], int *len_b)
{
    while (*len_b > 0)
    {
        int max_idx = find_max_index(b, *len_b);

        if (max_idx <= *len_b / 2)
            while (max_idx-- > 0)
                rb_rotate(b, *len_b);
        else
        {
            int moves = *len_b - max_idx;
            while (moves-- > 0)
                rrb_reverse_rotate(b, *len_b);
        }

        pa_push(a, len_a, b, len_b);
    }
}

void push_chunk_to_b(int a[], int *len_a, int b[], int *len_b, int sorted[], int chunk_size, int total)
{
    int min_chunk, max_chunk;

    for (int c = 0; c * chunk_size < total; c++)
    {
        min_chunk = c * chunk_size;
        max_chunk = (c + 1) * chunk_size - 1;
        if (max_chunk >= total)
            max_chunk = total - 1;

        int i = 0;
        while (i < *len_a)
        {
            if (a[i] >= sorted[min_chunk] && a[i] <= sorted[max_chunk])
            {
                // Rotación mínima en a
                if (i <= *len_a / 2)
                    while (i-- > 0)
                        ra_rotate(a, *len_a);
                else
                {
                    int moves = *len_a - i;
                    while (moves-- > 0)
                        rra_reverse_rotate(a, *len_a);
                }

                pb_push(a, len_a, b, len_b);

                // Rotación estratégica en b: colocar los más pequeños abajo
                if (*len_b > 1 && b[0] < sorted[min_chunk + chunk_size / 2])
                    rb_rotate(b, *len_b);

                i = 0;
            }
            else
                i++;
        }
    }
}

void sort_large(int *a, int *len_a, int *b, int *len_b, int total)
{
    int *sorted = (int *)malloc(sizeof(int) * total);
    if (!sorted)
        return;

    for (int i = 0; i < total; i++)
        sorted[i] = a[i];

    // Ordenación simple para crear chunks
    int swapped = 1;
    while (swapped)
    {
        swapped = 0;
        for (int i = 0; i < total - 1; i++)
        {
            if (sorted[i] > sorted[i + 1])
            {
                int tmp = sorted[i];
                sorted[i] = sorted[i + 1];
                sorted[i + 1] = tmp;
                swapped = 1;
            }
        }
    }

    int chunk_size = get_chunk_size(total);

    push_chunk_to_b(a, len_a, b, len_b, sorted, chunk_size, total);
    push_back_to_a(a, len_a, b, len_b);

    free(sorted);
}









// --------------------

/* 
int find_max_index(int b[], int len_b)
{
    int max = b[0];
    int idx = 0;
    for (int i = 1; i < len_b; i++)
    {
        if (b[i] > max)
        {
            max = b[i];
            idx = i;
        }
    }
    return idx;
}


void push_chunk_to_b(int a[], int *len_a, int b[], int *len_b, int sorted[], int chunk_size, int total)
{
    int min_chunk, max_chunk;

    for (int c = 0; c * chunk_size < total; c++)
    {
        min_chunk = c * chunk_size;
        max_chunk = (c + 1) * chunk_size - 1;
        if (max_chunk >= total)
            max_chunk = total - 1;

        int i = 0;
        while (i < *len_a)
        {
            // Si el elemento pertenece al chunk actual
            if (a[i] >= sorted[min_chunk] && a[i] <= sorted[max_chunk])
            {
                // Rotación mínima hacia cima o fondo
                if (i <= *len_a / 2)
                    while (i-- > 0)
                        ra_rotate(a, *len_a);
                else
                {
                    int moves = *len_a - i;
                    while (moves-- > 0)
                        rra_reverse_rotate(a, *len_a);
                }

                // Push a b
                pb_push(a, len_a, b, len_b);

                // Colocar en b estratégicamente: si es menor que la mitad del chunk → rrb
                if (*len_b > 1 && b[0] < sorted[min_chunk + chunk_size / 2])
                    rb_rotate(b, *len_b);

                i = 0; // reiniciar índice
            }
            else
                i++;
        }
    }
}

void push_back_to_a(int a[], int *len_a, int b[], int *len_b)
{
    while (*len_b > 0)
    {
        int max_idx = find_max_index(b, *len_b);

        if (max_idx <= *len_b / 2)
            while (max_idx-- > 0)
                rb_rotate(b, *len_b);
        else
        {
            int moves = *len_b - max_idx;
            while (moves-- > 0)
                rrb_reverse_rotate(b, *len_b);
        }

        pa_push(a, len_a, b, len_b);
    }
}

void sort_large(int *a, int *len_a, int *b, int *len_b, int total)
{
    int *sorted = (int *)malloc(sizeof(int) * total);
    if (!sorted)
        return;

    for (int i = 0; i < total; i++)
        sorted[i] = a[i];

    // Ordenar para crear chunks
    int swapped = 1;
    while (swapped)
    {
        swapped = 0;
        for (int i = 0; i < total - 1; i++)
        {
            if (sorted[i] > sorted[i + 1])
            {
                int tmp = sorted[i];
                sorted[i] = sorted[i + 1];
                sorted[i + 1] = tmp;
                swapped = 1;
            }
        }
    }

    int chunk_size = 20; // 100 números → 5 chunks

    push_chunk_to_b(a, len_a, b, len_b, sorted, chunk_size, total);
    push_back_to_a(a, len_a, b, len_b);

    free(sorted);
}


*/




// -----------------------

/* 
int find_chunk_index(int value, int sorted[], int chunk_size, int total)
{
    for (int i = 0; i < total; i += chunk_size)
    {
        int end = i + chunk_size - 1;
        if (end >= total)
            end = total - 1;
        if (value <= sorted[end])
            return i / chunk_size;
    }
    return (total - 1) / chunk_size;
}


void push_chunk_to_b(int a[], int *len_a, int b[], int *len_b, int sorted[], int chunk_size, int total)
{
    int moved = 1;

    while (moved && *len_a > 0)
    {
        moved = 0;
        for (int i = 0; i < *len_a; i++)
        {
            int chunk_index = find_chunk_index(a[i], sorted, chunk_size, total);

            if (chunk_index == 0) // mover el primer chunk
            {
                // Elegir rotación mínima
                if (i <= *len_a / 2)
                {
                    while (i-- > 0)
                        ra_rotate(a, *len_a);
                }
                else
                {
                    int moves = *len_a - i;
                    while (moves-- > 0)
                        rra_reverse_rotate(a, *len_a);
                }

                pb_push(a, len_a, b, len_b);
                moved = 1;
                break; // reevaluar stack después del push
            }
        }
    }
}


int find_max_index(int b[], int len_b)
{
    int max = b[0];
    int idx = 0;
    for (int i = 1; i < len_b; i++)
    {
        if (b[i] > max)
        {
            max = b[i];
            idx = i;
        }
    }
    return idx;
}

void push_back_to_a(int a[], int *len_a, int b[], int *len_b)
{
    while (*len_b > 0)
    {
        int max_idx = find_max_index(b, *len_b);

        if (max_idx <= *len_b / 2)
        {
            while (max_idx-- > 0)
                rb_rotate(b, *len_b);
        }
        else
        {
            int moves = *len_b - max_idx;
            while (moves-- > 0)
                rrb_reverse_rotate(b, *len_b);
        }

        pa_push(a, len_a, b, len_b);
    }
}



void sort_large(int *a, int *len_a, int *b, int *len_b, int total)
{
    int *sorted = (int *)malloc(sizeof(int) * total);
    if (!sorted)
        return;

    // Copiar y ordenar el stack
    for (int i = 0; i < total; i++)
        sorted[i] = a[i];

    // Bubble sort para preparar chunks
    int swapped = 1;
    while (swapped)
    {
        swapped = 0;
        for (int i = 0; i < total - 1; i++)
        {
            if (sorted[i] > sorted[i + 1])
            {
                int tmp = sorted[i];
                sorted[i] = sorted[i + 1];
                sorted[i + 1] = tmp;
                swapped = 1;
            }
        }
    }

    // Determinar tamaño del chunk según total de elementos
    int chunk_size;
    if (total <= 100)
        chunk_size = 5;   // pequeño stack, chunks más pequeños
    else if (total <= 500)
        chunk_size = 20;  // grande, chunks medianos
    else
        chunk_size = 50;  // muy grande, chunks grandes

    push_chunk_to_b(a, len_a, b, len_b, sorted, chunk_size, total);
    push_back_to_a(a, len_a, b, len_b);

    free(sorted);
}


*/


