#include "libft4.h"
/*
Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.
A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.
Your function must be declared as follows:
char    **ft_split(char *str);
*/

// Verificar si un carácter es un delimitador (espacio, tabulación o salto de línea)
int is_delimiter(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

// Cuenta cuántas palabras hay en la cadena
int count_words(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i])
    {
        // Saltar delimitadores
        while (str[i] && is_delimiter(str[i]))
            i++;
        // Si encontramos una palabra
        if (str[i])
        {
            count++;
            // Avanzar hasta el final de la palabra
            while (str[i] && !is_delimiter(str[i]))
                i++;
        }
    }
    return (count);
}

// Reserva memoria y copia una palabra desde 'start' hasta 'end'
char *malloc_word(char *str, int start, int end)
{
    int len = end - start;
    char *word = malloc(len + 1);
    int i = 0;

    while (start < end)
    {
        word[i] = str[start];
        i++;
        start++;
    }
    word[i] = '\0';
    return (word);
}

// Función principal: divide el string en palabras
char    **ft_split(char *str)
{
    int i = 0; 
    int j = 0; 
    int start = 0;
    int word_count = count_words(str);
    char **result = malloc(sizeof(char *) * (word_count + 1));

    while (str[i])
    {
        // Saltar delimitadores
        while (str[i] && is_delimiter(str[i]))
            i++;
        start = i;
        // Encontrar el final de la palabra
        while (str[i] && !is_delimiter(str[i]))
            i++;
        // Si se encontró una palabra, copiarla
        if (i > start)
        {
            result[j] = malloc_word(str, start, i);
            j++;
        }
    }
    result[j] = NULL;
    return (result);
}

//MAIN PARA PROBAR 
int main(void)
{
    char **word = ft_split("Una\tfrase para\n probar como funciona");
    int i = 0;
    while (word[i])
    {
        printf("Word %d: %s\n", i, word[i]);
        free(word[i]);
        i++;
    }
    free(word);
    return (0);
}