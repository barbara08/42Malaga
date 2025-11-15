#include "libft3.h"

/*
Write a program that displays the number of arguments passed to it, followed by
a newline.
If there are no arguments, just display a 0 followed by a newline.
Example:
$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>
*/

int main(int argc, char **argv)
{
    int i = 0;
    (void)argv;
    if(argc < 2)
        write(1, "\n", 1);
    else
    {
        while(i < argc - 1)
            i++;
        printf("i: %d", i);
    }
    return(0);
}