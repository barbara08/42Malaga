//#include "ft_printf.h"
#include <stdio.h>

//verifica longitud, caracteres inválidos, y duplicados
int	ft_validate_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		//// Verifica que el carácter no sea '+' ni '-', ni un carácter no imprimible (ASCII <= 32) ni fuera del rango imprimible ASCII (>126)
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
			return (0);
		// Comprobar si el carácter base[i] se repite en la cadena base
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	// La base debe tener al menos 2 caracteres
	return (i >= 2); 
}

//convierte el número a string
char	*fft_converse_base(long n, char *base_str)
{
	int				base;
	int				len;
	int				is_neg;
	char			*str;
	unsigned long	un;

	// Validamos base con la funcion ya creada de antes
	if (!ft_validate_base(base_str))
		return (NULL);

	// Calcular longitud de la base
	base = 0;
	while (base_str[base])
		base++;

	// Convertir número a positivo si es negativo
	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		un = (unsigned long)(-n);
	}
	else
		un = (unsigned long)n;

	// Contar dígitos y reservar memoria
	len = ft_count_digit(un, base) + is_neg;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';

	// Construir string desde el final
	while (len--)
	{
		str[len] = base_str[un % base];
		un /= base;
		if (un == 0 && is_neg && len > 0)
		{
			len--;
			str[len] = '-';
			break;
		}
	}
	return (str);
}


int main(void)
{
	unsigned long n = -2512452145521;
	//char *base_str = "0123456789ABCDEF";
	//char *base_str = "01";
	//char *base_str = "0123456789";
	//char *base_str = "01234567";
	//char *base_str = "0123456889ABCDEF";
	char *base_str = "5";

	char *result = fft_converse_base(n, base_str);
	
	if (result)
	{
		printf("Converted number: %s\n", result);
		free(result);
	}
	else
	{
		printf("Memory failed.\n");
	}
	
	//Probando la funcion ft_validate_base
	int validate = ft_validate_base(base_str);
	if(validate)
		printf("The base %s is validate", base_str);
	else
		printf("The base %s is not validate", base_str);

	return (0);
}