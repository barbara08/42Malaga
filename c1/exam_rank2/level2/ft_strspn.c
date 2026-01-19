#include "../level.h"
/*
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).
The function should be prototyped as follows:
size_t	ft_strspn(const char *s, const char *accept);
*/

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i;
	size_t a;

	i = 0;
	while(s[i])
	{
		a = 0;
		while (accept[a])
		{
			if(s[i] == accept[a])
				break;
			a++;
		}
		//if(accept[a] == '\0') => es lo mismo
		if(!accept[a])
			return(i);
		i++;
	}
	return(i);
}

int main()
{
	const char *s = "ppperiquito los palotes";
	const char *accept1 = "x";
	const char *accept2 = "eriuito los palotes";
	//const char *s = "hello";
	//const char *accept2 = "jfkkpoell";
	size_t ftstrspn1 = ft_strspn(s, accept1);
	size_t ftstrspn2 = ft_strspn(s, accept2);

	printf("strspn1: %zu\n", ftstrspn1);
	printf("strspn2: %zu\n", ftstrspn2);

	return(0);
}