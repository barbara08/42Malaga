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


/* OTRA FORMA
int	ft_atoi(char *str)
{
	int	n = 0;
	while (*str)
		n = n * 10 + (*str++ - '0');
	return (n);
}*/

int ft_atoi(char *str)
{
    int result = 0;
    while(*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return(result);
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
        if(n == 1)
        {
            printf("1");
            return(0);
        }
        while(n > 1)
        {
            if(n % f == 0)
            {
                ft_putnbr(f);
                //Se actualiza el valor de n dividiéndolo por f
                n /= f;    //    n = n / f
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

/* EXPLICACIÓN

n = 30;
f = 2;
Primera iteración:
30 % 2 == 0 → entra al if
Imprime 2
Ejecuta n /= f; → ahora n = 30 / 2 = 15
Como n > 1, imprime " * "

Segunda iteración:
n = 15, f = 2
15 % 2 != 0 → entra al else, incrementa f = 3

Tercera iteración:
15 % 3 == 0 → entra al if
Imprime 3
Ejecuta n /= f; → ahora n = 15 / 3 = 5
Como n > 1, imprime " * "

Cuarta iteración:
n = 5, f = 3
5 % 3 != 0 → f = 4
5 % 4 != 0 → f = 5
5 % 5 == 0 → entra al if
Imprime 5
Ejecuta n /= f; → ahora n = 5 / 5 = 1
Como n == 1, ya no imprime más " * "

*/