#include "libft3.h"

/*
Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.
A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.
If there are no arguments, the progam must display \n.
Example:
$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>
*/
//CON VARIOS ARG COMO PIDE SUBJET
int main(int argc, char **argv)
{
    int i = 1;
    if(argc == 1)
        write(1, "\n", 1);
    else
    {
        while (i < argc)
        {
            int j = 0;
            while (argv[i][j])
            {
                if(argv[i][j] >= 'A' && argv[i][j] <= 'Z')
                    argv[i][j] += 32;
                if((argv[i][j] >= 'a' && argv[i][j] <= 'z') && (argv[i][j - 1] == ' ' || argv[i][j - 1] == '\0'))
                    argv[i][j] -= 32;
                write(1, &argv[i][j], 1);
                j++;
            }
            write(1, " ", 1);
            i++;
        }
    }
    return(0);
}

/* SOLO UN ARG
int main(int argc, char **argv)
{
    int i = 0;
    if(argc == 2)
    {
            while (argv[1][i])
            {
                if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                    argv[1][i] += 32;
                if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') && (argv[1][i + 1] == ' ' || argv[1][i + 1] == '\0'))
                    argv[1][i] -= 32;
                write(1, &argv[1][i], 1);
                i++;
            }
    }
    return(0);    
}*/

/* MAS LARGO Y FUNCIONES AUXILIARES
int ft_isspace(char c)
{
    if (c <= 32)
        return(1);
    return(0);
}

void str_capitalizer(char *str)
{
    int i = 0;
    while(str[i])
    {
        //De mayúscula a minúsculas
        if(str[i] >= 'A' && str[i] <=  'Z')
            str[i] += 32;
        //Convierte la letra minúscula str[i] a mayúscula solo si:
            //str[i] es una letra minúscula ('a' a 'z'), y
            //El carácter anterior (str[i - 1]) es un espacio en blanco (detectado con ft_isspace).
        if((str[i] >= 'a' && str[i] <= 'z') && ft_isspace(str[i - 1]))
            str[i] -= 32;
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i = 1;
    if(argc == 1)
        write(1, "\n", 1);
    else
    {
        while(i < argc)
        {
            str_capitalizer(argv[i]);
            write(1, "\n", 1);
            i++;
        }
    }
    return(0);
}
    */