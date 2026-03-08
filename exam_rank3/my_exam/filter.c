#define _GNU_SOURCE 	// Te lo dan (va junto string.h) (para memmem)
#include <string.h> 	// (strlen, memmem, memmove)
#include <errno.h> 		// Te lo dan (errno)
#include <unistd.h> 	// (read, write)
#include <stdlib.h> 	// (realloc, free)
#include <stdio.h> 		// (perror, fprintf)
//#include <fcntl.h> 	// No se necesita (no se van a usar open ni close)

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
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
	char read_buffer[BUFFER_SIZE];  //buffer temporal para leer de stdin por bloques, de tamaño fijo (BUFFER_SIZE)
	char *buffer = NULL; //buffer dinámico que irá acumulando lo leído, se va ampliando con realloc 
	char *pos_buffer; //puntero que se usará para buscar las ocurrencias de argv[1] en buffer con memmem
	size_t buffer_len = 0; //len de buffer, guarda cuántos bytes válidos hay en buffer
		//arg 
	size_t argv1_len; //len de "bmb" => 3
		//bytes
	ssize_t read_bytes; //bytes leídos en cada read
	size_t before_bytes_ocurrence; //bytes que hay antes de la ocurrencia encontrada, se calcula restando pos_buffer - buffer
	size_t safe_bytes_to_write; //bytes que se pueden escribir de buffer sin riesgo de cortar una coincidencia, se calcula restando buffer_len - (argv1_len - 1)
		//iterador
	size_t i; // para los *
		//realloc
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
			//fprintf(stderr, "Error: ");
			//perror(NULL);
			perror("Error"); //perror ya añade ": ", Las 2 lineas anteriores son equivalentes, pero esta es más concisa
			free(buffer);
			return (1);
		}
		buffer = tmp;

		/* 4.2. Copiar los bytes leídos al buffer */
		memmove(buffer + buffer_len, read_buffer, read_bytes);
		//printf("\n\n");
		buffer_len += read_bytes;
		//printf("Buffer after read: '%.*s'\n", (int)buffer_len, buffer);
		//printf("Buffer_len: %zu\n", buffer_len);

		/* 4.3. Reemplazar las ocurrencias por *  */
			/* SOLO SE EJECUTA CUANDO  SI HAY  coincidencia */
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
			/* SOLO SE EJECUTA CUANDO  NO HAY  coincidencia */
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
		//fprintf(stderr, "Error: ");
		//perror(NULL);
		perror("Error");
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

