#include "push_swap.h"

//Estoy en la duda de las lineas de codigo

int	ft_fill_stack_from_str(const char *str, t_data *data)
{
	int		i;
	char	*ptr;
	long	num;
	char	*temp_ptr; // Usamos esto para la nueva ft_atoi

	i = 0;
	ptr = (char *)str;
	while (i < data->total)
	{
		num = ft_atoi(ptr, &temp_ptr); 
		if (num > INT_MAX || num < INT_MIN || num == 2147483648L)
			return (1);
		data->a[i] = (int)num;
        ptr = temp_ptr;
		while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
			ptr++;
		i++;
	}
    if (*ptr != '\0')
		return (1);
	return (0);
}

//Estoy en la duda de las lineas de codigo 
int	ft_parse_args(int argc, char **argv, t_data *data)
{
	int		i;
	char	*endptr;
	long	tmp_value;

	if (argc == 2)
		if (ft_fill_stack_from_str(argv[1], data))
			return (1);
	else // argc > 2
	{
		i = 0;
		while (i < data->total)
		{
			tmp_value = ft_atoi(argv[i + 1], &endptr); 
			if (tmp_value > INT_MAX || tmp_value < INT_MIN || tmp_value == 2147483648L)
				return (1);
            if (*endptr != '\0')
                return (1);
			data->a[i] = (int)tmp_value;
			i++;
		}
	}
	return (0);
}


//ORIGINAL

int	ft_parse_args(int argc, char **argv, t_data *data)
{
	int		i;
	char	*endptr;
	long	tmp_value;

	if (argc == 2)
	{
		// Si ft_fill_stack_from_str falla (por formato o overflow), retorna 1
		if (ft_fill_stack_from_str(argv[1], data))
			return (1);
	}
	else // argc > 2
	{
		i = 0;
		while (i < data->total)
		{
            //char *endptr;   estaba aquí pero lo he subido arriba a ver si funciona
            
			// Llama a la nueva ft_atoi, pasando la dirección de endptr
			tmp_value = ft_atoi(argv[i + 1], &endptr); 

			// Comprobación 1 & 2
			if (tmp_value > INT_MAX || tmp_value < INT_MIN || tmp_value == 2147483648L)
				return (1);
            
            // Comprobación 3: La cadena del argumento no debe tener basura al final
            // (Es decir, endptr debe apuntar al terminador \0)
            if (*endptr != '\0')
                return (1);
                
			data->a[i] = (int)tmp_value;
			i++;
		}
	}
	return (0);
}


//LINEAS JUSTAS (también en pb)
void pa(int a[], int *len_a, int b[], int *len_b)
{
    int i;

    if (*len_b > 0)
    {
        i = *len_a;
        while (i > 0)
        {
            a[i] = a[i - 1];
            i--;
        }
        a[0] = b[0];

        i = 0;
        while (i < *len_b - 1)
        {
            b[i] = b[i + 1];
            i++;
        }
        (*len_a)++;
        (*len_b)--;
        write(1, "pa\n", 3);
    }
}


