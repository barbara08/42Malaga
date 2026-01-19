#include "../level.h"
/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.
Your function must be declared as follows:
unsigned char	reverse_bits(unsigned char octet);
Example:

  1 byte
_____________
 0010  0110
     ||
     \/
 0110  0100
*/

unsigned char reverse_bits(unsigned char octet)
{
	unsigned char r_v = 0;
	int i = 8;

	while (i--)
	{
		r_v = (r_v << 1) | (octet & 1);
		octet >>= 1;
	}
	return(r_v);
}
//Solo para mostrar el resultado en bit, NO LO PIDEN
void print_bits(unsigned char octet)
{
    int i = 8; 
    unsigned char bit = 0;
    printf("octect: %u\n", octet);

    while (i--)
    {
        bit = (octet >> i & 1) + 48; 
        write (1, &bit, 1);
    }
}

int main()
{
	/* Results:
	2  => 00000010 => 64  => 01000000
	5  => 00000101
	10 => 00001010
	20 => 00010100
	23 => 00010111
	42 => 00101010 => 84  => 01010100
	45 => 00101101 => 180 => 10110100
	*/
	unsigned char octet = 2;
	unsigned char reverted = reverse_bits(octet);

	printf("Decimal:\n");
	printf("octet: %u\n", octet);
	printf("Reverted: %u\n", reverted);

	printf("Binary:\n");
	print_bits(octet);
	printf("\n");
	print_bits(reverted);

	return (0);
}