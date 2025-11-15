#include "libft.h"

size_t fft_sstrlen(const char *s)
{
    size_t i = 0;
    while(*s)
    { 
        i++;
        s++;
    }
    return(i);
}

//OTRA FORMA
size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while(s[i] != '\0')
        i++;
    return(i);
}

/* 
int main()
{
    char *s = "chocolatero";
    size_t s_len = ft_strlen(s);
    printf("%zu", s_len);
    return(0);
}
*/