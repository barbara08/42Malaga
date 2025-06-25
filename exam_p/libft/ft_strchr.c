#include "libft.h"

/*
The strchr() 
function locates the first occurrence of c (converted to a
char) in the string pointed to by s.  The terminating null character is
considered to be part of the string; therefore if c is ‘\0’, the
functions locate the terminating ‘\0’
*/

char *ft_strchr(const char *s, int c)
{
    int i = 0;
    char *aux;
    char char_c = (char)c;
    
    while(s[i] != '\0')
    {
        if(s[i] == char_c)
        {
            aux = (char *)&s[i];
            return (aux);
        }
        i++;
    }
    if(char_c == '\0')
    {
        aux = (char *) &s[i];
        return(aux);
    }
    else
        return (NULL);
}

int main()
{
    char *s = "periquito";
    int c = 'q';
    char *strchr = ft_strchr(s, c);
    printf("strchr: %s", strchr);
    return(0);
}