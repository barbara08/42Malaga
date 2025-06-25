#include "libft.h"

//copies up to dstsize - 1 characters from the string src to dst,
//NUL-terminating the result if dstsize is not 0
//Return => el tamaño total que tendría la cadena en destino si hubiera espacio suficiente (es decir, strlen(src)).
//Esto permite detectar si hubo truncamiento.

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i = 0;
    size_t src_len = ft_strlen(src);

    if(size == 0)
        return(src_len);
    while (src[i] != '\0' && i < size - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (src_len);
}

int main()
{
    char dst[5];
    const char src[] = "hola que tal";

    size_t ftstrlcpy = ft_strlcpy(dst, src, 20);
    printf("frstrlcpy: %zu\n", ftstrlcpy);
    printf("dst: %s", dst);

    return(0);
}