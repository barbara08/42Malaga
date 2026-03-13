#include "push_swap.h"

void ft_sort_three(int *stack_a, int size_a)
{
	if (size_a != 3)
		return;
	if (ft_is_sorted(stack_a, size_a))
		return;

	int a = stack_a[0];
	int b = stack_a[1];
	int c = stack_a[2];

	if (a > b && b < c && a < c)
		sa_swap(stack_a, size_a);
	else if (a > b && b > c)
	{
		sa_swap(stack_a, size_a);
		rra_reverse_rotate(stack_a, size_a);
	}
	else if (a > b && b < c && a > c)
		ra_rotate(stack_a, size_a);
	else if (a < b && b > c && a < c)
	{
		sa_swap(stack_a, size_a);
		ra_rotate(stack_a, size_a);
	}
	else if (a < b && b > c && a > c)
		rra_reverse_rotate(stack_a, size_a);
}

void ft_sort_five_v0(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
	while (*size_a > 3)
		pb_push(stack_a, size_a, stack_b, size_b);
	ft_sort_three(stack_a, *size_a);

	while (*size_b > 0)
		pa_push(stack_a, size_a, stack_b, size_b);
}
void sort_five(int *a, int size_a)//, int *stack_b, int *size_b)
{
    int i, j, temp;

	i = 0;
	while(i<size_a)
    {
		j = 0;
		while (j< 5 - i - 1)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
			j++;
        }
		i++;
    }
}
void ft_sort_five(int *a, int *size_a, int *b, int *size_b)
{
    int min, i, min_index, j;
    while (*size_a > 3)
    {
        min = a[0];
        min_index = 0;
        for (i = 1; i < *size_a; i++)
        {
            if (a[i] < min)
            {
                min = a[i];
                min_index = i;
            }
        }
        if (min_index <= *size_a / 2)
        {
            for (j = 0; j < min_index; j++)
                ra_rotate(a, *size_a);
        }
        else
        {
            for (j = min_index; j < *size_a; j++)
                rra_reverse_rotate(a, *size_a);
        }
        pb_push(a, size_a, b, size_b);
    }
    ft_sort_three(a, *size_a);
    while (*size_b > 0)
        pa_push(a, size_a, b, size_b);

}

