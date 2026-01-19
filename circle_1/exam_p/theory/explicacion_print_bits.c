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
    printf("octect: %u\n", octet);

    while (i--) // Recorre desde el bit 7 al bit 0
    {
        bit = (octet >> i & 1) + 48;  // Extrae el bit actual y lo convierte a carácter ('0' o '1')
        //printf("bit: %d %u\n", i, octet >> i );
        write (1, &bit, 1); // Escribimos el carácter directamente en la salida estándar
    }
}
/* EXPLICACION
Todos los números en C se almacenan como binarios internamente, 
aunque los escribamos en decimal, octal o hexadecimal. 
La conversión a binario ya está hecha automáticamente.

unsigned char octet = 44;
Internamente: 00101100

El bucle hace esto:

i (bit pos)	        octet >> i (binario automático)	      (>> i) & 1 (última columana derecha)                Bit imprimido
7	                    00000000	                        0   (0 + 48 = 48) Equivale al '0'    =>              '0'
6	                    00000000	                        0	(0 + 48 = 48) Equivale al '0'    =>              '0'
5	                    00000001	                        1	(1 + 48 = 49) Equivale al '1'    =>              '1'
4	                    00000010	                        0	(0 + 48 = 48) Equivale al '0'    =>              '0'
3	                    00000101	                        1	(1 + 48 = 49) Equivale al '1'    =>              '1'
2	                    00001011	                        1	(1 + 48 = 49) Equivale al '1'    =>              '1'
1	                    00010110	                        0	(0 + 48 = 48) Equivale al '0'    =>              '0'
0	                    00101100	                        0	(0 + 48 = 48) Equivale al '0'    =>              '0'

Y en pantalla ves:
00101100

CALCULO:
(octet >> i & 1)
octet >> i desplaza los bits del byte octet hacia la derecha i posiciones.
Luego, se hace un AND bit a bit con 1 para aislar el bit menos significativo en esa posición (última columna derecha)
Esto obtiene el valor del bit en la posición i (de izquierda a derecha) + 48 = el valor del bit que será 0 o 1.
Se suma 48 porque en ASCII el carácter '0' tiene el valor decimal 48 y '1' tiene 49.
Así convertimos el número 0 o 1 en su representación de carácter ASCII para imprimirlo.
*/

// OTRA FORMA
void printt_bitss(unsigned char octet)
{
    //Creamos una máscara con un 1 en el bit más alto (el bit 7). Por ejemplo: 10000000
    unsigned char mask = 1 << 7;  // Máscara para el bit más significativo (bit 7)
    int i = 0;

    printf("octect: %u\n", octet);
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

        if (i == 4) // Justo después del 4° bit (desde la izquierda), inserta un espacio
            write(1, " ", 1);
    }
    write(1, "\n", 1); // Salto de línea al final
}

int main() 
{
    unsigned char n = 44;
    /* 
    2  => 00000010
    5  => 00000101
    10 => 00001010
    20 => 00010100
    23 => 00010111
    */

    print_bits(n);
    ft_putchar('\n');
    printt_bitss(n);
    ft_putchar('\n');
    print_bits_separate(n);

    return (0);
}

