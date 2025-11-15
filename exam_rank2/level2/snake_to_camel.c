#include "../level.h"

/*
Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

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
*/

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        int i = 0;
        int underscore = 0;
        char c;

        while (argv[1][i])
        {
            if(argv[1][i] == '_')
                underscore = 1;
            else
            {
                if (i == 0 && argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                {
                    // convertir primera letra a minúscula
                    c = argv[1][i] + 32;
                    write(1, &c, 1);
                }
                else if(underscore && argv[1][i] >= 'a' && argv[1][i] <= 'z')
                {
                    c = argv[1][i] - 32;
                    write(1, &c, 1);
                }
                else
                    write(1, &argv[1][i], 1);
                
                underscore = 0;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return(0);
}