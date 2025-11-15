#include "libft3.h"

/*
Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.
The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".
Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".
Minus signs ('-') are interpreted only if they are the first character of the
string.
Your function must be declared as follows:
int	ft_atoi_base(const char *str, int str_base);
*/

int char_to_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1); // Invalid character
}
//		./a.out "1a" "16"  => 26
//		./a.out "1a" "18"  => break

int ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int rest = 0;
	int value;

	// Saltar espacios y caracteres de control (ASCII <= 32)
	while(str[i] <= 32)
		i++;
	// Detectar signo solo al inicio
	if(str[i] == '-')
	{
		sign = -1;
		i++;
	}
	// Convertir mientras los caracteres sean válidos para la base
	while(1)
	{
		value = char_to_value(str[i]);
		//(-1)caracter invalido || (value >= str_base)fuera de rango para la base 
		if(value == -1 || value >= str_base) 
			break;
		rest = rest * str_base + value;
		i++;
	}
	return(rest * sign);
}
/*
El while (1) es un bucle infinito: 
significa que el ciclo seguirá ejecutándose para siempre, 
a menos que se use un break para salir
SE USA PORQUE
Porque no sabes exactamente cuántos caracteres válidos habrá en la cadena.
La función va leyendo carácter a carácter.
Cuando encuentra un carácter inválido o fuera de rango para la base, usa break para salir.
Esto hace que el bucle termine justo cuando ya no se pueda convertir más.
*/

/*EXPLICACION 
FUNCION   char_to_value
Convierte un carácter que representa un dígito en una base hasta 16 
('0'–'9', 'a'–'f', 'A'–'F') a su valor numérico entero.
Si el carácter es entre '0' y '9'
→ devuelve su valor numérico ('0' → 0, '9' → 9)
Si es una letra minúscula entre 'a' y 'f'
→ devuelve 10 a 15 ('a' → 10, 'f' → 15)
Si es una letra mayúscula entre 'A' y 'F'
→ también devuelve 10 a 15 ('A' → 10, 'F' → 15)
Si no es un carácter válido para bases hasta 16
→ devuelve -1
*/

//Esta función para el main
void ft_putnbr(int n)
{
	char c;

	if (n == -2147483648) // Caso mínimo de int
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int result;

    if (argc != 3)
    {
        write(1, "Introduce un número y su base\n", 31);
        return (1);
    }
    // Convert base from string to int (we assume it's valid)
    int base = 0;
    int i = 0;
    while (argv[2][i])
    {
		if (argv[2][i] < '0' || argv[2][i] > '9')
        {
            write(1, "Base inválida\n", 13);
            return (1);
        }
        base = base * 10 + (argv[2][i] - '0');
        i++;
    }
    result = ft_atoi_base(argv[1], base);
    ft_putnbr(result);
    write(1, "\n", 1);
    return (0);
}


/* 
int main()
{	//RESULTADOS
    printf("%d\n", ft_atoi_base("1a", 16));  // 26
    printf("%d\n", ft_atoi_base("-101", 2)); // -5
    printf("%d\n", ft_atoi_base("123", 4));  // 27
    printf("%d\n", ft_atoi_base("12FDB3", 16)); // 1244483
    return 0;
}
*/

//------------------------------------------------------------------------------


/* FUNCIONA PERO ES MAS LARGA Y COMPLEJA PARA MI
//Función para ignorar espacios, tabs, saltos de línea, etc. al comienzo
int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == '\v' || c == '\f' || c == '\r');
}
//Funcion que convierte un carácter que representa un dígito en una base hasta 16
int char_to_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1); // Invalid character
}

int ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int result = 0;
	int sign = 1;
	int value;

	if (str_base < 2 || str_base > 16)
		return (0);

	// Saltar espacios iniciales
	while (is_space(str[i]))
		i++;
	// Verificar si el primer caracter es '-'
	// Signo negativo
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	// Recorrer la cadena mientras haya caracteres válidos
	// Convertir cada carácter válido a su valor numérico
	while (str[i])
	{
		value = char_to_value(str[i]);
		if (value < 0 || value >= str_base)
    		break; // Caracter no válido en la base indicada
		result = result * str_base + value;
		i++;
	}
	return (result * sign);
}
*/

