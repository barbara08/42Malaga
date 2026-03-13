#include "../level.h"
/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.
Your function must be declared as follows:
void	print_bits(unsigned char octet);
Example, if you pass 2 to print_bits, it will print "00000010"
*/

void print_bits(unsigned char octet)
{
	int i = 8;
	int bit = 0;

	while (i--)
	{
		bit = (octet >> i & 1) + 48;
		write(1, &bit, 1);
		/* Si queremos separlos en 4 => 0001 0111 (no lo pide)
		if (i == 4)
            write(1, " ", 1);
		*/
	}
}
int main() 
{
	unsigned char n = 23;
	/* Results:
	2  => 00000010
	5  => 00000101
	10 => 00001010
	20 => 00010100
	23 => 00010111
	42 => 00101010
	*/

	print_bits(n);
	write(1, "\n", 1);

	return (0);
}