#include <stdlib.h>   /* malloc, free, atoi */
#include <stdio.h>    /* fprintf, stdout */

int validation(int *table, int row, int col)
{
    int i;

    i = 0;
    while (i < col)
    {
        if (table[i] == row)
            return (0);
        if (table[i] - i == row - col)
            return (0);
        if (table[i] + i == row + col)
            return (0);
        i++;
    }
    return (1);
}

void print_solution(int *table, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (i > 0)
            fprintf(stdout, " ");
        fprintf(stdout, "%d", table[i]);
        i++;
    }
    fprintf(stdout, "\n");
}

void n_queens(int col, int size, int *table)
{
    int row;

    if (col == size)
    {
        print_solution(table, size);
        return ;
    }
    row = 0;
    while (row < size)
    {
        if (validation(table, row, col))
        {
            table[col] = row;
            n_queens(col + 1, size, table);
        }
        row++;
    }
}

int main(int ac, char **av)
{
    int *table;
    int size;

    if (ac != 2)
        return (1);
    size = atoi(av[1]);
    if (size <= 0)
        return (0);
    table = (int *)malloc(sizeof(int) * size);
    if (!table)
        return (1);
    n_queens(0, size, table);
    free(table);
    return (0);
}
