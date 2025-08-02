#include "libft4.h"

/*
Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.
Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.
If the number of parameters is not 1, simply display a newline.
The input, when there is one, will be valid.
Allowed functions: printf, atoi
Examples:
$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/

int	ft_atoi(char *str)
{
	int	n = 0;
	while (*str)
		n = n * 10 + (*str++ - '0');
	return (n);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int n;
    int f;

    if (argc == 2)
    {
        n = ft_atoi(argv[1]);
        f = 2;
        while(n > 1)
        {
            if(n % f == 0)
            {
                ft_putnbr(f);
                n /= f;
                if(n > 1)
                    write(1, " * ", 3);
            }
            else
                f++;
        }
    }
    write(1, "\n", 1);
	return (0);
}