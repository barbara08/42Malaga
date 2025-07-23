
//DOS FORMAS DE HACER WHILE (no se si ok)
/* 
	while(s[i++])
	{
		if()
		{
			//code
		}
	}
 -------------------------
	while (s[i])
	{
		if()
		{
			//code
		}
		i++;
	}
*/

//DOS FORMAS DE VERIFICAR (no se si ok)
/*
	copy = (char *)malloc(ft_strlen(src) + 1 * sizeof(char *));

	if (copy == NULL)
		return(NULL);

	if (!copy)
		return(NULL);
*/

//BITS

/*


11000011 >> 4 | 11000011 << 4

		00001100 | 00110000 = 00111100

OR: 0 | 0 = 0, 0 | 1 = 1
*/

/*
int lookup[256] = {};

* int: Se declara un arreglo de tipo int. Esto indica que cada elemento del arreglo será de tipo entero.
* lookup[256]: Define un arreglo llamado lookup con 256 elementos. 
	Es un arreglo estático de tamaño 256, 
	lo que significa que puede almacenar hasta 256 valores enteros. 
	Los índices de este arreglo van del 0 al 255
* = {}: La inicialización vacía ({})
	significa que se está inicializando el arreglo con todos sus valores a cero de manera implícita.
En C, si un arreglo global o estático se inicializa de esta manera,
cada uno de sus elementos se establece a 0 de forma predeterminada.
En el caso de un arreglo local, los elementos se llenan con valores indeterminados si no se especifican.


Si se quisiera inicializar el arreglo con valores específicos, se podría hacer de la siguiente manera:
// ejemplo de inicialización con valores específicos
int lookup[256] = {1, 2, 3, ..., 256}; 
*/