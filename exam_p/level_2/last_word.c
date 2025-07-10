
#include "libft2.h"
/* display => mostrar
Write a program that takes a string and displays its last word followed by a \n.
A word is a section of string delimited by spaces/tabs or by the start/end of
the string.
If the number of parameters is not 1, or there are no words, display a newline.
Example:
$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        int i = 0;
        //1. Recorrer el str hasta el final
        while(argv[1][i])
        {
            i++;
            //printf("1. i vale: %d\n", i);
        }
        i--;
        //printf("1. i vale: %d\n", i);
        //2. Recorrer str hacia atrás hasta encontrar spaces/tabs
        while(argv[1][i] > 32)
        {
            i--;
            //printf("2. i vale: %d\n", i);
        }
        i++;
        //printf("2. i vale: %d\n", i);
        //3. Volver al final de str y write la última palabra
        while(argv[1][i])
        {
            write(1, &argv[1][i], 1);
            i++;
            //printf("3. i vale: %d\n", i);

        }
        //printf("3. i vale: %d\n", i);

    }
    write(1, "\n", 1);
    return(0);
}


