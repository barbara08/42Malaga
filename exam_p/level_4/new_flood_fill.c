#include "libft4.h"
#include "flood_fill.h"

char *make_area(char zone, t_point size)
{
    char **area = malloc(sizeof(char *) * (size.y + 1));
    if(!area)
        return (NULL);
    int r = 0;
    while (r < size.y)
    {
        area[r] = malloc(sizeof(char) * (size.x + 1));
        int c = 0;
        //while(c < )


        
    }
    
}
