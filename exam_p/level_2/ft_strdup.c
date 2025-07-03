#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/*
Reproduce the behavior of the function strdup (man strdup).
Your function must be declared as follows:
char *ft_strdup(char *src);
*/

int	ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return(i);
}

char	*ft_strdup(char *src)
{
	char *copy;
	int i;

	copy = (char *)malloc(ft_strlen(src) + 1 * sizeof(char));
	i = 0;
	if (copy == NULL)
		return(NULL);
	while(src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return(copy);
}

int main()
{
	char *src = "Una copia de src en copy";
	char *ftstrdup = ft_strdup(src);
	printf("ft_strdup: %s\n", ftstrdup);
	printf("src: %s", src);
	return(0);
}