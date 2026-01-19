#include "libfttheory.h"

int ft_putchar(char c)
{
    return(write(1, &c, 1));
}

void ft_putstr(char *str)
{
    while(*str)
        write(1, str++, 1);
}

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while(s[i] != '\0')
        i++;
    return(i);
}

//Imprimir c => n veces
void ft_putchar_n(char c, int n)
{
    while (n > 0)
    {
        write(1, &c, 1);
        n--;
    }
}

void ft_putstr_n(char *str, int n)
{
    while(*str)
    {
        int i = 0;
        while(i < n)
        {
            write(1, str, 1);
            i++;
        }
        str++;
    }
}

void ft_putnbr(int n)
{
	//Manejar INT MIN
	if (n == -2147483648) // límite de int
    {
        write(1, "-2147483648", 11);
        return;
    }
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


char	*ft_itoa(int nbr)
{
    int		len = 0; 
	int		tmp = nbr; 
	int		negative = nbr < 0; 
	char	*str; 

	if (nbr == -2147483648)
		return ("-2147483648");
    
	if (nbr == 0)
		len = 1;
	//Contar dígitos
	while (tmp != 0)
	{
		tmp /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + negative + 1));
	if (!str)
		return (NULL);

    str[len + negative] = '\0';
  
    if (nbr == 0)
		str[0] = '0';

    if (negative)
	{
		str[0] = '-';
		nbr = -nbr;
	}

	while (nbr != 0)
	{
		str[len-- + negative - 1] = (nbr % 10) + '0';
		nbr /= 10;
	}
    return (str);
}

//OTRA FORMA DE HACER ft_itoa
char *fft_itoa(int nbr)
{
    int     n = nbr;
    //Inicializa len con 1 si nbr es cero o negativo, y 0 si es positivo.
    //Esto es para contar el signo '-' en negativos o el dígito '0' en caso de cero.
    int     len = (nbr <= 0); // Cuenta 1 si es negativo o cero
    char    *str;

    // Contar dígitos
    while (n)
    {
        n /= 10;
        len++;
    }
    str = (char *)malloc(len + 1);
    if (!str)
        return (NULL);
    //Colocar \0 al final de la cadena
    str[len] = '\0';
    //Si el número original es cero, 
    //coloca el carácter '0' en la primera posición, porque el bucle de abajo no lo cubrirá (ya que no entra en el while
    if (nbr == 0)
        str[0] = '0';
    //Manejar negativo
    //Si el número es negativo, 
    //coloca el signo menos '-' en la primera posición de la cadena
    if (nbr < 0)
    {
        str[0] = '-';
        // Usar long para evitar desbordamiento en -2147483648
        unsigned int un = -(unsigned int)nbr;
        while (un)
        {
            str[--len] = (un % 10) + '0';
            un /= 10;
        }
    }
    //Manejar positivo
    //si el número es positivo, hace lo mismo que arriba pero directamente con nbr
    else
    {
        while (nbr)
        {
            str[--len] = (nbr % 10) + '0';
            nbr /= 10;
        }
    }
    return (str);
}


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

int main()
{
    //ft_putchar
    printf("ft_putchar\n");
    int c = 'j';
    int cc = 'j';
    // Convierte 0 o 1 en carácter ASCII '0' o '1'
    ft_putchar(c + '0'); //Imprime el nº ASCII que es '?'
    ft_putchar('\n');
    ft_putchar(cc); //Imprime la letra 'j'
    ft_putchar('\n');

    //ft_putstr
    printf("ft_putstr\n");
    char *str = "jajaja";
    ft_putstr(str);
    ft_putstr("\n");

    //ft_strlen
    printf("ft_strlen\n");
    printf("%zu\n", ft_strlen(str));

    //ft_putchar_n
    printf("ft_putchar_n\n");
    char *ccc = "abc";
    ft_putchar_n(*ccc, 3);
    printf("\n");

    //ft_putstr_n
    printf("ft_putstr_n\n");
    char *s = "abc";
    ft_putstr_n(s, 3);
    printf("\n");

    //ft_putnbr
    printf("ft_putnbr\n");
    ft_putnbr('A');
	write(1, "\n", 1);

	ft_putnbr(-5);
	write(1, "\n", 1);

	ft_putnbr(-2147483647);
	write(1, "\n", 1);

	ft_putnbr(2147483647);
	write(1, "\n", 1);

    //ft_atoi
    printf("ft_atoi\n");
	const char *test1 = "   123";
	const char *test2 = "-456";
	const char *test3 = "+789";
	const char *test4 = "   \t\n\r\f\v42abc";
	const char *test5 = "abc123";
	const char *test6 = "2147483647"; // INT_MAX
	const char *test7 = "-2147483648"; // INT_MIN

    printf("ft_atoi(\"%s\") = %d\n", test1, ft_atoi(test1));
	printf("ft_atoi(\"%s\") = %d\n", test2, ft_atoi(test2));
	printf("ft_atoi(\"%s\") = %d\n", test3, ft_atoi(test3));
	printf("ft_atoi(\"%s\") = %d\n", test4, ft_atoi(test4));
	printf("ft_atoi(\"%s\") = %d\n", test5, ft_atoi(test5));
	printf("ft_atoi(\"%s\") = %d\n", test6, ft_atoi(test6));
	printf("ft_atoi(\"%s\") = %d\n", test7, ft_atoi(test7));


    //ft_itoa
    printf("ft_itoa\n");
	char *str1 = ft_itoa(-12345);
	char *str2 = ft_itoa(12345);
	char *str3 = ft_itoa(0);

	int i = 0;
	while (str1[i])
		write(1, &str1[i++], 1);
    printf("\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);

	free(str1);
	free(str2);
	free(str3);

	return (0);
}



    