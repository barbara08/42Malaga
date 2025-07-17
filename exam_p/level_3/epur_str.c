#include "libft3.h"
/*
Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.
A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.
If the number of arguments is not 1, or if there are no words to display, the
program displays \n.
Example:
$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>
*/

//Verifica si un carácter es espacio o tabulación
//Return 1 => si es alguno de los dos 
//Return 0 => si no lo es
int is_space(char c)
{
    return(c == ' ' || c == '\t');
}

int main(int argc, char **argv)
{
    int i = 0;
    int space = 0;
    
    if (argc == 2)
    {
        // Saltar espacios/tabs iniciales
        while(argv[1][i] && is_space(argv[1][i]))
            i++;
        while (argv[1][i])
        {
            // Si encontramos una palabra
            if (!is_space(argv[1][i]))
            {
                if (space)
                    write(1, " ", 1); // Escribimos espacio entre palabras
                // Escribir la palabra
                while (argv[1][i] && !is_space(argv[1][i]))
                {
                    write(1, &argv[1][i], 1);
                    i++;
                }
                space = 1; // Se necesita espacio antes de la próxima palabra
            }
            else
            {
                // Saltar espacios entre palabras
                while (argv[1][i] && is_space(argv[1][i]))
                    i++;
            }
        }
    }
    write(1, "\n", 1);
    return(0);
}