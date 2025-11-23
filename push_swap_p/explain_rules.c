void pa(int a[], int *len_a, int b[], int *len_b);
/* rules_push.c

if (*len_b > 0)
	Antes de hacer “pa”, se verifica que B no esté vacía.
	Si B tiene al menos un elemento, se puede hacer el push

int i = *len_a;
	i empieza en la longitud actual de A.
	Ejemplo: si A tiene 4 elementos, i = 4
	Esto se usa para mover los elementos de A una posición hacia abajo

while (i > 0)
{
    a[i] = a[i - 1];
    i--;
}
	Este while desplaza todos los elementos de A hacia abajo una posición,
	para liberar el índice 0.
	Ej:
	A = [3, 7, 10, 12]
	len_a = 4
	A = [?, 3, 7, 10, 12]

a[0] = b[0];
	Se coloca el primer elemento de B en el primer lugar de A.

i = 0;
	// i se usará para recorrer B.


// Mover elementos de b hacia adelante
while (i < *len_b - 1)
{
    b[i] = b[i + 1];
    i++;
}
	Este while desplaza todos los elementos de B hacia arriba, 
	porque el primero ya fue movido a A.
	Ej:
	B = [9, 5, 2, 1]
	B = [5, 2, 1, ?]

(*len_a)++;
	Como A recibió un nuevo elemento, su longitud aumenta en 1.

(*len_b)--;
	Como B perdió un elemento, su longitud disminuye en 1.

*/

void rotate(int stack[], int len);
/* rules_rotate.c

int first;
	guardará el primer elemento del stack

first = stack[0];
	Guarda el primer elemento de la pila antes de mover nada.
	Esto es importante porque ese elemento terminará en la última posición.

while (i < len - 1)
{
    stack[i] = stack[i + 1];
    i++;
}
	Este while desplaza todos los elementos una posición hacia arriba.
	Ej:
	[3, 7, 10, 12]
	[7, 10, 12, ?]
	El último elemento queda libre momentáneamente

stack[len - 1] = first;
	Coloca el primer elemento (que guardamos en first) al final del array



*/


