#include "libft2.h"
/*
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

unsigned char	swap_bits(unsigned char octet)
{
    return((octet >> 4 | octet << 4));
}

int main()
{
    unsigned char octet = 15;
    unsigned char s_b = swap_bits(octet);  
    printf("octect: %u\n", octet);  //15
    printf("s_w: %u\n", s_b);  //240
    print_bits(s_b);  // 240  => 11110000

    return(0);
}

/*
Binario:      ABCD EFGH
Posiciones:   7654 3210

octet >> 4 → mueve los 4 bits altos a la derecha:
ABCD EFGH >> 4  →  0000 ABCD

octet << 4 → mueve los 4 bits bajos a la izquierda:
ABCD EFGH << 4  →  EFGH 0000

OR entre los dos:
0000 ABCD
 */
