#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif


/* 
"hola bmb que tal" | ./filter bmb
Result => hola *** que tal$
*/
/* Tester

./tester.sh "echo 'hola bmb que tal' | ./filter bmb | cat -e"

*/

int main(int argc, char **argv)
{
	/* 1. Declaración de las variables necesarias */

		//buffer
	char read_buffer[BUFFER_SIZE];
	char *buffer = NULL;
	size_t buffer_len = 0; //len de buffer, guarda cuántos bytes válidos hay en buffer
	char *pos_buffer;
		//arg 
	size_t argv1_len; //len de "bmb" => 3
		//bytes
	ssize_t read_bytes; //bytes leídos en cada read
	size_t before_bytes_ocurrence;
	size_t safe_bytes_to_write;

	size_t i; // para los *
	char *tmp; // para realloc

	/* 2. Validación de argumentos */
	if (argc != 2 || argv[1][0] == '\0')
		return (1);
	
	/* 3. Saber len de argv[1] */
	argv1_len = strlen(argv[1]);

	/* 4. Lectura de stdin por bloques */
	while ((read_bytes = read(0, read_buffer, BUFFER_SIZE)) > 0)
	{
		/* 4.1. Ampliar buffer para añadir lo recién leído */
		tmp = realloc(buffer, buffer_len + read_bytes);
		if (!tmp)
		{
			fprintf(stderr, "Error: ");
			perror(NULL);
			free(buffer);
			return (1);
		}

		/* 4.2. Copiar los bytes leídos al buffer */
		buffer = tmp;
		memmove(buffer + buffer_len, read_buffer, read_bytes);
		buffer_len += read_bytes;

		/* 4.3. Reemplazar las ocurrencias por *  */
		while ((pos_buffer = memmem(buffer, buffer_len, argv[1], argv1_len)))
		{
			/* 4.3.1. Calcular cuántos bytes hay antes de la coincidencia */
			before_bytes_ocurrence = pos_buffer - buffer;
			/* 4.3.2. Escribir lo que está antes de la coincidencia */
			if (before_bytes_ocurrence > 0)
				write(1, buffer, before_bytes_ocurrence);
			/* 4.3.3. Escribir los '*' */
			i = 0;
			while (i < argv1_len)
			{
				write(1, "*", 1);
				i++;
			}
			/* 4.3.4. Mover el buffer para eliminar lo escrito */
			memmove(buffer, pos_buffer + argv1_len, buffer_len - before_bytes_ocurrence - argv1_len);
			buffer_len -= before_bytes_ocurrence + argv1_len;
		}

		/* 4.4. Escribir la parte segura del buffer */
		if(buffer_len >= argv1_len)
		{
			/* Calcular cuántos bytes son seguros para escribir (sin riesgo de cortar una coincidencia) */
			safe_bytes_to_write = buffer_len - (argv1_len - 1);
			/* Escribir la parte segura */
			write(1, buffer, safe_bytes_to_write);
			/* Mover el buffer para eliminar lo escrito */
			memmove(buffer, buffer + safe_bytes_to_write, buffer_len - safe_bytes_to_write);
			buffer_len -= safe_bytes_to_write;
		}
	}

	/* 5. Error de read */
	if (read_bytes < 0)
	{
		fprintf(stderr, "Error: ");
		perror(NULL);
		free(buffer);
		return 1;
	}
	/* 6. Escribir lo que quede */
		/* Vacía el buffer final (no puede haber coincidencias incompletas ya) */
	if (buffer_len > 0)
		write(1, buffer, buffer_len);

	/* 7. Liberar memoria y salir */
	free(buffer);
	return (0);

}

