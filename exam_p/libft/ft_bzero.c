#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    size_t i = 0;
    unsigned char *ss = s;

    while(i < n)
    {
        ss[i] = '\0';
        i++;
    }
    //No hace nada, no hace falta asignarlo al final
    //s = (void *)ss;
}

int main()
{
    char s[] = "jajaja";
    int i = 0;
    //Pone a 0 los tres primeros caracteres
    ft_bzero(s, 3);
    write(1, "Result 1: ", 10);
    //(3 + 1 del \0)
    while(i < 6)
    {
        if (s[i] == '\0')
            write(1, "\\0", 2);  // Mostramos los nulos como texto
        else
            write(1, &s[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return(0);
}
