#include "libft3.h"
/*
Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.
LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.
A LCM can be calculated in two ways:
- You can calculate every multiples of each integers until you have a common
multiple other than 0
- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:
	LCM(x, y) = | x * y | / HCF(x, y)

  | x * y | means "Absolute value of the product of x by y"
If at least one integer is null, LCM is equal to 0.
Your function must be prototyped as follows:
unsigned int lcm(unsigned int a, unsigned int b);
*/

// Función auxiliar para calcular el MCD usando el algoritmo de Euclides
unsigned int hcf(unsigned int a, unsigned int b)
{
	while(b != 0)
	{
		unsigned int tmp = b;
		b = a % b;
		a = tmp;
	}
	return(a);
}

unsigned int lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return(0);
	//return((a / hcf(a, b)) * b);
	return(a * b / hcf(a,b));
}

//Función para usar en el main
void ft_putnbr(unsigned int n)
{
	char c;
	if (n >= 10)
		ft_putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}
int main()
{
	unsigned int a = 12;
	unsigned int b = 18;
	unsigned int result = lcm(a, b);

	write(1, "Result: ", 8);
	ft_putnbr(result);
	write(1, "\n", 1);

	//PROBAR LA FUNCION AUX hcf
	unsigned int hcff = hcf(a, b);
	printf("hcf: %d", hcff);
	return(0);
}

/* EXPLICACION:
hcf: implementa el algoritmo de Euclides para encontrar el máximo común divisor 
	usando solo while.
	Esta es la condición del algoritmo de Euclides, que dice:
	Reemplaza a por b y b por a % b hasta que b sea 0.

FORMULA QUE TE DAN:  LCM(x, y) = | x * y | / HCF(x, y)
lcm: usa la fórmula LCM(a, b) = (a / HCF(a, b)) * b, 
	lo cual es más seguro que (a * b) / HCF(a, b) para evitar desbordamientos
Return: Esta línea es la clave de la función. Usa la fórmula matemática del MCM:
 				a x b
LCM(𝑎,𝑏) =	----------
				HCF(𝑎,𝑏)
Pero en vez de hacer a * b / hcf(a, b), se hace:
(a/hcf(a,b))∗b
¿Por qué se hace de esta manera?
Porque reduce el riesgo de desbordamiento (overflow) en la multiplicación.
Primero divides a entre el MCD (número más pequeño), y luego multiplicas por b

ft_putnbr: función auxiliar que imprime un número usando recursión y write
	para probar en el main
*/