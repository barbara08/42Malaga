#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *ddest = dest;
    unsigned const char *ssrc = src;
    size_t i = 0;

    if(ddest == NULL && ssrc == NULL)
        return(NULL);

    while (i < n)
    {
        ddest[i] = ssrc[i];
        i++;
    }
    /* Estas dos lineas sobran 
    dest = (void *) ddest;
	src = (void *) ssrc;
    */
    return(dest);
}
/*
int main()
{
    char dest[13] = "que tal";
    char src[] = "hola";
    ft_memcpy(dest, src, 4);
    printf("Result 1: %s\n", dest);
    //SIN PRINTF
    char ssrc[] = "42Malaga";
    char ddest[20];
    int i = 0;

    ft_memcpy(ddest, ssrc, 6); // Copia los primeros 6 caracteres: "42Mad"
    write(1, "Resul 2: ", 11);
    while (i < 6)
    {
        write(1, &ddest[i], 1);
        i++;
    }
    //write(1, "\n", 1);

    return (0);
}
 */