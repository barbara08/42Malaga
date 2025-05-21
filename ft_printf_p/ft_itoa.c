
#include "printf.h"

char	*ft_itoa(int n)
{
	int tmp;
	int len;
	char *str;

	tmp = n;
	len = (n <= 0);
	while (tmp && ++len)
		tmp /= 10;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		int digit = n % 10;
		if (digit < 0)
			digit = -digit;
		str[--len] = '0' + digit;
		n /= 10;
	}
	return (str);
}