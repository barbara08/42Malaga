#include "libft2.h"
/*
Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.
Your function must be declared as follows:
void	print_bits(unsigned char octet);
Example, if you pass 2 to print_bits, it will print "00000010"
 */

 void ft_putchar(char c)
{
    write(1, &c, 1);
}

void print_bits(unsigned char octet)
{
    int i = 8; // Contador a 8, ya que son 8 bits
    unsigned char bit = 0; // Inicializar bit a 0, para almacenar el bit actual

    while (i--) // Mientras i sea mayor que 0 (empezando con i = 8 y disminuyendo hasta 0)
    {
        bit = (octet >> i & 1) + 48; 
        write (1, &bit, 1); 
    }
}

/* EXPLICACION
(octet >> i & 1)
octet >> i desplaza los bits del byte octet hacia la derecha i posiciones.
Luego, se hace un AND bit a bit con 1 para aislar el bit menos significativo en esa posición.
Esto obtiene el valor del bit en la posición i (de izquierda a derecha).
+ 48
El valor del bit será 0 o 1.
Se suma 48 porque en ASCII el carácter '0' tiene el valor decimal 48 y '1' tiene 49.
Así convertimos el número 0 o 1 en su representación de carácter ASCII para imprimirlo.
*/

// OTRA FORMA
void printt_bitss(unsigned char octet)
{
    //Creamos una máscara con un 1 en el bit más alto (el bit 7). Por ejemplo: 10000000
    unsigned char mask = 1 << 7;  // Máscara para el bit más significativo (bit 7)
    int i = 0;

    while (i < 8) 
    {
        //Hacemos una operación AND para saber si el bit actual es 1 o 0
        if ((octet & mask) != 0)  // Comprobamos si el bit actual es 1
            ft_putchar('1');
        else
            ft_putchar('0');
        //Corremos la máscara un bit hacia la derecha para verificar el siguiente bit
        mask >>= 1;  // Movemos la máscara un bit a la derecha
        i++;
    }
    // NO ponemos salto de línea (no hay '\n')
}

int main() {
    unsigned char n = 10;
    /* 
    2  => 00000010
    5  => 00000101
    10 => 00001010
    */

    print_bits(n);
    ft_putchar('\n');
    printt_bitss(n);

    return (0);
}