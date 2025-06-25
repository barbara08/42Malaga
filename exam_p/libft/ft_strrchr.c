#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    char *aux;
    char char_c = c;
    int len = ft_strlen(s);

    while(s[len] >= 0)
    {
        if(s[len] == char_c)
        {
            aux = (char *)&s[len];
            return(aux);
        }
        len--;
    }
    if(char_c == '\0' )
    {
        aux = (char *)&s[len];
        return(aux);
    }
    else
        return (NULL);
}

int main()
{
    char *s = "pierico";
    int c = 'i';
    char *strrchr = ft_strrchr(s, c);
    printf("strrchr: %s", strrchr);
    return(0);
}