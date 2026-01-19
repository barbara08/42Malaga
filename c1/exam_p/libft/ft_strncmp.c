#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned char *ss1;
    unsigned char *ss2;
    size_t i;

    ss1 = (unsigned char *)s1;
    ss2 = (unsigned char *)s2;
    i = 0;

    while((ss1[i] != '\0' || ss2[i] != '\0') && (i < n))
    {
        if(ss1[i] != ss2[i])
            return(ss1[i] - ss2[i]);
        i++;
    }
    return(ss1[i] - ss2[i]);
}

int main()
{
    char *s1 = "AB";
    char *s2 = "ABC";
    int strncmp = ft_strncmp(s1, s2, 2);
    printf("strncmp: %d", strncmp);
}