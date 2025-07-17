#include "libft3.h"

/*
Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.
A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.
If the number of parameters is not 1, or if there are no words, simply display
a newline.
Examples:
$> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$>
*/

int is_space(char c)
{
    if (c <= 32)
        return 1;
    return (0);
}

int main(int ac, char **argv)
{
    if (ac == 2)
    {
        int i = 0; 
        int space = 0;
        while (is_space(argv[1][i]))
            i++;
        while (argv[1][i])
        {
            if (is_space(argv[1][i]))
                 space = 1;
            if (!is_space(argv[1][i]))
            {
                if (space)
                    write(1, "   ", 3);
                space = 0;
                write(1, &argv[1][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}