
/*
Los operadores >> y << son operadores de desplazamiento de bits 
("bit shift operators"). 
Se utilizan para mover los bits de una variable 
hacia la derecha o hacia la izquierda. 

//DESPLAZAMIENTO A LA IZQUIERDA    <<
* Ejemplo:
unsigned char a = 5;    // Binario: 00000101
unsigned char b = a << 1; // Resultado: 00001010 (es 10 en decimal)
* Interpretación: 
Cada desplazamiento a la izquierda equivale a multiplicar por 2.

//DESPLAZAMIENTO A LA DERECHA   >>
Desplaza los bits de a n posiciones hacia la derecha.
Para tipos sin signo (unsigned), se rellenan ceros por la izquierda
Para tipos con signo (int), depende del compilador: 
puede rellenar con ceros o con el bit de signo (esto se llama desplazamiento aritmético)
* Ejemplo con unsigned:
unsigned char a = 20;   // Binario: 00010100
unsigned char b = a >> 2; // Resultado: 00000101 (es 5 en decimal)
*Interpretación:
Cada desplazamiento a la derecha equivale a dividir entre 2 (para números positivos sin signo)

RESUMEN:
Operador	Acción	                        Efecto Matemático
<< n	    Desplaza a la izquierda	        Multiplica por 2ⁿ
>> n	    Desplaza a la derecha	        Divide entre 2ⁿ (aprox)

 */

#include <stdio.h>

int main() 
{
    unsigned char a = 5;        // 00000101 en binario
    unsigned char b = a << 1;   // Desplaza a la izquierda (multiplica por 2)
    unsigned char c = a << 2;   // Multiplica por 4
    unsigned char x = a << 7;   // Multiplica por 
    unsigned char j = a << 9;   // Multiplica por 

    unsigned char d = 20;       // 00010100 en binario
    unsigned char e = d >> 1;   // Divide entre 2
    unsigned char f = d >> 2;   // Divide entre 4
    unsigned char y = d >> 7;   // Divide por 
    unsigned char z = d >> 9;   // Divide por 



    printf("a:     = %u\n", a);
    printf("b: a << 1 = %u\n", b);
    printf("c: a << 2 = %u\n", c);
    printf("x: a << 7 = %u\n", x);
    printf("j: a << 9 = %u\n", j);


    printf("d:     = %u\n", d);
    printf("e: d >> 1 = %u\n", e);
    printf("f: d >> 2 = %u\n", f);
    printf("y: d >> 7 = %u\n", y);
    printf("z: d >> 9 = %u\n", z);



    return (0);
}
/* RESULTADO MAIN

a:  5 → 00000101
b:  5 << 1 es 00000101 → 00001010 = 10
c:  5 << 2 es 00000101 → 00010100 = 20
x:  5 << 7 es 00000101 → 10000000 = 128
j:  5 << 9 es 00000101 → 00000000 = 0. (ya que todos son 0)

d:  20 → 00010100
e:  20 >> 1 es 00010100 → 00001010 = 10
f:  20 >> 2 es 00010100 → 00000101 = 5
y:  20 >> 7 es 00010100 →  = FALTA CALCULAR
z:  20 >> 9 es 00010100 →  = FALTA CALCULAR

*/
/*
Operación	    Resultado matemático	    Resultado guardado en unsigned char
5 << 7	        640                         128 (por desbordamiento)
5 << 9	        2560                        0 (porque los últimos 8 bits son todos ceros)

Explicacion:

Aunque matemáticamente:
5 * 2^7 = 5 * 128 = 640
5 * 2^9 = 5 * 512 = 2560

Como es de tipo unsigned char, 
solo puede guardar valores de 0 a 255, 
y solo los últimos 8 bits del resultado se conservan, 
así que:

x = 640 % 256 = 128
j = 2560 en binario = 00001010 00000000
Últimos 8 bits:                ↑↑↑↑↑↑↑↑
*/