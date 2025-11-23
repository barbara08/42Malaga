
void ft_sort_five(int *a, int *size_a, int *b, int *size_b);
/* 
Resumen simple del algoritmo

1. Mientras A tenga más de 3 elementos:
	Encuentra el mínimo.
	Llévalo arriba con ra o rra.
	Hacemos pb para enviarlo a B.
2. Ordena los 3 que quedan en A con ft_sort_three
3. Vuelve a meter los mínimos de B en A usando pa

Resultado: A queda totalmente ordenado
*/

int ft_get_chunk_size(int total_number_a);
/* 
total_number_a: cantidad total de números en el stack A.
Determinar el tamaño de cada chunk según la cantidad total de elementos en A.

1. total_number_a ≤ 100
	Si hay 100 números o menos, devolvemos 20 (chunk)
	Esto significa:
	Dividiremos los números en chunks de 20 elementos.
	En push_swap suele producir un resultado de 700–900 movimientos, lo cual es muy bueno.
	Por ejemplo:
	Para 80 números → se usarán 4 chunks de 20.
	Para 50 números → se usarán 3 chunks (20 + 20 + 10)

2. total_number_a ≤ 500
	Si hay entre 101 y 500 números, se usa chunk size = 45.
	Razón:
	Con 45 elementos por chunk, el algoritmo se mueve bien para stacks medianos.
	Esta configuración suele producir 5500 movimientos en stacks de 500, que está dentro del rendimiento esperado del proyecto.
	Ejemplos:
	Para 200 números → se crean 4 chunks de 45.
	Para 500 números → se crean 11 chunks de 45.

3. total_number_a > 500
	Si el stack tiene más de 500 elementos, devolvemos chunk size = 100.
	Motivo:
	En stacks muy grandes conviene usar chunks más amplios para que la búsqueda de elementos sea más eficiente.
	Usar chunks demasiado pequeños hace que el algoritmo se vuelva lento en stacks enormes.
*/

int ft_find_max_index(int b[], int len_b);
/*
Sirve para encontrar la posición del valor máximo en el stack B (muy usada en el algoritmo de chunks)
Devuelve:
	El índice donde está el valor máximo del stack.

int max_value = b[0];
	Asignamos como valor máximo inicial el primer elemento del stack.
	Esto sirve como punto de partida para comparar.
	Ejemplo: si B = {12, 50, 3}, el máximo por ahora es 12

int pos_max_index = 0;
	Guardamos que la posición del máximo es inicialmente la posición 0.
	Si encontramos un número mayor, actualizaremos esta variable.

int i = 1;
	Creamos un contador que empieza en 1
	No empezamos en 0 porque ese ya lo usamos como referencia.

Búsqueda del valor máximo
while (i < len_b)
{
Bucle que recorre todos los elementos de B, desde la posición 1 hasta el final.
if (b[i] > max_value)
		{
			max_value = b[i];
			pos_max_index = i;
		}
	Si el valor actual b[i] es mayor que el máximo que teníamos guardado:
	Actualizamos el valor máximo:
	max_value = b[i];
	Guardamos la posición donde apareció:
	pos_max_index = i;
	Ejemplo:
	Si estamos en la posición 3 y b[3] es 98 y antes el máximo era 50,
	el nuevo máximo es 98
	la posición máxima es 3.

return(pos_max_index);
	Cuando el bucle termina, devolvemos la posición del número más grande del stack B.
	Si el máximo está en la posición 4, la función devuelve 4

*/
int ft_find_max_index(int b[], int len_b);
/* 
¿Por qué hay que buscar el máximo en B?

	Cuando usas el algoritmo por chunks, la estrategia es:
	Pasar muchos números desde A → B por rangos (chunks).
	Y luego recuperar B hacia A de forma ordenada.
	Para que A quede ORDENADO, debes sacar de B siempre el número MÁS GRANDE primero.

¿Qué queremos realmente?

	Queremos que los elementos vuelvan a A en orden descendente desde B, así:
	Sacar de B el más grande (90)
	Luego el segundo más grande
	Luego el tercero…
	Así A se reconstruye ordenado

Su propósito:

	1. Localizar dónde está el número más grande en B
	para decidir si conviene hacer rb o rrb
	y moverlo a la cima para hacer pa
	2. Si el máximo está lejos por arriba:
	se usa rb varias veces.
	3. Si está lejos por abajo:
	se usa rrb varias veces.

	Así el máximo llega al índice 0
*/

