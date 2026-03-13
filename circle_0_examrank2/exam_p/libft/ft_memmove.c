#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *ddst = dst;
    unsigned const char *ssrc = src;
    size_t i = len;

    //Verificar NULL para evitar comportamiento indefinido
    if(!ddst && !ssrc)
        return (NULL);
    //Detecta correctamente si hay solapamiento
    if (ssrc < ddst)
    {
        while (i > 0)
        {
            //Copiar hacia atrás cuando es necesario (de final a inicio)
            i--;
            ddst[i] = ssrc[i];
        }
    }
    else
        //ft_memcpy para copiar hacia adelante cuando no hay conflicto
        ft_memcpy(ddst, ssrc, i);
    return(dst);
}


int main()
{
    char ssrc[] = "42Malaga";
    char ddest[20] = "guena";
    int i = 0;

    ft_memmove(ddest, ssrc, 6);
    write(1, "Result: ", 8);
    while (i < 6)
    {
        write(1, &ddest[i], 1);
        i++;
    }
    write(1, "\n", 1);
    printf("ssrc: %s\n", ssrc);
    printf("ddest: %s\n", ddest);

    return(0);
}