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

int	main(int argc, char **argv)
{
	char    read_buf[BUFFER_SIZE];
	char    *buf = NULL;
	size_t  buf_len = 0;
	ssize_t bytes;
	size_t  target_len;
	char    *pos;
	size_t  i;

	/* Validación de argumentos */
	if (argc != 2 || argv[1][0] == '\0')
		return 1;

	target_len = strlen(argv[1]);

	/* Lectura de stdin */
	while ((bytes = read(0, read_buf, BUFFER_SIZE)) > 0)
	{
		char *tmp = realloc(buf, buf_len + bytes);
		if (!tmp)
		{
			fprintf(stderr, "Error: ");
			perror(NULL);
			free(buf);
			return 1;
		}
		buf = tmp;
		memmove(buf + buf_len, read_buf, bytes);
		buf_len += bytes;

		/* Reemplazar coincidencias completas */
		while ((pos = memmem(buf, buf_len, argv[1], target_len)))
		{
			size_t before = pos - buf;

			if (before > 0)
				write(1, buf, before);

			/* Escribir los '*' directamente */
			i = 0;
			while (i < target_len)
			{
				write(1, "*", 1);
				i++;
			}

			memmove(buf, pos + target_len,
					buf_len - before - target_len);
			buf_len -= before + target_len;
		}

		/* Escribir parte segura */
		if (buf_len >= target_len)
		{
			size_t safe = buf_len - (target_len - 1);
			write(1, buf, safe);
			memmove(buf, buf + safe, buf_len - safe);
			buf_len -= safe;
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
	if (buf_len > 0)
		write(1, buf, buf_len);

	free(buf);
	return (0);
}
