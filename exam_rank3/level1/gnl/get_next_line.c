#include "get_next_line.h" //borrar esta libreria

char	*ft_strchr(char *s, int c)
{
	int	i = 0;
	while (s[i] && s[i] != c) // incluir dentro del while && s[i] "exista"
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, int n)
{
	while (n-- > 0) // cambiar el --n por n--
		((char *)dest)[n] = ((char *)src)[n]; // cambiarar los n - 1 por solo n
	return (dest);
}

int	ft_strlen(char *s)
{
	int	res = 0;
	while (s && *s) // añadir dentro del while && s "exista"
	{
		s++;
		res++;
	}
	return (res);
}

int	str_append_mem(char **s1, char *s2, int size2)
{
	/* Añadido por mi cuenta este if */
	if (!*s1)
	{
		*s1 = malloc(1);
		if (!*s1)
			return 0;
		(*s1)[0] = '\0';
	}
	int	size1 = ft_strlen(*s1);
	char	*tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = '\0';
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}
//Esta función no CREO que sea la correcta, no se usa parámetro n
void	*ft_memmove(void *dest, const void *src, int n)
{
	if (dest > src)
		return (ft_memmove(dest, src, n));
	else if (dest == src)
		return (dest);
	//size_t	i = ft_strlen((char *)src) - 1; // sustituir esta linea por int j = ft_strlen((char *)src);
	int j = ft_strlen((char *)src);
	int i = 0; 
	while (i <= j) //sustituir por while (i <= j)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++; // cambiar i-- por i++;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char	*ret = NULL;
	char	*tmp = ft_strchr(b, '\n');
	while (!tmp)
	{
		if (!str_append_str(&ret, b))
			return (NULL);
		int read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(ret); //Añadido por mi cuenta
			return (NULL);
		}
		b[read_ret] = 0;
		//Descomentado el if
		if (read_ret == 0)
		{
		  if (ret && *ret) //aqui he añadido por mi cuenta ret &&
			  return (ret);
		  free(ret);
		  return (NULL);
		}
		tmp = ft_strchr(b, '\n'); //tb descomentado
	}
	if (!str_append_mem(&ret, b, tmp - b + 1))
	{
		free(ret);
		return (NULL);
	}
	//ft_memmove(b, tmp + 1, ft_strlen(tmp + 1));
	ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1); //descometado y añadido + 1 para que se copie el \0 al final de b
	return (ret);
}
//Cuando ejecute tester.sh comentar main
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Uso: %s <arquivo_para_ler>\n", argv[0]);
        return 1;
    }

	// Abrimos argv[1]
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) // Cubrimos que sea negativo
    {
        perror("Error: no se puede abrir el archivo");
        return 1;
    }

    char *line;
    int count = 0;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Linea %d: %s", count + 1, line);
		free(line); // Podemos liberar directamente despues de generarla, aunque no se entrega main
		count++;
	}

    close(fd);
    return 0;
}





//Esta función no CREO que sea la correcta,
//pero es la que me explica la IA
/* 
void	*ft_memmove(void *dest, const void *src, int n)
{
	int		i;
	char	*d;
	char	*s;

	if (!dest || !src)
		return (dest);
	d = (char *)dest;
	s = (char *)src;
	if (d > s)
	{
		i = n - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}*/