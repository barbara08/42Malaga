#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1042
#endif

int main(int argc, char **argv)
{
    // Validación estricta de argumentos
    if (argc != 2 || argv[1][0] == '\0') {
        return 1;
    }

    char *s = argv[1];
    size_t s_len = strlen(s);
    char *data = NULL;
    size_t data_len = 0;
    char buffer[BUFFER_SIZE];
    ssize_t n;

	char *new_data;
	size_t i;
    char *found;
	size_t count;
	size_t processed_offset;
	size_t remaining_after;


    // Bucle principal de lectura de stdin
    while ((n = read(0, buffer, sizeof(buffer))) > 0) {
        // Expandir memoria para acumular lo leído
        new_data = realloc(data, data_len + n);
        if (!new_data) {
            fprintf(stderr, "Error: malloc failed\n");
            free(data);
            return 1;
        }
        data = new_data;
        
        // Copiar lo nuevo al final del buffer acumulado
        i = 0;
        while (i < (size_t)n) {
            data[data_len + i] = buffer[i];
            i++;
        }
        data_len += n;

        // Buscar y reemplazar el patrón mientras exista en data
        while ((found = memmem(data, data_len, s, s_len)) != NULL) {
            // 1. Escribir lo que hay antes de la coincidencia
            write(1, data, found - data);

            // 2. Escribir asteriscos (usando while en lugar de for)
            count = 0;
            while (count < s_len) {
                write(1, "*", 1);
                count++;
            }

            // 3. Mover el resto del buffer hacia adelante
            processed_offset = (found - data) + s_len;
            remaining_after = data_len - processed_offset;
            memmove(data, data + processed_offset, remaining_after);
            data_len = remaining_after;
        }
    }

    if (n < 0) {
        fprintf(stderr, "Error: read failed\n");
        free(data);
        return 1;
    }

    // Escribir el remanente que no llegó a formar un patrón completo
    if (data_len > 0) {
        write(1, data, data_len);
    }

    free(data);
    return 0;
}
	