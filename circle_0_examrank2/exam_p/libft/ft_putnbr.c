#include "libft.h"

//Usando la función ft_putchar
void	fft_pputnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

//Sin usar la función ft_putchar
void ft_putnbr(int n)
{
	//Manejar INT MIN
	/* 
	if (n == -2147483648) // límite de int
    {
        write(1, "-2147483648", 11);
        return;
    }*/
	//Manejar el negativo
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	//Manejar el positivo
	char c;
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}


int main()
{
	ft_putnbr('A');
	write(1, "\n", 1);

	ft_putnbr(-5);
	write(1, "\n", 1);

	ft_putnbr(-2147483647);
	write(1, "\n", 1);

	ft_putnbr(2147483647);
	write(1, "\n", 1);

	fft_pputnbr('A');

	return(0);
}
