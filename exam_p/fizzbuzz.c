#include <stdio.h>
#include <unistd.h>

/*
Write a program that prints the numbers from 1 to 100, each separated by a
newline.
If the number is a multiple of 3, it prints 'fizz' instead.
If the number is a multiple of 5, it prints 'buzz' instead.
If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:
$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
*/

void ft_write_int(int n)
{
    char c;
    if (n >= 10)
        ft_write_int(n / 10);
    c = n % 10 + '0';
    write(1, &c, 1);
}


int main()
{
    int i = 1;
    while (i <= 100)
    {
        if ((i % 3 == 0) && (i % 5 == 0))
            write(1, "fizzbuzz", 8);
        else if(i % 3 == 0)
            write(1, "fizz", 4);
        else if(i % 5 == 0)
            write(1, "buzz", 4);
        else
            ft_write_int(i);
        i++;
        write(1, "\n", 1);
    }
    return(0);
}
