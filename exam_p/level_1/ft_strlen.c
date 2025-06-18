#include <unistd.h>
#include <stdio.h>
/*
Write a function that returns the length of a string.
Your function must be declared as follows:

int	ft_strlen(char *str);
*/
int	ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return(i);
}

int main()
{
    char *str = "hola don pepito";
    printf("%d", ft_strlen(str));

    return(0);
}