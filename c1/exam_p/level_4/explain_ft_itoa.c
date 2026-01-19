#include "libft4.h"

char	*ft_itoa(int nbr)
{
    int		len = 0;                // longitud del número (cantidad de dígitos)
	int		tmp = nbr;              // copia del número para contar dígitos
	int		negative = nbr < 0;     // bandera para saber si es negativo
	char	*str;                   // puntero al string que se va a devolver

    // Caso especial: el número más pequeño representable en un int
	// No se puede hacer nbr = -nbr porque se desborda
    // Manejo del INT_MIN (-2147483648), ya que no se puede hacer -INT_MIN
	if (nbr == -2147483648)
		return ("-2147483648");
    // Contar cuántos dígitos tiene el número
    // Si el número es 0, su longitud es 1
	if (nbr == 0)
		len = 1;
    // Contar la cantidad de dígitos (en valor absoluto)
	while (tmp != 0)
	{
		tmp /= 10;
		len++;
	}
    // Reservar memoria para los caracteres:
	// longitud + 1 si es negativo + 1 para el '\0'
    // Reservar memoria para el string + signo si es negativo + terminador nulo
	str = (char *)malloc(sizeof(char) * (len + negative + 1));
	if (!str)
		return (NULL);
    //Coloca el carácter nulo (\0) al final del string.
    //len es la cantidad de dígitos del número.
    //negative vale 1 si el número es negativo, 0 si no. Se suma porque el signo - ocupa un lugar extra.
    str[len + negative] = '\0';
    //Verificar si es 0
    //Si el número es 0, coloca el carácter '0' en la primera posición del string.
    //No entra al while si el número es 0, así que lo maneja aparte.
    if (nbr == 0)
		str[0] = '0';
    //Verificar si es negativo
    //Si el número es negativo:
    //Escribe el signo - al inicio de la cadena.
    //Convierte nbr a positivo para facilitar el siguiente bucle.
    if (negative)
	{
		str[0] = '-';
		nbr = -nbr;
	}
    // Construir el string de derecha a izquierda
    //Construye el string numérico de derecha a izquierda.
    //nbr % 10 obtiene el dígito menos significativo.
    //Se convierte a carácter sumándole '0'.
    //Se coloca en la posición correspondiente: len-- + neg - 1.
    //+negative compensa si hay un signo - al inicio.
	while (nbr != 0)
	{
		str[len-- + negative - 1] = (nbr % 10) + '0';
		nbr /= 10;
	}
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