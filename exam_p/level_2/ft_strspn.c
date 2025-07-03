#include <stdio.h>
/*
Reproduce exactly the behavior of the strspn function 
(man strspn).
The function should be prototyped as follows:
size_t	ft_strspn(const char *s, const char *accept);
*/

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i;
	size_t x;
	size_t f;

	i = 0;
	while(s[i])
	{
		x = 0;
		f = 0;
		while(accept[x])
		{
			if(s[i] == accept[x])
				f = 1;
			x++;
		}
		if(f == 0)
			return(i);
		i++;
	}
	return(i);
}
int main()
{
	const char *s = "hello";
	const char *accept1 = "jfkkhpoell";
	const char *accept2 = "x";
	size_t ftstrspn1 = ft_strspn(s, accept1);
	size_t ftstrspn2 = ft_strspn(s, accept2);

	printf("strspn1: %zu\n", ftstrspn1);
	printf("strspn2: %zu\n", ftstrspn2);

	return(0);
}