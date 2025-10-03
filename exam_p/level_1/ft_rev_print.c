#include <unistd.h>
#include <stdio.h>

/* 
write a function that takes a string, and displays the string in reverse
followed by a newline.

Examples:
$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
*/


char	*ft_strrev(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	write(1, "\n", 1);
	return(str);
}
int main()
{
	char str[] = "dub0 a POIL";
	ft_strrev(str);
	return(0);
}