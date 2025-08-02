#include "libft3.h"

/*
Write a program that takes one or more strings and, for each argument, puts
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.
A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.
A letter is a character in the set [a-zA-Z]
If there are no parameters, display \n.
Examples:
$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>
*/

int ft_isspace(char c)
{
    if (c <= 32)
        return (1);
    return (0);
}

void rstr_capitalizer(char *str)
{
    int i = 0;
    while (str[i])
    {
         // If the character is uppercase, make it lowercase
         if (str[i] >= 'A' && str[i] <= 'Z')
             str[i] += 32;
         // Now check for lowercase character and if the next char
         // is a space character, make it uppercase again
         if ((str[i] >= 'a' && str[i] <= 'z') && ft_isspace(str[i + 1]))
             str[i] -= 32;
         // Now print every char
         write(1, &str[i], 1);
         i++;
         //ft_putchar(str[i++]);
    }
}

int main(int argc, char **argv)
{
    int i = 1;
    if (argc == 1)
        write(1, "\n", 1);
    else
    {
        while (i < argc)
        {
            rstr_capitalizer(argv[i]);
            write(1, "\n", 1);
            i++;
        } 
    }
}