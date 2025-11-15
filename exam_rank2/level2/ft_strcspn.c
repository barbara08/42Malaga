#include "../level.h"
/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).
The function should be prototyped as follows:
size_t	ft_strcspn(const char *s, const char *reject);
*/

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i;
	size_t r;

	i = 0;
	while (s[i])
	{
		r = 0;
		while (reject[r])
		{
			if(s[i] == reject[r])
				return(i);
			r++;
		}
		i++;
	}
	return(i);
}

int main()
{
	const char *s = "periquito los palotes";
	const char *reject1 = "aeiou";
	const char *reject2 = "t";
	size_t ftstrcspn1 = ft_strcspn(s, reject1);
	size_t ftstrcspn2 = ft_strcspn(s, reject2);

	printf("strcspn1: %zu\n", ftstrcspn1);
	printf("strcspn2: %zu\n", ftstrcspn2);

	return(0);
}