#include "../level.h"
/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.
It must return its parameter.
Your function must be declared as follows:
char    *ft_strrev(char *str);
*/

char *ft_strrev(char *str)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (str[i])
		i++;
	i--;
	j = 0;
	while (j < i)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		j++;
		i--;
	}
	return(str);
}


int main(void)
{
	char s[] = "hello";
	printf("%s\n", ft_strrev(s)); // Output: "olleh"
}