#include "libft2.h"

/*
Write a function that determines if a given number is a power of 2.
This function returns 1 if the given number is a power of 2, otherwise it returns 0.
Your function must be declared as follows:
int	    is_power_of_2(unsigned int n);
*/

int is_power_of_2(unsigned int n)
{
    if(n == 0) // 0 no es potencia de 2
        return(0);
    while(n % 2 == 0) // Mientras sea divisible por 2
        n /= 2; // Divide entre 2 (reduce el valor)
    return(n == 1);  // Si al final queda 1, es potencia de 2
}

//Usando operaciones a nivel de bits (más eficiente)
int is_power_of_2_bits(unsigned int n) 
{
    // Verificamos que el número sea mayor que cero
    if (n <= 0) {
        return (0);
    }
    // Usamos una operación a nivel de bits:
    // Un número que es potencia de 2 tiene solo un bit en 1.
    // Por ejemplo, 8 = 1000 en binario, y 7 = 0111
    // 8 & 7 = 0000, entonces (n & (n - 1)) == 0 solo si n es potencia de 2
    if ((n & (n - 1)) == 0) 
        return (1);
    else 
        return (0);
}

//OTRA FORMA DE HACERLO CON BITS
int is_power_of_2_bits_simple(unsigned int n)
{
    return (n > 0 && (n & (n - 1)) == 0);
}

int main() 
{
	printf("1 -> %d\n", is_power_of_2(1));   // 1
	printf("2 -> %d\n", is_power_of_2(2));   // 1
	printf("3 -> %d\n", is_power_of_2(3));   // 0
	printf("4 -> %d\n", is_power_of_2(4));   // 1
	printf("5 -> %d\n", is_power_of_2(5));   // 0
	printf("0 -> %d\n", is_power_of_2(0));   // 0

	printf("\n");

	//--------------------------------------------------
    int n = 4;
    //Para los decimales
    if (is_power_of_2(n))
        printf("%d Si es potencia de 2\n", n);
    else
        printf("%d NO es potencia de 2\n", n);

    //Para los bits
    if (is_power_of_2_bits(n))
        printf("%d Si es potencia de 2\n", n);
    else
        printf("%d NO es potencia de 2\n", n);
    return (0);
}