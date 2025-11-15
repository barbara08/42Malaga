#include "../level.h"

/*
Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.
Your function must be declared as follows:
unsigned char	swap_bits(unsigned char octet);
Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
*/

unsigned char swap_bits(unsigned char octet)
{
	return((octet >> 4 | octet << 4));
}

int main()
{
    unsigned char octet = 15;
    unsigned char s_b = swap_bits(octet);  
    printf("octect: %u\n", octet);  //15
    printf("s_b: %u\n", s_b);  //240
    //print_bits(s_b);  // 240  => 11110000

    return(0);
}