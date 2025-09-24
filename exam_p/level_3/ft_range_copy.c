#include "libft3.h"
/*
Write the following function:
int *ft_range(int start, int end);
It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.
Examples
- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.

//También funciona para rangos inversos
//como ft_range(10, 5) → imprime: 10 9 8 7 6 5
*/

int *ft_range(int start, int end)
{
    int *array;
    int size;
    int i;
    size = end - start;
    if(size < 0)
        //size = size * (-1);
        size = -size;
    size++;
    array = malloc(sizeof(int) * (size + 1));
    i = 0;
    if(start < end)
    {
        while(start <= end)
        {
            printf("-start-(%d)-", start);
            array[i] = start;
            start++;
            i++;
        }
    }
    else
    {
        while(start >= end)
        {
            array[i] = start;
            start--;
            i++;
        }
    }
    return(array);
}

int main(){
    //int test1[];
    //test1 = ft_range(1,3);
    
    int test9[] = {-1,0,1,2,3,4};
    int i =0;
    int size = 0;

    size = sizeof(test9) / sizeof((int)test9[0]);
    printf("\ntest1: %d \n", size);
    while(i<size){
        printf("%d ",test9[i]);
        i++;
    }


}
 //int x(){
    /*
    int test2[] = ft_range(-1,2);
    int test3[] = ft_range(0,0);
    int test4[] = ft_range(0,-3);
    int i =0;
    int size = 0;

    size = sizeof(test1) / sizeof((int)test1[0]);
    printf("\ntest1: %d \n", size);
    while(i<size){
        printf("%d ",test1[i]);
        i++;
    }
    printf("\ntest2: \n");
    size = sizeof(*test2) / sizeof(test2[0]);
    while(i<size){
        printf("%d ",test2[i]);
        i++;
    }
    printf("\ntest3: \n");
    size = sizeof(*test3) / sizeof(test3[0]);
    while(i<size){
        printf("%d ",test3[i]);
        i++;
    }
    printf("\ntest4: \n");
    i =0;
    size = sizeof(*test4) / sizeof(test4[0]);
    while(i<size){
        printf("%d ",test4[i]);
        i++;
    }
*/
//}  