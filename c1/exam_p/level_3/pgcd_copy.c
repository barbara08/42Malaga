#include "libft3.h"
/*
Write a program that takes two strings representing two strictly positive
integers that fit in an int.
Display their highest common denominator followed by a newline (It's always a
strictly positive integer).
If the number of parameters is not 2, display a newline.
Examples:
$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
Allowed functions: printf, atoi, malloc, free
*/


int main(int argc, char **argv)
{
    if(argc == 3)
    {
        int n1 = atoi(argv[1]);
        int n2 = atoi(argv[2]);

        int dividendo1 =n1;
        int dividendo2=n2;
        int divisor;
        if (n1>n2){
            divisor=n2;
        }else{
            divisor=n1;
        }
        while (divisor > 0){
            if (dividendo1 % divisor == 0)
            {
                if (dividendo2 % divisor == 0)
                {
                    printf("este numero %d es el divisor maximo", divisor);
                    break;
                }
            }
            divisor--;
        }
        printf("he salido y el divisor maximo es el %d", divisor);
    }
    return(0);
}