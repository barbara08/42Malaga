#include "libft3.h"

/*
Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.
If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.
Yes, the examples are right.
Examples:
$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

//return(0) => NO es primo
//return(1) => SI es primo
int is_prime(int n)
{
	int divisor = 2;
	if (n < 2)
		return(0);
	while (divisor * divisor <= n)
	{
		if(n % divisor == 0)
			return(0);
		divisor++;
	}
	return(1);
}

int isPrime(int num)
{
	if (num <= 1)
		return (0); // No es primo ni 0 ni 1
	int i = 2;
	while (i < num)
	{
		if (num % i == 0)
			return (0); // No es primo
		i++;
	}
	return (1); // Es primo
}


//Para imprimir un número
//No verifica el negativo (porque solo pide positivo)
//Para poder imprimir sum
void ft_putnbr(int n)
{
    char c;
    if (n >= 10)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}
//Pasar str a número, solo el positivo
//Esto es para el argv[1];
int	ft_atoi_positive(const char *str)
{
    int result = 0;
   // int negative = 1;

    while ((*str >= 9 && *str <= 13) || *str == 32)
        str++;
    /*if(*str == '-')
    { 
        negative = -1;
        str++;
    }*/
    if(*str == '+')
        str++;
    while(*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    //return(result * negative);
    return(result);
}

int main(int argc, char **argv)
{
    int i;
    int n;
    int sum = 0;
    if(argc == 2)
    {
        n = ft_atoi_positive(argv[1]);
        if (n <= 0)
        {
            write(1, "0\n", 2);
            return(0);
        }
        i = 2;
        while (i <= n)
        {
            if (isPrime(i))
                sum += i;
            i++;
        }
    }
    ft_putnbr(sum);
    write(1, "\n", 1);
    return(0);
}


/* main para probar funcion is_prime 
int main()
{
    int n1 = 17;
    int n2 = 18;
    int isprime1 = is_prime(n1);
    int isprime2 = is_prime(n2);

    printf("n1 %d\n", isprime1);
    printf("n2 %d\n", isprime2);
    if(isprime1 == 1)
        printf("n1 is prime: %d\n", n1);
    else
        printf("n1 is not prime: %d\n", n1);
    if(isprime2 == 1)
        printf("n2 is prime: %d\n", n2);
    else
        printf("n2 is not prime: %d\n", n2);
    return(0);
}
*/

/* EXPLICACION is_prime
//i es divisor en mi función.
int i = 2;
Inicializa el divisor i en 2, que es el primer número con el que se probará la divisibilidad.
if (n < 2) return(0);
Si n es menor que 2, no es primo (porque los primos empiezan desde el 2).
while (i * i <= n)
El ciclo se ejecuta mientras i al cuadrado sea menor o igual a n. Esto es una optimización, porque no hace falta probar divisores mayores a la raíz cuadrada de n.
Dentro del while:
if (n % i == 0) return(0);
Si n es divisible por i, entonces no es primo y la función retorna 0 inmediatamente.
i++ incrementa i para probar con el siguiente posible divisor.
Si termina el while sin encontrar divisores, significa que n es primo, entonces retorna 1.
*/







