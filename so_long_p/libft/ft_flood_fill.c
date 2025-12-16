#include "libft.h"

typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

char **make_area(char *zone[], t_point size)
{
    char **area = malloc(sizeof(char *) * (size.y + 1));
    if(!area)
        return (NULL);
    int r = 0;
    while (r < size.y)
    {
        area[r] = malloc(sizeof(char) * (size.x + 1));
        int c = 0;
        while (c < size.x)
        {
            area[r][c]= zone[r][c];
            c++; 
        }
        r++;
    }
    return(area);
}
void print_tab(char **area)
{
    int row = 0;
    int col;
    while (area[row])
    {
        col = 0;
        while (area[row][col])
        {
            printf ("%c ", area[row][col]);
            col++;
        }
        row++;
        printf("\n");
    }
}
void change_char(char **tab, char character, int x, int y, t_point size)
{
    printf("[%d][%d]", x,y);
    if (x>=0 && x<size.x && y >=0 && y < size.y && tab[y][x] == character){
        printf(" * ");
        tab[y][x] = 'F';
        change_char(tab, character, x+1, y, size);
        change_char(tab, character, x-1, y, size);
        change_char(tab, character, x, y+1, size);
        change_char(tab, character, x, y-1, size);
        
    }
    printf("\n");
}
void  flood_fill(char **tab, t_point size, t_point begin)
{
    char character = tab[begin.y][begin.x]; // El 0 o el 1
    int x = begin.x;
    int y = begin.y;
    change_char(tab, character, x, y, size);
}

int main()
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};
	area = make_area(zone, size);
	print_tab(area);
	flood_fill(area, size, begin);
    write(1, "\n", 1);
	print_tab(area);
    
    int y = 0;
    while (y < size.y){
        free(area[y]); 
        y++;
    }
    free(area);
}