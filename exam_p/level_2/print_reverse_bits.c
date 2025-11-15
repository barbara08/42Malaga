#include "libft2.h"

//Función inventada por mi

/* Write a function that takes a byte, reverses it, bit by bit 
returns the result, and prints it in binary WITHOUT A NEWLINE
AT THE END.
(like the example)

Example:
  1 byte
_____________
 0010  0110
     ||
     \/
 0110  0100

 */

unsigned char print_reverse_bits(unsigned char octet)
{
    int i = 8;
    unsigned char bit_print_verted = 0;
    unsigned char bit;

    while(i--)
    {
        bit_print_verted = (bit_print_verted << 1) | (octet & 1);
        octet >>= 1;
    }
    i = 8;
    while(i--)
    {
        bit = (bit_print_verted >> i & 1) + 48;
        write(1, &bit, 1);
    }
    write(1, "\n", 1);
    return(bit_print_verted);
}

int main()
{
    unsigned char octet = 23; //// 00010111
    unsigned char reverseprint = print_reverse_bits(octet);  //imprime 11101000
    printf("%u", reverseprint); // imprime 232
    return(0);
}