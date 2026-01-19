#include "../level.h"

/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.
A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.
If the number of parameters is different from 1, the program will display
'\n'.
In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).
Examples:
$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/


int main(int argc, char **argv)
{
	int i;
	int c;
	int start;
	int end;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
			i++;
		i--;

		while (i >= 0)
		{
			// Saltar espacios
			while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
				i--;
			if (i < 0)
				break;
			end = i;

			// Encontrar inicio de palabra
			while (i >= 0 && (argv[1][i] != ' ' && argv[1][i] != '\t'))
				i--;
			start = i + 1;

			// Imprimir palabra
			c = start;
			while (c <= end)
			{
				write(1, &argv[1][c], 1);
				c++;
			}

			// Solo imprime un espacio si hay más palabras antes
			while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
				i--;
			if (i >= 0)
				write(1, " ", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}




/* 
int main(int argc, char **argv)
{
	char *str;
	int i;
	int c;
	int start;
	int end;

	if (argc == 2)
	{
		str = argv[1];
		i = 0;
		while (str[i])
			i++;
		i--;

		while (i >= 0)
		{
			// Saltar espacios
			while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
				i--;
			if (i < 0)
				break;
			end = i;

			// Encontrar inicio de palabra
			while (i >= 0 && (str[i] != ' ' && str[i] != '\t'))
				i--;
			start = i + 1;

			// Imprimir palabra
			c = start;
			while (c <= end)
			{
				write(1, &str[c], 1);
				c++;
			}

			// Solo imprime un espacio si hay más palabras antes
			while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
				i--;
			if (i >= 0)
				write(1, " ", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}*/
