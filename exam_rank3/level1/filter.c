#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

//cc -Wall -Wextra -Werror filter.c -o filter
//echo "ababcabababc" | ./filter ababc | cat -e
//Result => *****ab*****$
//echo 'abcdefaaaabcdeabcabcdabc' | ./filter abc | cat -e
//Result => ***defaaa***de******d***$

/* 
echo "ababcabababc" | ./filter ababc | cat -e
Result => *****ab*****$
echo 'abcdefaaaabcdeabcabcdabc' | ./filter abc | cat -e
Result => ***defaaa***de******d***$
echo "holabmbmbxbm1b" | ./filter bmb 
Result => hola***mbxbm1b$
echo "hola bmb que tal" | ./filter bmb 
Result => hola *** que tal$
*/

int	main(int argc, char **argv)
{
	char    read_buf[BUFFER_SIZE]; //buffer temporal para cada read, no se garantiza que contenga una coincidencia completa
	char    *buf = NULL; //buffer dinámico para almacenar lo leído
	size_t  s_len = 0; //longitud actual de s
	ssize_t bytes; //bytes leídos en cada read
	size_t  str_len; //longitud de la cadena a filtrar, len de argv[1]
	char    *pos; //ptr a la primera ocurrencia de target en buf
	size_t  i; //contador para escribir los '*' sin riesgo de cortar una coincidencia

	char *tmp; //ptr para realloc
	size_t before; //bytes antes de la ocurrencia encontrada
	size_t safe; //bytes seguros para escribir (sin riesgo de cortar una coincidencia)

	/* Validación de argumentos */
	if (argc != 2 || argv[1][0] == '\0')
		return 1;

	str_len = strlen(argv[1]);

	/* Lectura de stdin */
	while ((bytes = read(0, read_buf, BUFFER_SIZE)) > 0)
	{
		tmp = realloc(buf, s_len + bytes);
		if (!tmp)
		{
			fprintf(stderr, "Error: ");
			perror(NULL);
			free(buf);
			return 1;
		}
		buf = tmp;
		memmove(buf + s_len, read_buf, bytes);
		s_len += bytes;

		/* Reemplazar coincidencias completas */
		while ((pos = memmem(buf, s_len, argv[1], str_len)))
		{
			before = pos - buf;

			if (before > 0)
				write(1, buf, before);

			/* Escribir los '*' directamente */
			i = 0;
			while (i < str_len)
			{
				write(1, "*", 1);
				i++;
			}

			memmove(buf, pos + str_len, s_len - before - str_len);
			s_len -= before + str_len;
		}

		/* Escribir parte segura */
		if (s_len >= str_len)
		{
			safe = s_len - (str_len - 1);
			write(1, buf, safe);
			memmove(buf, buf + safe, s_len - safe);
			s_len -= safe;
		}
	}

	/* Error de read */
	if (bytes < 0)
	{
		fprintf(stderr, "Error: ");
		perror(NULL);
		free(buf);
		return 1;
	}

	/* Escribir lo que quede */
	if (s_len > 0)
		write(1, buf, s_len);

	free(buf);
	return (0);
}

