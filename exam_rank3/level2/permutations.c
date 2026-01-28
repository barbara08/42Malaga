#include <stdlib.h>
#include <unistd.h>

/* Intercambiar dos caracteres */
void ft_swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Longitud de string */
int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

/* Verificar si un carácter es letra */
int ft_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/* Ordenamiento burbuja para poner string en orden alfabético */
void sort_string(char *s, int len)
{
    int i, swapped;

    if (!s || len <= 1)
        return;
    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        i = 0;
        while (i < len - 1)
        {
            if (s[i] > s[i + 1])
            {
                ft_swap(&s[i], &s[i + 1]);
                swapped = 1;
            }
            i++;
        }
    }
}

/* Generar permutaciones por swap/backtracking */
void permute(char *s, int start, int len)
{
    int i;

    if (start == len)
    {
        write(1, s, len);
        write(1, "\n", 1);
        return;
    }
    i = start;
    while (i < len)
    {
        ft_swap(&s[start], &s[i]);
        permute(s, start + 1, len);
        ft_swap(&s[start], &s[i]); /* backtrack */
        i++;
    }
}

int main(int ac, char **av)
{
    int len;
    char *str;

    if (ac != 2)
        return 1;

    /* Validar solo letras */
    len = ft_strlen(av[1]);
    if (len == 0)
        return 0;
    for (int i = 0; i < len; i++)
    {
        if (!ft_isalpha(av[1][i]))
            return 0;
    }

    /* Reservar memoria para modificar string */
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return 1;
    for (int i = 0; i < len; i++)
        str[i] = av[1][i];
    str[len] = '\0';

    sort_string(str, len);    /* ordenar alfabéticamente */
    permute(str, 0, len);     /* generar permutaciones */

    free(str);
    return 0;
}
