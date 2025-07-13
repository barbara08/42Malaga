#include "libft2.h"
/* 
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
    unsigned char bits_reverted = 0;
    int i = 8;

    while(i--)
    {
        bits_reverted = (bits_reverted << 1) | (octet & 1);
        octet >>= 1;  //Es lo mismo:  octect = octect >> 1
    }
    return(bits_reverted);
   
}

int main()
{
    unsigned char octet = 45;
    unsigned char reverted = reverse_bits(octet);

    printf("octet: %u\n", octet);               // 45   =>   00101101
    printf("Reverted : %u\n", reverted);        // 180  =>   10110100

    return (0);
}

/* EXPLICACION:
bits_reverted comienza en 0 y se irá llenando con los bits invertidos.
El bucle while (i--) se ejecuta 8 veces (porque un byte tiene 8 bits)
En cada iteración:
bits_reverted << 1 → desplaza los bits del resultado a la izquierda para hacer espacio.
octet & 1 → toma el bit menos significativo del byte original.
Se agrega ese bit al final de bits_reverted con |
Luego octet >>= 1 → mueve los bits del byte original a la derecha para procesar el siguiente.
*/
