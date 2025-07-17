#include "libft3.h"

/*
Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.
If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.
Yes, the examples are right.
Examples:
$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

//return(0) => NO es primo
//return(1) => SI es primo
int is_prime(int n)
{
    int i = 2;
    if (n < 2)
        return(0);
    while (i * i <= n)
    {
        if(n % i == 0)
            return(0);
        i++;
    }
    return(1);
}










