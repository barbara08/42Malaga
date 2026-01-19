#include "libft4.h"
/*
Write a program that takes a string and displays this string after rotating it
one word to the left.
Thus, the first word becomes the last, and others stay in the same order.
A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.
Words will be separated by only one space in the output.
If there's less than one argument, the program displays \n.
Example:
$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

int	main(int argc, char **argv)
{
	int	i = 0;
	int	start = 0;
	int	first_word_end = 0;
	int	printed = 0; // Para saber si ya imprimimos una palabra

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	//1. Skip leading spaces/tabs
	while (argv[1][i] == ' ' || argv[1][i] == '\t')
		i++;

	//2. Save start position of the first word
	start = i;

	//3. Mark the end of the first word
	while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
		i++;
	first_word_end = i;

	//4. Skip spaces/tabs after first word
	while (argv[1][i] == ' ' || argv[1][i] == '\t')
		i++;

	//5. Print the rest of the string
	while (argv[1][i])
	{
		//5.A Skip extra spaces
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;

		//5.B Print the word
		if (argv[1][i])
		{
			// Add a space if we already printed a word before
			if (printed)
				write(1, " ", 1);
            // while there are no spaces, print the character (word)
			while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
			{
				write(1, &argv[1][i], 1);
				i++;
			}
			printed = 1;
		}
	}

	//6. If there was at least one word after the first, add a space before the first word
	//Si hubo al menos una palabra después de la primera, 
	//agregue un espacio antes de la primera palabra.
	if (printed)
		write(1, " ", 1);

	//7. Write the first word
	i = start;
	while (i < first_word_end)
	{
		write(1, &argv[1][i], 1);
		i++;
	}

	//8 y 9
	write(1, "\n", 1);
	return (0);
}


