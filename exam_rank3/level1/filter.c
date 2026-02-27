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

/* Para ejecutar el tester.sh 

./tester.sh "echo 'abcdefaaaabcdeabcabcdabc' | ./filter abc | cat -e"

*/

int	main(int argc, char **argv)
{
	char    read_buf[BUFFER_SIZE]; //buffer temporal para cada read, no se garantiza que contenga una coincidencia completa
	char    *buf = NULL; //buffer dinámico para almacenar lo leído
	size_t  s_len = 0; //longitud actual de s, guarda cuántos bytes válidos hay en buf.
	ssize_t bytes; //bytes leídos en cada read
	size_t  str_len; //longitud de la cadena a filtrar, len de argv[1]
	char    *pos; //ptr apaunta a la primera ocurrencia del patrón dentro de buf
	size_t  i; //contador para escribir los '*' sin riesgo de cortar una coincidencia

	char *tmp; //ptr para realloc (para evitar perder el buffer original en caso de error)
	size_t before; //Número de bytes antes de la coincidencia encontrada.
	size_t safe; //Cantidad de bytes seguros para escribir (sin riesgo de cortar una coincidencia)

	/* Validación de argumentos */
	if (argc != 2 || argv[1][0] == '\0')
		return 1;

	str_len = strlen(argv[1]);

	/* Lectura de stdin */
		/* Lee stdin por bloques */
	while ((bytes = read(0, read_buf, BUFFER_SIZE)) > 0)
	{
		/* Amplía buf para añadir lo recién leído */
		tmp = realloc(buf, s_len + bytes);
		if (!tmp)
		{
			fprintf(stderr, "Error: ");
			perror(NULL);
			free(buf);
			return 1;
		}
		/* Copia lo leído al final del buffer acumulado */
		buf = tmp;
		memmove(buf + s_len, read_buf, bytes);
		s_len += bytes;

		/* Reemplazar coincidencias completas */
			/* Busca coincidencias completas, incluso si vienen de reads distintos */
		while ((pos = memmem(buf, s_len, argv[1], str_len)))
		{
			/* Calcula cuántos bytes hay antes del patrón */
			before = pos - buf;
			
			/* Escribe lo que está antes de la coincidencia */
			if (before > 0)
				write(1, buf, before);

			/* Sustituye el patrón por '*' directamente */
			i = 0;
			while (i < str_len)
			{
				write(1, "*", 1);
				i++;
			}

			/* Mover el buffer para eliminar lo escrito */
			memmove(buf, pos + str_len, s_len - before - str_len);
			s_len -= before + str_len;
		}

		/* Escribir parte segura */
			/* Si hay suficiente buffer para una coincidencia futura… */
		if (s_len >= str_len)
		{
			/* Deja los últimos str_len - 1 bytes */
			/* podrían ser el inicio de una coincidencia cortada */
			safe = s_len - (str_len - 1);
			/* Escribe lo que es seguro */
			write(1, buf, safe);
			/* Conserva solo la parte peligrosa */
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
		/* Vacía el buffer final (no puede haber coincidencias incompletas ya) */
	if (s_len > 0)
		write(1, buf, s_len);

	free(buf);
	return (0);
}

/*

EXPLICACION DE LAS VARIABLES:

"hola bmb que tal" | ./filter bmb
Result => hola *** que tal$

BUFER_SIZE => es el tamaño del bloque de lectura, 
	lo que se lee en cada read. 
	No tiene que ver con el tamaño del patrón a filtrar 
	ni con el tamaño del buffer dinámico.

BUFFER_SIZE = 4
argv[1] = "bmb"
str_len = 3
stdin = "holabmbquetal"

char    read_buf[BUFFER_SIZE]; //buffer temporal para cada read, no se garantiza que contenga una coincidencia completa
char    *buf = NULL; //buffer dinámico para almacenar lo leído
size_t  s_len = 0; //longitud actual de s, guarda cuántos bytes válidos hay en buf.
ssize_t bytes; //bytes leídos en cada read
size_t  str_len; //longitud de la cadena a filtrar, len de argv[1]
char    *pos; //ptr apaunta a la primera ocurrencia del patrón dentro de buf
size_t  i; //contador para escribir los '*' sin riesgo de cortar una coincidencia

char *tmp; //ptr para realloc (para evitar perder el buffer original en caso de error)
size_t before; //Número de bytes antes de la coincidencia encontrada.
size_t safe; //Cantidad de bytes seguros para escribir (sin riesgo de cortar una coincidencia)

Cambios de nombres de variables:

read_buffer => bloque
buffer => acumulado
buffer_len => acumulado_len (s_len)
read_bytes => leidos
argv1_len => filtro_len (str_len)
pos_buffer => encontrado 

before_bytes_ocurrence
safe_bytes_to_write

*/