void ft_push_chunk_to_b(int a[], int *len_a, int b[], int *len_b, int sorted[], int chunk_size, int total);
/*
a[] : stack A
len_a : tamaño de A
b[] : stack B
len_b : tamaño de B
sorted[] : array ordenado con todos los valores originales (base para localizar chunks)
chunk_size : tamaño del chunk
total : cantidad total de números

Objetivo:
	Enviar los elementos de A a B por rangos (chunks), minimizando movimientos.
Variables auxiliares:
	min_chunk → índice inicial del chunk dentro del array sorted
	max_chunk → índice final del chunk
	chunk → número del chunk actual
	i → índice para recorrer A
	moves → rotaciones cuando se usa rra
chunk = 0;
	Comenzamos por el chunk 0 (el primer grupo)
while (chunk * chunk_size < total)
    {
	Mientras existan chunks por procesar.
	chunk * chunk_size es la posición inicial del chunk.
	Si supera total, ya no hay chunks.
1. Calcular límites del chunk actual
        min_chunk = chunk * chunk_size;
        max_chunk = (chunk + 1) * chunk_size - 1;
Calculamos:
índice inicial del chunk
índice final del chunk
	Ejemplo:
	chunk_size = 20
	chunk = 2
	min_chunk = 40
	max_chunk = 59
if (max_chunk >= total)
            max_chunk = total - 1;
Si el chunk final se pasa del total, lo ajustamos al final de la lista.
Para el último chunk, normalmente pasa.
2. Recorrer A buscando elementos que pertenezcan al chunk
        i = 0;
        while (i < *len_a)
        {
Recorremos todos los elementos actuales del stack A.
if (a[i] >= sorted[min_chunk] && a[i] <= sorted[max_chunk])
Si el número actual a[i] está dentro del rango del chunk…
	Ejemplo:
	chunk = valores entre sorted[20] y sorted[39]
	si a[i] pertenece → toca enviarlo a B
3. Traer el valor a la cima mediante rotación mínima
                if (i <= *len_a / 2)
                {
                    while (i-- > 0)
                        ra(a, *len_a);
                }
Si el valor está en la mitad superior del stack A:
Conviene usar ra (rotaciones hacia arriba).
Es más barato porque son menos movimientos.
else
                {
                    moves = *len_a - i;
                    while (moves-- > 0)
                        rra(a, *len_a);
                }
Si está en la mitad inferior, usamos rra (rotación inversa).
Más eficiente que hacer muchas ra.
El objetivo: traer el valor del chunk hasta la posición 0.

4. Mandarlo a B
                pb(a, len_a, b, len_b);
Una vez que el valor está arriba del stack A → lo mandamos a B.

5. Rotación estratégica en B
                if (*len_b > 1 && b[0] < sorted[min_chunk + chunk_size / 2])
                    rb(b, *len_b);
Esta parte es muy inteligente.
	¿Qué hace esto?
		Si B tiene más de 1 elemento
		Y el valor recién colocado (b[0]) es pequeño dentro del chunk
		Lo mandamos hacia abajo con rb.
	¿Por qué?
		Para mantener B más o menos ordenado
		Los valores del chunk que son pequeños quedan abajo
		Los más grandes quedan arriba
		Facilita muchísimo el ft_push_back_to_a después
6. Reiniciar el contador para volver a recorrer A
                i = 0;
Después de hacer un pb, el stack A cambia.
Volvemos al inicio para recalcular correctamente posiciones.
}
            else
                i++;
Si NO pertenece al chunk, simplemente pasamos al siguiente elemento
7. Pasar al siguiente chunk
        c++;
    }
}
Cuando ya no quedan valores del chunk dentro de A, pasamos al siguiente grupo (c++).
Repetimos el proceso hasta vaciar todos los chunks.
*/

void ft_push_chunk_to_b(int a[], int *len_a, int b[], int *len_b, int sorted[], int chunk_size, int total);
/* 
Resumen simple de lo que hace esta función
1. Divide el conjunto en chunks usando chunk_size.
2. Para cada chunk:
	Busca en A los valores del rango del chunk.
	Los trae arriba con rotación mínima.
	Los envía a B con pb.
	Ordena B mínimamente para que los más pequeños queden abajo.
3. Repite hasta procesar todos los chunks.
Resultado final:
	A queda casi vacío
	B queda con los valores repartidos por chunks, medianamente ordenados
	Después se usa ft_push_back_to_a para reconstruir A ordenado.
*/


