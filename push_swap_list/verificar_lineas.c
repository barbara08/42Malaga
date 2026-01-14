#include "push_swap.h"

long ft_converted_digit(const char *str, const char **endptr)
{
    long num;
    const char *start;

    num = 0;
    start = str;
    while (*str >= '0' && *str <= '9')
    {
        num = num * 10 + (*str - '0');
        if (num > (long)INT_MAX + 1L)
            return 2147483648L; // error de overflow
        str++;
    }

    if (str == start)
        return 2147483648L; // no hay dígitos

    if (endptr)
        *endptr = str;

    return (num);
}

long ft_atol(const char *str, char **endptr)
{
    long num;
    int sign;

    sign = 1;
    if (endptr)
        *endptr = (char *)str;

    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;

    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }

    num = ft_converted_digit(str, (const char **)endptr);

    return num * sign;
}



//ORIGINAL, OK, PERO SE PASA DE LAS 25 LINEAS
// Nuevo ft_atol que se usará en parsing.c
long	ft_atol(const char *str, char **endptr)
{
	long	num;
	int		sign;
    
	num = 0;
	sign = 1;
    // Inicializa endptr al inicio de la cadena en caso de no encontrar dígitos
    if (endptr)
		*endptr = (char *)str;

	// 1. Saltar Whitespace inicial
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;

	// 2. Manejar Signo
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}

	// 3. Conversión de Dígitos
    // Usamos 'start_digits' para saber si encontramos al menos un dígito
    const char *start_digits = str;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
        // 4. Chequeo de Overflow (antes de multiplicar por el signo final)
        // Se usa INT_MAX/MIN + 1L para verificar el valor sin signo
        if (num > (long)INT_MAX + 1L) // 2147483648L
        {
            // Este es un error de overflow. El valor 2147483648L es
            // usado para indicar error en tu lógica original.
            return (2147483648L); 
        }
		str++;
	}
    
    // Si no se leyó ningún dígito, la cadena no tiene formato válido
    if (str == start_digits)
    {
        // Si hay un '+' o '-' solo, o basura inicial, se marcará como error 
        // cuando fill_stack_from_str chequee 2147483648L.
        // Se devuelve un valor que fallará la validación INT_MIN/MAX
        if (*start_digits == '\0' && sign == 1) // Caso de cadena vacía o solo espacios, que no debería ocurrir aquí
            return (0);
        return (2147483648L); // Indica error de formato
    }

    // 5. Actualizar endptr al primer caracter no numérico (el espacio, o '\0')
    if (endptr)
		*endptr = (char *)str;

	return (num * sign);
}