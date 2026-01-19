
#include <stdio.h>
/* 
unsigned int g = (a > b) ? a : b;

unsigned int g;
Declara una variable g de tipo unsigned int (entero sin signo).

(a > b) ? a : b;
Esta es una expresión condicional o "ternaria":

Si a > b, entonces el resultado es a.
Si no, el resultado es b.
------------------------------------------------
//ESTO:
unsigned int g = (a > b) ? a : b;

//ES LO MISMO QUE:
if (a > b)
    g = a;
else
    g = b;
-------------------------------------------------

(a > b)	Condición: ¿a es mayor que b?
? a	Si sí → usa a
: b	Si no → usa b
g = ...	Asigna el resultado a g

*/

int main()
{
	unsigned int a = 10;
	unsigned int b = 20;

	unsigned int g = (a > b) ? a : b;
	// Como 10 > 20 es falso, g = b = 20
	printf("Result: %d", g);
	return(0);
}