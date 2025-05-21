#include "printf.h"

char	*ft_converse_base(unsigned long n, char *base_str)
{
	int	base;
	int len;
	char *str;

	base = 0;
	while (base_str[base])
		base++;
	len = ft_count_digit(n, base);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = base_str[n % base];
		n /= base;
	}
	return (str);
}