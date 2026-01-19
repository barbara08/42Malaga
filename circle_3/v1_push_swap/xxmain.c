#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_atoi_validate(const char *str, int *error)
{
	long num = 0;
	int sign = 1;
	*error = 0;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
	{
		*error = 1;
		return (0);
	}
	while (*str >= '0' && *str <= '9')
    {
		num = num * 10 + (*str - '0');
		if ((num * sign) > 2147483647 || (num * sign) < -2147483648)
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	if (*str != '\0')
	{
		*error = 1;
		return (0);
	}
	return (int)(num * sign);
}

int ft_number_duplicate(int *stack, int size)
{
	int i = 0;
	while (i < size)
	{
		int j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
				return (1);  // ¡Duplicado encontrado!
			j++;
		}
		i++;
	}
	return (0);  // No hay duplicados
}

int ft_is_sorted(int *stack, int size)
{
	int i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0); // Encontró que no está ordenado
		i++;
	}
	return (1); // Está ordenado
}

void print_error_and_free(int *a, int *b)
{
	write(2, "Error\n", 6);
	free(a);
	free(b);
}
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
}

void rb(int *b, int size)
{
    ra(b, size);
}

void rrb(int *b, int size)
{
    rra(b, size);
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

// --- Mostrar pila ---
void printstack(char *name, int *stack, int size)
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
int main(int argc, char **argv)
{
	/*
    int n = 10;
    int a[10] = {37, 2, 19, 8, 25, 4, 15, 99, 1, 42};
    int b[10] = {0};
    int size_a = n;
    int size_b = 0;
	*/

		////

	if (argc < 2)
		return (0);

	int size_a = argc - 1;
	int size_b = 0;
	int n = size_a;

	int *a = (int *)malloc(sizeof(int) * size_a);
	if (!a)
		return (1);

	int *b = (int *)malloc(sizeof(int) * size_a);
	if (!b)
	{
		free(a);
		return (1);
	}

	int error = 0;
	int i = 0;
	while (i < size_a)
	{
		a[i] = ft_atoi_validate(argv[i + 1], &error);
		if (error)
		{
			print_error_and_free(a, b);
			return (1);
		}
		i++;
	}

	i = 0;
	while (i < size_a)
	{
		int j = i + 1;
		while (j < size_a)
		{
			if (a[i] == a[j])
			{
				print_error_and_free(a, b);
				return (1);
			}
			j++;
		}
		i++;
	}

		/////////

    int *normalized = normalize(a, n);
    i = 0;
    while (i < n)
    {
        a[i] = normalized[i];
        i++;
    }
    free(normalized);


	

    printf("Antes de ordenar:\n");
    printstack("A", a, size_a);

	chunk_sort(a, &size_a, b, &size_b, n);
    //radix_sort(a, &size_a, b, &size_b, n);

    printf("\nDespués de ordenar:\n");
    printstack("A", a, size_a);
    printstack("B", b, size_b);

    return 0;
}
