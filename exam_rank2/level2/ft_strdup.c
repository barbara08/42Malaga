#include "../level.h"
/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).
Your function must be declared as follows:
char    *ft_strdup(char *src);
*/

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return(i);
}


char *ft_strdup(char *src)
{
	int i = 0;
	char *copy;

	copy = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if(!copy)
		return(NULL);
	
	//while(src[i] != '\0')  => es lo mismo
	while(src[i])
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

