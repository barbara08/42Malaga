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
int calculate_size(char *str)
{
    int size = 0;
    int pos = 0;
    int is_init = 0;
    int last_char_is_space = 0;
    while(str[pos]){
        if (str[pos] == 32 && is_init == 1 && last_char_is_space == 0)
        {
            printf("%c|", str[pos]);
            last_char_is_space = 1;
            size++;
        }
        else if (str[pos] != ' ')
        {
            printf("%c|", str[pos]);
            last_char_is_space= 0;
            size++;
            is_init = 1;
        }
        pos++;
    }
    if (last_char_is_space)
        size--;

    return size;
}

void find_first_word(char *str, int *start, int *end, int *init_next_word)
{
    int i = 0;
    (*start) = 0;
    while (str[i] && str[i] == 32)
        i++;
    (*start) = i;
    while (str[i] && str[i] != 32)
        i++;
    (*end) = i -1;
    while (str[i] && str[i] == 32)
        i++;
    (*init_next_word) = i;
    printf("[  s: %d, e: %d, p: %d.    ]", (*start), *end, *init_next_word);
}
int main(int argc, char **argv)
{
    if(argc == 2)
    {
        /*
        int i = 0;
        char *new_str;
        while(argv[1][i] && argv[1][i] == ' ')
            i++;

        */
       int size = 0;
       size = calculate_size(argv[1]);
       printf("%d---", size);
       int start=1000, end=1000, pos=1000;
       find_first_word(argv[1], &start, &end, &pos);
       printf("  s: %d, e: %d, p: %d", start, end, pos);
       char *new_str;
       new_str = malloc(sizeof(char) * (size + 1));

       char *str = argv[1];
       int i = 0;
       while (str[pos]){
        // hay que controlar que no se metan más de 1 espacio consecutivo
            new_str[i] = str[pos];
            i++;
            pos++;
       }

       // hay que comprobar si tengo que añadir un espacio entre la ulitma letra y la primera

       // aqui escribo la primera palabra al final
       while (start <= end){
        new_str[i] = str[start];
        start++;
        i++;
       }
            
        /* 
        while(argv[1] && argv[1][i] != ' ')
        {
            new_str = argv[1][i];
            i++;
        }*/
/*
        printf("%d", i);
        printf("%c", argv[1][i]);
*/
    }
}