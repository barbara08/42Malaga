#include "libft2.h"
/*
Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.
A snake_case string is a string where each word is in lower case, separated by
an underscore "_".
A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.
Examples:
$>./snake_to_camel "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./snake_to_camel "hello_world" | cat -e
helloWorld$
$>./snake_to_camel | cat -e
$
Allowed functions: malloc, free, realloc, write
*/

/*
int main(int argc, char **argv)
{
    if(argc == 2)
    {
        int i = 0;
        int capitalize = 0;
        char c;

        while(argv[1][i])
        {
            if(argv[1][i] == '_')
                capitalize = 1;
            else
            {
                if(capitalize && argv[1][i] >= 'a' && argv[1][i] <= 'z')
                {
                    c = argv[1][i] - 32;
                    write(1, &c, 1);
                    capitalize = 0;
                }
                else
                {
                    write(1, &argv[1][i], 1);
                    capitalize = 0;
                }
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
} 
*/
// Con función aux ya que se pasa de 25 lineas

void ft_putchar(char c)
{
    write(1, &c, 1);
}

char to_upper(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return (c);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        int capitalize = 0;

        while (argv[1][i])
        {
            if (argv[1][i] == '_')
                capitalize = 1;
            else
            {
                if (capitalize)
                {
                    ft_putchar(to_upper(argv[1][i]));
                    capitalize = 0;
                }
                else
                    ft_putchar(argv[1][i]);
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}