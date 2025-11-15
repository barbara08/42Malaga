#include "libft2.h"
/*
Reproduce exactly the behavior of the function strcspn
(man strcspn).
The function should be prototyped as follows:
size_t	ft_strcspn(const char *s, const char *reject);
*/

// FUNCION CON INDICES
size_t	ft_strcspn(const char *s, const char *reject)
{

	size_t i;	//para *s
	size_t x;	//para *reject

	i = 0;
	while(s[i])
	{
		x = 0;
		while (reject[x])
		{
			if(s[i] == reject[x])
					return(i);
			x++;
		}
		i++;
	}
	return(i);
}

//FUNCION CON PUNTEROS

size_t	fft_sstrcspn(const char *s, const char *reject)
{
	const char *s1;	//para *s
	const char *s2;	//para *reject

	s1 = s;
	while(*s)
	{
		s2 = reject;
		while(*s2)
		{
			if(*s == *s2)
				return (s - s1);
			s2++;
		}
		s++;
	}
	return(s - s1);
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