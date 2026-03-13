#include "libft.h"

 void *ft_memset(void *b, int c, size_t len)
 {
    unsigned char *bb;
    size_t i;

    bb = (unsigned char *)b;
    i = 0;
    while(i < len)
    {
        bb[i] = (unsigned char)c;
        i++;
    }
    return(b);
 }


 void	*fft_mmemset(void *s, int c, size_t n)
{
	unsigned char	*dst;
	size_t			i;

	i = 0;
	dst = s;
	while (n > i)
	{
		dst[i] = c;
		i++;
	}
	s = (void *) dst;
	return (s);
}

int main()
{
    //Debe ser un array para que sea modificable
    //No un puntero (que solo apunta a una zona de memoria de solo lectura)
    char s[] = "jiji";
    int ast = '*';
    ft_memset(s, ast, 2);
    printf("memset: %s", s);
    return(0);
}