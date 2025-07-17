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
    // Signo negativo
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    // Convertir cada carácter válido a su valor numérico
    while (str[i])
    {
        value = char_to_value(str[i]);
        if (value < 0 || value >= str_base)
            break;
        result = result * str_base + value;
        i++;
    }
    return (result * sign);
}

//Esta función para el main
void ft_putnbr(int n)
{
    char c;
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
        base = base * 10 + (argv[2][i] - '0');
        i++;
    }
    result = ft_atoi_base(argv[1], base);
    ft_putnbr(result);
    write(1, "\n", 1);
    return (0);
}




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