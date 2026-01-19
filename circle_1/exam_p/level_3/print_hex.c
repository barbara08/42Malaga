#include "libft3.h"
/*
Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.
If the number of parameters is not 1, the program displays a newline.
Examples:
$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/
int	ft_atoi(const char *str)
{
	int result = 0;
	int negative = 1;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if(*str == '-')
	{
		negative = -1;
		str++;
	}
	else if(*str == '+')
		str++;
	while(*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return(result * negative);
}

void ft_puthex(int nbr)
{
	char *str = "0123456789abcdef";
	if(nbr >= 16)
		ft_puthex(nbr / 16);
	nbr = str[nbr % 16];
	write(1, &nbr, 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_puthex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}