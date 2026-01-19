#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// --- Operaciones básicas ---
void ra(int *a, int size)
{
    if (size < 2) return;
    int tmp = a[0];
    int i = 0;
    while (i < size - 1)
    {
        a[i] = a[i + 1];
        i++;
    }
    a[size - 1] = tmp;
	write(1, "ra\n", 3);

}

void rra(int *a, int size)
{
    if (size < 2) return;
    int tmp = a[size - 1];
    int i = size - 1;
    while (i > 0)
    {
        a[i] = a[i - 1];
        i--;
    }
    a[0] = tmp;
	write(1, "rra\n", 4);

}

void rb(int *b, int size)
{
    ra(b, size);
	write(1, "ra\n", 3);

}

void rrb(int *b, int size)
{
    rra(b, size);
	write(1, "rra\n", 4);

}

void pb(int *a, int *size_a, int *b, int *size_b)
{
    if (*size_a == 0) return;
    int i = *size_b;
    while (i > 0)
    {
        b[i] = b[i - 1];
        i--;
    }
    b[0] = a[0];
    i = 0;
    while (i < *size_a - 1)
    {
        a[i] = a[i + 1];
        i++;
    }
    (*size_a)--;
    (*size_b)++;
	write(1, "pb\n", 3);

}

void pa(int *a, int *size_a, int *b, int *size_b)
{
    if (*size_b == 0) return;
    int i = *size_a;
    while (i > 0)
    {
        a[i] = a[i - 1];
        i--;
    }
    a[0] = b[0];
    i = 0;
    while (i < *size_b - 1)
    {
        b[i] = b[i + 1];
        i++;
    }
    (*size_a)++;
    (*size_b)--;
	write(1, "pa\n", 3);

}

// --- Normalizar ---
int *normalize(int *arr, int n)
{
    int *sorted = malloc(sizeof(int) * n);
    int *normalized = malloc(sizeof(int) * n);
    int i = 0, j;
    while (i < n)
    {
        sorted[i] = arr[i];
        i++;
    }
    // Burbuja
    int swapped = 1;
    while (swapped)
    {
        swapped = 0;
        i = 0;
        while (i < n - 1)
        {
            if (sorted[i] > sorted[i + 1])
            {
                int tmp = sorted[i];
                sorted[i] = sorted[i + 1];
                sorted[i + 1] = tmp;
                swapped = 1;
            }
            i++;
        }
    }
    i = 0;
    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            if (arr[i] == sorted[j])
                normalized[i] = j;
            j++;
        }
        i++;
    }
    free(sorted);
    return normalized;
}

// --- Traer máximo de B arriba ---
int find_max_index(int *b, int size)
{
    int i = 1;
    int max = b[0];
    int idx = 0;
    while (i < size)
    {
        if (b[i] > max)
        {
            max = b[i];
            idx = i;
        }
        i++;
    }
    return idx;
}

// --- Ordenar N números ---
void chunk_sort(int *a, int *size_a, int *b, int *size_b, int n)
{
    int chunks = (n <= 100) ? 5 : 11;
    int chunk_size = n / chunks;
    int current_limit = chunk_size;
    int pushed = 0;

    // PASO 1: mover chunks a B
    while (*size_a > 0)
    {
        if (a[0] < current_limit)
        {
            pb(a, size_a, b, size_b);
            pushed++;
            // si está en la mitad inferior, lo mandamos al fondo de B
            if (b[0] < current_limit - (chunk_size / 2))
                rb(b, *size_b);
        }
        else
            ra(a, *size_a);

        // aumentamos el límite si ya movimos todo el chunk
        if (pushed == current_limit)
            current_limit += chunk_size;
    }

    // PASO 2: devolver desde B en orden
    while (*size_b > 0)
    {
        int max_i = find_max_index(b, *size_b);
        if (max_i <= *size_b / 2)
        {
            while (max_i-- > 0)
                rb(b, *size_b);
        }
        else
        {
            int x = *size_b - max_i;
            while (x-- > 0)
                rrb(b, *size_b);
        }
        pa(a, size_a, b, size_b);
    }
}

void print_stack(char *name, int *stack, int size)
{
    printf("%s: ", name);
    int i = 0;
    while (i < size)
    {
        printf("%d ", stack[i]);
        i++;
    }
    printf("\n");
}

// --- MAIN ---
int main(void)
{
    int n = 100;
    int *a = malloc(sizeof(int) * n);
    int *b = calloc(n, sizeof(int));
    int size_a = n;
    int size_b = 0;

    // Generar ejemplo aleatorio
    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000 - 500;

    int *norm = normalize(a, n);
    int i = 0;
    while (i < n)
    {
        a[i] = norm[i];
        i++;
    }
    free(norm);

    printf("Antes:\n");
    print_stack("A", a, size_a);

    chunk_sort(a, &size_a, b, &size_b, n);

    printf("\nDespués:\n");
    print_stack("A", a, size_a);

    free(a);
    free(b);
    return 0;
}