//Función auxiliar para indexar los elementos, para poder implemarlo en la funcion radix_sort
//Radix solo funciona correctamente cuando los valores van de 0 a N-1 sin repetidos, por eso se indexa
void ft_index_stack(int *stack, int size)
{
	int n_sorted=0;
	int i;
	int j;
	int *sorted = malloc(size * sizeof(int)); //array nuevo que usaremos para tener una copia ordenada del stack original

	//1. Copiar elementos
		//Copia el contenido de stack en sorted para no modificar el original mientras ordenamos
	i = 0;
	while (i < size)
	{
		sorted[i] = stack[i];
		i++;
	}
	//2. Ordenar (bubble sort)
		//Ordena el array sorted de menor a mayor usando Bubble Sort (ineficiente, pero fácil)
		//Después de esto, sorted contiene los mismos números pero ordenados
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (sorted[j] > sorted[j + 1])
			{
				int tmp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = tmp;
				n_sorted++;
			}
			j++;
		}
		i++;
	}
	printf("n_sorted: %d\n---------\n", n_sorted);
	i = 0;
	while (i<size){
		printf("%d\n", sorted[i]);
		i++;
	}
	//3. Asignar índices
		//Aquí ocurre la indexación real:
		//Para cada número original en stack[i], buscamos su posición (j) en el array ordenado sorted.
		//Reemplazamos stack[i] con j, que es su índice ordenado
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (stack[i] == sorted[j])
			{
				stack[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
	free(sorted);
}

void ffft_sort_big(int *a, int *len_a, int *b, int *len_b)
{
	int max_bits = 0;
	int max_num = *len_a - 1;
	int i = 0;

	while ((max_num >> max_bits) != 0)
		max_bits++;

	while (i < max_bits)
	{
		int j = 0;
		int size = *len_a;

		while (j < size)
		{
			// Bit actual
			int bit = (a[0] >> i) & 1;

			if (bit == 0)
				pb_push(a, len_a, b, len_b);
			else
			{
				// Revisa si también se puede rotar b
				int rotate_b = 0;
				if (*len_b > 0 && ((b[0] >> i) & 1) == 1)
					rotate_b = 1;

				if (rotate_b)
					rr_rotate(a, *len_a, b, *len_b); // ra + rb
				else
					ra_rotate(a, *len_a);
			}
			j++;
		}

		// Devuelve todos los elementos de b a a
		while (*len_b > 0)
			pa_push(a, len_a, b, len_b);

		i++;
	}
}

void ft_sort_big(int *a, int *len_a, int *b, int *len_b)
{
	int max_bits = 0; //Para calcular cuántos bits necesitamos para representar el número más grande
	int max_num = *len_a - 1; //Como los valores ya están indexados de 0 a n-1, el valor más alto es =>  len_a - 1
	int i = 0; //Contador para recorrer los bits desde el menos significativo hasta el más significativo

	//1. Calcular el número de bits necesarios
	while ((max_num >> max_bits) != 0)
		max_bits++;

	//2. Recorrer los bits desde el menos significativo (LSB) hasta el más significativo (MSB)
	while (i < max_bits)
	{
			//Contador para recorrer todos los elementos de a en esta pasada de bits
		int j = 0; 
			//Guarda el tamaño actual de a, ya que este puede cambiar durante el bucle (cuando se hace pb, el tamaño de a baja), 
			//Guardamos el valor original para recorrerlo completamente sin error
		int size = *len_a; 
		//3. Recorre todos los elementos de A, en la pasada actual de bits
		while (j < size)
		{
				//Explciado abajo
			//3.A
			if (((a[0] >> i) & 1) == 0)
				pb_push(a, len_a, b, len_b);
			//3.B
			else
				ra_rotate(a, *len_a);
			j++;
		}
		//4. Simplemente lo vaciamos con pa (explciado abajo)
		while (*len_b > 0)
			pa_push(a, len_a, b, len_b);
		i++;
	}
}



void print_stack(char *name, int stack[], int len)
{
	int i = 0;
	printf("%s: ", name);
	while (i < len) {
		printf("%d ", stack[i]);
		i++;
	}
	printf("\n");
}

void ft_sort_big_num_v1(int *a, int len_a, int *b, int len_b)
{
	int i =0;
	int j =1;

	print_stack("stack_a original: ", a, len_a);
	print_stack("stack_b original: ", b, len_b);


	while (j<len_a)
	{
		if (a[i] > a[j]){
			if (i==0){
				while (j<len_a){
					if (a[i]<a[j]){
						break;
					}
					j++;
				}
				if (j==len_a){
					ra_rotate(a, len_a);
				}else{
					sa_swap(a, len_a);
					if (b && a[i] < b[i]){
						pa_push(a, &len_a, b, &len_b);
					}
				}
				print_stack("stack_a medio: ", a, len_a);
				print_stack("stack_b medio: ", b, len_b);



			}else{
				int z=0;
				while(z<i){
					pb_push(a, &len_a, b, &len_b);
					z++;
				}
				//printf("2. stack_a: %d\n", *a);
				i=0;
				j=1;
			}
		}else{
			i++;
			j++;
		}
	}
	print_stack("stack_a final: ", a, len_a);
	print_stack("stack_b final: ", b, len_b);

	/* 
	if (b){
		while(b){
			pa_push(a, &len_a, b, &len_b);
		}
	}*/
}

//funcion que devuelve la posicion del entero mas pequeño
int get_less_position_number(int *stack, int len_stack)
{
	int position = 0;
	int number = stack[0];
	int i = 1;
	//printf("****\n");
	while(i<len_stack){
		if (stack[i] < number){
			//printf("--stack %d %d %d\n", i, number, stack[i]);
			position = i;
			number = stack[i];
		}
		i++;
	}
	//printf("****\n");
	return position;
}

void ft_sort_big_num_v2(int *a, int len_a, int *b, int len_b)
{
	int position;
	int diff_with_end;
	int i = 0;
	while (len_a >2){
		//printf("------\n");
		//print_stack("A", a, len_a);
		//print_stack("B", b, len_b);
		position = get_less_position_number(a, len_a);
		//printf("-pos %d\n", position);
		diff_with_end = len_a - position;
		//printf("-diff %d\n", diff_with_end);
		//printf("-len_a %d\n", len_a);
		//printf("-len_a %d %d\n", position, (int)len_a/2);
		if (position >= (int)(len_a/2)){//} && diff_with_end >0){
			//printf("hola %d --\n", (len_a/2));
			i=0;
			//while (i<diff_with_end)
			while (i<diff_with_end)
			{
			//printf ("%d < %d - %d\n", i,len_a,diff_with_end);
				rra_reverse_rotate(a, len_a);
				//	ra_rotate(a, len_a);
				i++;
			}
			pb_push(a, &len_a, b, &len_b);
			//len_a--;
		}else{
			//printf("estoy en el else pos %d ...", position);
			if (position==1){
				sa_swap(a, len_a);
			}else{
			//	printf("AAAAQUI");
				i=position;
				while (i>0){
				//rra_reverse_rotate(a, len_a);
					ra_rotate(a, len_a);
					i--;
				}
				pb_push(a, &len_a, b, &len_b);
				//len_a--;
			}
		}
	}
	if (a[0] > a[1]){
		sa_swap(a, len_a);
	}
	i=0;
	while (i<len_b){
		pa_push(a, &len_a, b, &len_b);
	}
}

int number_more_little(int *a, int len_a, int number){
	int i = 1;
	int r = 1;
	while (i<=len_a){
		if (number>a[i]){
			r=0;
			break;
		}
		i++;
	}
	return r;
}

void ft_sort_big_num_v3(int *a, int len_a, int *b, int len_b)
{
	pb_push(a, &len_a, b, &len_b);
	while (len_a>1){
		//printf ("->***************<-\n");
		//printf("------\n");
		//print_stack("A", a, len_a);
		//print_stack("B", b, len_b);
		//printf ("->%d - %d --- %d\n", a[0], b[0],a[0] < b[0]);
		
		if (a[0] < b[0]){
			int is_more_litte = number_more_little(a, len_a, a[0]);
			if (is_more_litte){
				ra_rotate(a, len_a);
			}else{
				if (len_b==1){
					pb_push(a, &len_a, b, &len_b);
					sb_swap(b, len_b);
				}else{
					int c = 0;
					is_more_litte = number_more_little(b, len_b, a[0]);
					if (is_more_litte == 0){
						while (a[0] < b[0]){				
							//printf ("%d - %d__%d\n", a[0], b[0], is_more_litte);
							if (a[1]== b[0])
							{
								rr_rotate(a, len_a, b, len_b);
							}else{
								rb_rotate(b, len_b);
							}
							c++;
							if (c==len_b){
								break;
							}
						}
					}
					pb_push(a, &len_a, b, &len_b);
					if (is_more_litte){
						rb_rotate(b, len_b);
					}else{
						while (c>0){
							rrb_reverse_rotate(b, len_b);
							c--;
						}
					}
				}
			}
		}else{
			pb_push(a, &len_a, b, &len_b);
		}
	}
	
	//printf("FIN!!");
	while (len_b>0){
		pa_push(a, &len_a, b, &len_b);
	}
	rra_reverse_rotate(a, len_a);
}


void ft_sort_big_num(int *a, int len_a, int *b, int len_b)
{
	int i = 0;
	int len=5;
	while(i < (len_a - len))
	{
		//sort_five(a, len);
		ft_sort_five(a, &len_a, b, &len_b);
		/*
printf("*********************\n");
	print_stack("A", a, len_a);
	print_stack("B", b, len_b);
printf("*********************\n");
*/
		ra_rotate(a, len_a);
		i++;
	}
	// printf("@@@@@@@@@@@@@@@@@@@@@\n");
	if (i<=5){
		i--;
		while (i>0){
			rra_reverse_rotate(a, len_a);
			// printf("%d -- %d ||", a[0], a[1]);
			if (a[0] > a[1]){
				sa_swap(a, len_a);
			}
			i--;
		}
	}else{
		i = 0;
		while(i<5){
			ra_rotate(a, len_a);
			i++;
		}
	}
}






/* ft_sort_three
Sirve para ordenar una pila (stack) de exactamente 3 elementos con el menor número de movimientos.
Ordenar 3 números es un caso pequeño y muy común en push_swap, y se puede hacer con pocas instrucciones.
Esta función contiene la lógica para mover los elementos de forma óptima: usando solo sa, ra, rra.
Así evitas hacer algoritmos generales complejos para solo 3 números.
Se llama cuando la pila tiene 3 o menos elementos para ordenar rápido.
*/
/* ft_sort_five
Sirve para ordenar pilas de hasta 5 elementos (caso pequeño).
La estrategia típica es:
Pasar 2 números de stack_a a stack_b con la instrucción pb (push b), para reducir el problema a ordenar 3 elementos en stack_a.
Llamar a ft_sort_three para ordenar esos 3 elementos en stack_a.
Luego insertar los elementos de stack_b de vuelta a stack_a con pa, ya ordenados.
Esta es una solución común y eficiente para pilas pequeñas, y se aprovecha que ordenar 3 es sencillo.
*/
/* Resumen:
ft_sort_three: ordena rápido 3 elementos.
ft_sort_five: ordena hasta 5 elementos usando sort_three y moviendo elementos entre pilas.
Se usan para casos pequeños donde un algoritmo simple es mejor que uno complejo.
*/
/* ft_index_stack
Porque hay que indexar
Radix Sort funciona con números binarios en rangos pequeños, y no con valores reales grandes o desordenados
El stack puede tener valores muy grandes o desordenados, por ejemplo:
stack_a = [98, 3, -42, 999, 17]

Estos números:
No están en orden ni tienen una relación directa entre sí.
Sus valores pueden ser muy altos o negativos, lo que complica compararlos bit a bit
Solución: Indexar
Convertimos los valores reales a índices ordenados, es decir:
Original:  [98, 3, -42, 999, 17]
Ordenado:  [-42, 3, 17, 98, 999]
Índices:   [  3, 1,  0,  4,   2]
sto hace que:
Los números estén todos en el rango 0 a n-1 (donde n es la cantidad de elementos).
Puedas trabajar con valores compactos y positivos.
Puedas usar Radix Sort directamente, porque funciona con bits binarios.

Ejemplo:
stack_a = [98, 3, 999, 17]

Si no indexas, tendrías que trabajar con los bits de 98, 3, 999, 17:
98   = 01100010
3    = 00000011
999  = 001111100111
17   = 00010001

Pero si indexas:
stack_a = 			[98, 3, 999, 17]
Los valores serán 	[2, 0, 3, 1] 	y solo necesitas trabajar con:
2 = 10
0 = 00
3 = 11
1 = 01
Número original		Índice en ordenado		Explicación
98					2						98 	es el tercer número ordenado
3					0						3 	es el primero en orden
999					3						999 es el cuarto (último)
17					1						17 	es el segundo en orden

Ahora sí, puedes aplicar Radix Sort por bits de forma clara, rápida y predecible.
*/

/* ft_sort_big (radix_sort)
1. 
while ((max_num >> max_bits) != 0) max_bits++;
	Calcula cuántos bits se necesitan para representar max_num.
	Ejemplo:
	Si max_num = 7 → binario: 111 → 3 bits
	Se hace shift a la derecha (>>) hasta que se hace cero → cuenta los bits necesarios.

3.
if (((a[0] >> i) & 1) == 0)
	Aquí ocurre la parte clave del radix sort:
	a[0] >> i → toma el bit i del primer número de A
	& 1 → extrae solo ese bit
	Si ese bit es 0, se hace pb (mandar a B)
	Si es 1, se hace ra (rotar A para mantenerlo en A)
3.A
pb_push(a, len_a, b, len_b);
	Mueve el primer elemento de A a B.
	(Presumiblemente implementado como pb en push_swap).
3.B
ra_rotate(a, *len_a);
	Rota A hacia arriba: mueve el primer número al final.
	Se usa para que los valores cuyo bit actual es 1 queden atrás en el stack pero no se pierdan.
4.
pa_push(a, len_a, b, len_b);
	Una vez que pasamos todos los valores de A por el filtro del bit actual, 
	todo lo que fue a B (bit 0) debe volver a A, así que simplemente lo vaciamos con pa	

RESUMEN:
Esta es una implementación funcional de Radix Sort, adaptada al proyecto push_swap, usando solo:
pb para mover valores con bit 0 a B
ra para rotar valores con bit 1
pa para devolver todo de B a A
Se repite por cada bit
Y es muy eficiente, con una complejidad de:
O(n * log n) movimientos en el peor caso
Ideal para valores de 100 o 500 elementos

*/