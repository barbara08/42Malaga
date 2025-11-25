#include "push_swap.h"


//Correcto las 25 lineas, ok
int	count_numbers_in_string(const char *str)
{
	int	count;
	int	in_number;
	int	i;

	i = 0;
	in_number = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
		{
			if (!in_number)
			{
				count++;
				in_number = 1;
			}
		}
		else
			in_number = 0;
		i++;
	}
	return (count);
}


static int	fill_stack_from_str(const char *str, t_data *data)
{
	int		i;
	long	num;
	char	*ptr;
	char	*temp_ptr; // Usamos esto para la nueva ft_atol

	i = 0;
	ptr = (char *)str;
	while (i < data->total)
	{
        // 1. Llamar a ft_atol: le pasamos la dirección de ptr
        // ptr será actualizado para apuntar al carácter después del número
		num = ft_atol(ptr, &temp_ptr); 
        
		// Comprobación 1: Overflow (num > INT_MAX || num < INT_MIN)
		// Comprobación 2: Error de formato/basura (num == 2147483648L)
		if (num > INT_MAX || num < INT_MIN || num == 2147483648L)
			return (1);
            
		data->a[i] = (int)num;
        
        // El puntero 'ptr' ahora avanza usando 'temp_ptr' actualizado por ft_atol
        ptr = temp_ptr;
        
        // 2. Saltamos los espacios/whitespace que separan los números
		while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
			ptr++;
            
		i++;
	}
    
    // 3. Chequeo final de basura (aunque count_numbers_in_string lo previene)
    // Si count_numbers_in_string fue correcto, ptr debería estar en '\0'
    if (*ptr != '\0')
		return (1);

	return (0);
}


int	parse_args(int argc, char **argv, t_data *data)
{
	int		i;
	long	val;

	if (argc == 2)
	{
		// Si fill_stack_from_str falla (por formato o overflow), retorna 1
		if (fill_stack_from_str(argv[1], data))
			return (1);
	}
	else // argc > 2
	{
		i = 0;
		while (i < data->total)
		{
            char *endptr;
            
			// Llama a la nueva ft_atol, pasando la dirección de endptr
			val = ft_atol(argv[i + 1], &endptr); 

			// Comprobación 1 & 2
			if (val > INT_MAX || val < INT_MIN || val == 2147483648L)
				return (1);
            
            // Comprobación 3: La cadena del argumento no debe tener basura al final
            // (Es decir, endptr debe apuntar al terminador \0)
            if (*endptr != '\0')
                return (1);
                
			data->a[i] = (int)val;
			i++;
		}
	}
	return (0);
}

