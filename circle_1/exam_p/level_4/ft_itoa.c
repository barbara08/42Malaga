#include "libft4.h"

/*
Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.
Your function must be declared as follows:
char	*ft_itoa(int nbr);
Allowed functions: malloc
*/

char	*ft_itoa(int nbr)
{
	char	*str;
	int		len = 1;	//Todos números tiene al menos un dígito
	long	n = nbr;	//convertimos nbr (int) a long para evitar errores con INT_MIN
	long	tmp;		//copia de n usada para contar cuántos dígitos tiene
	//1. Si el número es negativo pasar a positivo
	if (n < 0)
	{
		n = -n;
		len++; // para el signo negativo
	}
	//2. Calculamos la cantidad de dígitos
	tmp = n;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		len++;
	}
	//3. Reservar memory
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	//4. Ponemos el carácter nulo (\0) al final de la cadena.
	str[len] = '\0';
	//5. Rellenamos el string con los dígitos
	while (len--)
	{
		str[len] = '0' + (n % 10);
		n = n / 10;
		//6. Colocamos el signo si es negativo en la posicion 0
		if (len == 1 && nbr < 0)
		{
			str[0] = '-';
			break;
		}
	}
	//7. Devolver str
	return (str);
}

//MAIN PARA PROBAR
int main()
{
	char *str = ft_itoa(-12345);

	int i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	free(str);
	return (0);
}

/*
1.
Si el número es negativo:
Lo pasamos a positivo (-n) para poder extraer dígitos.
Aumentamos len para reservar espacio para el signo '-'.
Aquí usamos long para evitar desbordamiento con -2147483648.
2.
Usamos tmp para contar cuántas cifras tiene el número:
Mientras tmp >= 10, dividimos por 10 y aumentamos len.
Esto cuenta cuántas cifras necesitaremos.
3. 
Reservar memoria para str
4. 
Ponemos el carácter nulo (\0) al final de la cadena.
5. 
Este bucle llena el string desde el final hacia el principio.
n % 10 obtiene el último dígito (ej: de 123 sale 3).
'0' + número lo convierte en carácter ASCII.
Después, dividimos n entre 10 para obtener el siguiente dígito.
6.
Si llegamos a la posición 1 (penúltima) y el número original (nbr) era negativo:
Colocamos '-' en la posición 0.
Hacemos break porque ya terminamos de llenar.
7. Delvolver str
*/