#include <stdlib.h>
#include <unistd.h>

// Función para imprimir un subset
void print_subset(int *subset, int size)
{
    if (size == 0)
    {
        write(1, "\n", 1);
        return;
    }

    for (int i = 0; i < size; i++)
    {
        char buf[12]; // buffer para int como string
        int len = 0;
        int n = subset[i];
        int neg = 0;

        if (n == 0)
        {
            buf[len++] = '0';
        }
        else
        {
            if (n < 0)
            {
                neg = 1;
                n = -n;
            }
            int tmp = n;
            char rev[10];
            int rev_len = 0;
            while (tmp > 0)
            {
                rev[rev_len++] = (tmp % 10) + '0';
                tmp /= 10;
            }
            if (neg)
                buf[len++] = '-';
            for (int j = rev_len - 1; j >= 0; j--)
                buf[len++] = rev[j];
        }
        write(1, buf, len);
        if (i != size - 1)
            write(1, " ", 1);
    }
    write(1, "\n", 1);
}

// Backtracking para generar subsets
void backtrack(int *set, int *subset, int set_size, int subset_size,
               int index, int current_sum, int target)
{
    if (current_sum == target)
    {
        print_subset(subset, subset_size);
        return; // <--- CORRECCIÓN: detener esta rama para evitar duplicados
    }

    if (index == set_size)
        return;

    // Opción 1: NO incluir el elemento actual
    backtrack(set, subset, set_size, subset_size, index + 1, current_sum, target);

    // Opción 2: SÍ incluir el elemento actual
    subset[subset_size] = set[index];
    backtrack(set, subset, set_size, subset_size + 1, index + 1, current_sum + set[index], target);
}

// Validar argumentos numéricos
int check_args(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        int j = 0;
        if (argv[i][j] == '+' || argv[i][j] == '-')
            j++;
        if (!argv[i][j])
            return 0;
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
                return 0;
            j++;
        }
    }
    return 1;
}

int main(int argc, char **argv)
{
    if (argc < 2 || !check_args(argc, argv))
        return 1;

    int target = atoi(argv[1]);
    int set_size = argc - 2;
    if (set_size < 0)
        return 1;

    int *set = malloc(set_size * sizeof(int));
    int *subset = malloc(set_size * sizeof(int));
    if (!set || !subset)
    {
        free(set);
        free(subset);
        return 1;
    }

    for (int i = 0; i < set_size; i++)
        set[i] = atoi(argv[i + 2]);

    backtrack(set, subset, set_size, 0, 0, 0, target);

    free(set);
    free(subset);
    return 0;
}