void ft_push_back_to_a(int a[], int *len_a, int b[], int *len_b);
/*
Esta función sirve para vaciar el stack B devolviendo sus valores a A en orden correcto
Objetivo:
	Sacar todos los elementos del stack B y pasarlos a A ordenadamente.

	max_index: guardará la posición del número más grande en B
	moves: cantidad de rotaciones necesarias cuando se usan rrb

1. Buscar el índice del máximo en B
max_index = ft_find_max_index(b, *len_b);
2. Decidir si rotar hacia arriba o hacia abajo
	if (max_index <= *len_b / 2)
		Si el máximo está en la mitad superior del stack B, conviene hacer rotaciones hacia arriba (rb), porque son menos rotaciones.
	2.1. Rotaciones hacia arriba (rb)
	while (max_index-- > 0)
		rb(b, *len_b);
	Rotamos hacia arriba tantas veces como el índice indica.
	Cada rb mueve el elemento de arriba al final, acercando el máximo hacia la cima (posición 0)
	2.2. Rotaciones hacia abajo (rrb)
	else
	{
		moves = *len_b - max_index;
	Si el máximo está en la mitad inferior del stack, calculamos cuántas rotaciones hacia abajo se necesitan para traerlo arriba.
	2.3. 
	while (moves-- > 0)
			rrb(b, *len_b);
	}
	Ejecutamos las rotaciones inversas (rrb) hasta que el máximo llegue a la cima (posición 0)
3. Cuando el máximo ya está arriba → pasarlo a A
pa(a, len_a, b, len_b);
	Una vez que el máximo está arriba del stack B, se hace un pa:
	El elemento pasa de B → A
	len_a aumenta
	len_b disminuye
	Esto coloca el mayor valor disponible en el final correcto del stack A.
*/


void ft_sort_big_number(int *a, int *len_a, int *b, int *len_b, int total);
/* 
Variables locales:
	sorted: array dinámico que contendrá todos los valores de A ordenados
	i: índice para bucles
	swapped y tmp: auxiliares para bubble sort
	chunk_size: tamaño de cada chunk
1. Reservar memory para sorted
2. 
i = 0;
    while (i < total)
    {
        sorted[i] = a[i];
        i++;
    }
Copiamos todos los valores de A a sorted.
Esto es necesario porque no queremos modificar A mientras calculamos los chunks.

3. Ordenar la copia (bubble sort)
swapped = 1;
    while (swapped)
	{
		...
	}
Explicación:
	swapped = bandera para controlar si hubo cambios en la pasada.
	Bubble sort: comparamos pares consecutivos y los intercambiamos si están desordenados.
	Repetimos hasta que no se hagan swaps → array ordenado.
	Resultado: sorted[] tiene todos los números de A en orden ascendente.

4. Determinar tamaño de cada chunk
    chunk_size = ft_get_chunk_size(total);
Llamamos a la función que decide cuántos elementos va a tener cada chunk dependiendo del total:
	<100 → 20
	<500 → 45
	500 → 100
Esto optimiza el número de movimientos de push_swap.

5. Pasar elementos a B por chunks
    ft_push_chunk_to_b(a, len_a, b, len_b, sorted, chunk_size, total);
Llamamos a la función que:
Recorre A
Selecciona los elementos del chunk actual
Los manda a B de manera estratégica
Objetivo: llenar B parcialmente ordenado, listo para reconstruir A.

6. Recuperar todos los elementos a A
    ft_push_back_to_a(a, len_a, b, len_b);
Llamamos a la función que vacía B hacia A, sacando siempre el máximo primero.
Resultado: A queda completamente ordenado
*/

void ft_sort_big_number(int *a, int *len_a, int *b, int *len_b, int total);
/* 
Resumen de toda la función
	1. Crear copia de A (sorted)
	2. Ordenar sorted (para poder definir los chunks)
	3. Calcular tamaño de chunk (chunk_size)
	4. Pasar elementos de A → B por chunks (ft_push_chunk_to_b)
	5. Vaciar B → A en orden (ft_push_back_to_a)
	6. Liberar memoria
*/