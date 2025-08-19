#include <unistd.h>
#include <stdio.h>
/*
Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.
'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...
Case remains unchanged.
If the number of arguments is not 1, just display a newline.

Examples:
$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        while(argv[1][i])
        {
            int n = 1;
            if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
                n = argv[1][i] - 'a' + 1;
            else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                n = argv[1][i] - 'A' + 1;
            while (n > 0)
            {
                write(1, &argv[1][i], 1);
                n--;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return(0);
}
