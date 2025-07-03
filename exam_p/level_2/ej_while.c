
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


char *ft_strrev(char *str)
{
    int i;
    int j;
    char tmp;

    // Calculamos la longitud de la cadena
    i = 0;
    while (str[i])
        i++;

    // i ahora es la longitud, j es el índice del último carácter
    j = i - 1;  //j apunta al último carácter real 
    i = 0;

    // Intercambiamos caracteres desde ambos extremos hacia el centro
		//usamos dos índices: 
		//i (inicio) y j (final), 
		//y mientras i < j, intercambiamos los caracteres en esas posiciones
    while (i < j)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }

    return str;
}