#include "libft4.h"
#include "flood_fill.h"

/*
Expected files   : *.c, *.h
Allowed functions: -

Write a function that takes a char ** as a 2-dimensional array of char, a 
t_point as the dimensions of this array and a t_point as the starting point.
Starting from the given 'begin' t_point, this function fills an entire zone 
by replacing characters inside with the character 'F'. A zone is an group of 
the same character delimitated horizontally and vertically by other characters
or the array boundry. (boundry => límite)
The flood_fill function won't fill diagonally.
The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin);
The t_point structure is prototyped like this:
  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;
Example:
$> cat test_main.c
#include "test_functions.h"
#include "flood_fill.h"
int main(void)
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
	}
	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	putc('\n');
	print_tab(area);
	return (0);
}
$> gcc flood_fill.c test_main.c test_functions.c -o flood_fill; ./flood_fill
1 1 1 1 1 1 1 1
1 0 0 0 1 0 0 1
1 0 0 1 0 0 0 1
1 0 1 0 0 0 0 1
1 1 0 0 0 0 0 0

1 1 1 1 1 1 1 1
1 F F F 1 0 0 1
1 F F 1 0 0 0 1
1 F 1 0 0 0 0 1
1 1 0 0 0 0 0 0
$> 
*/
//r => row es y
//c => column es x
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