#include "libft2.h"
/*
Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.
Your function must be declared as follows:
void	print_bits(unsigned char octet);
Example, if you pass 2 to print_bits, it will print "00000010"
Explciación del código en el file explicacion_print_bits.c
 */

void print_bits(unsigned char octet)
{
    int i = 8; 
    unsigned char bit = 0;
    printf("octect: %u\n", octet);

    while (i--)
    {
        bit = (octet >> i & 1) + 48; 
        //printf("bit: %d %u\n", i, octet >> i );
        write (1, &bit, 1);
    }
}

// FUNCION IMPREME LA SALIDA CON SEPARACION EJ: 0000 1010 EN VEZ DE 00001010
void print_bits_separate(unsigned char octet)
{
    int i = 8;
    unsigned char bit;

    printf("octet: %u\n", octet);
    while (i--)
    {
        bit = ((octet >> i) & 1) + '0';
        write(1, &bit, 1);

        if (i == 4)
            write(1, " ", 1);
    }
    //write(1, "\n", 1); // No lo pide, no se pone
}
/* 
int main() 
{
    unsigned char n = 44;
     
    2  => 00000010
    5  => 00000101
    10 => 00001010
    20 => 00010100
    23 => 00010111
    

    print_bits(n);
    write(1, "\n", 1);
    print_bits_separate(n);

    return (0);
}
*/