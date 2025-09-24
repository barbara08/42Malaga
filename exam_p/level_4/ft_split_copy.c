#include "libft4.h"
/*
Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.
A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.
Your function must be declared as follows:
char    **ft_split(char *str);
*/


int search_space(char *str, int i)
{
    while (str[i] && (str[i] != '\n' && str[i] != '\t' && str[i] != 32))
        i++;
    return(i);
}  

int count_word(char *str)
{
    int num_words = 0;
    int i = 0;
    int start = -1;
    //int end = -1;
    while(str[i]){
        if (str[i] == '\n' || str[i] == '\t' || str[i] == 32){

            if (start >=0){
                num_words++;
                start = -1;
            }
        }else{
            if (start < 0){
                start = i;
            }
        }
        i++;
    }
    if (start >= 0){
        num_words++;
    }

    return num_words;
}


char    **ft_split(char *str)
{
    int i;
    char *word;
    int size_word;
    int pos_word;
    char **array_str=NULL;
    int pos_array_str=0;
    printf("====%lu=====", strlen(str));
    printf("num word %d>>>", count_word(str));
    

    array_str = malloc(sizeof(char *) * (count_word(str) + 1));
    if (!array_str)
        return(NULL);

    i = 0;
    /*
    while (str[i] && ((str[i]) == '\n' || str[i] == '\t' || str[i] == 32))
        i++;
        //printf("-i %d---", i);
      */  
    while(str[i])
    {
        while (str[i] && ((str[i]) == '\n' || str[i] == '\t' || str[i] == 32))
            i++;
        if (!str[i]){
            break;
        }
        size_word = search_space(str, i) - i;
        printf("size_word %d --- ", size_word);

        word = malloc(sizeof(char *) * (size_word + 1));
        if(!word)
            return(NULL);
        pos_word = 0;
        while(pos_word < size_word)
        {
            word[pos_word] = str[i];
            pos_word++;
            i++;
        }
        
        array_str[pos_array_str] = word;
        printf("- %d---%d -ª %s ###\n",i, pos_array_str, word);
        pos_array_str++;
        if (str[i])
            i++;
        
    }
    printf(" pos final %d ---- \n", pos_array_str);
    return(array_str);

}

int main(void)
{
    char **word = ft_split("Una\tfrase para\n probar como funciona");
    
    int i = 0;
    while (word[i])
    {
        printf("Word %d: %s\n", i, word[i]);
        free(word[i]);
        i++;
    }
    free(word);
    
 
    return (0);
}