#include "libft.h"

//appends string src to the end of dst.  It will append at most
//dstsize - strlen(dst) - 1 characters. 
//It will then NUL-terminate, unless
//dstsize is 0 or the original dst string was longer than dstsize

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t dst_len = ft_strlen(dst);
    size_t src_len = ft_strlen(src);
    size_t i = 0;

    if(size <= dst_len)
        return (src_len + size);
    while(src[i] != '\0' && (dst_len + i) < size - 1)
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';
    return(dst_len + src_len);
}

int main()
{
    char dst[15] = "hola ";
    char src[] = "que tal";
    //Para que se cumpla el if
    size_t ftstrlcat1 = ft_strlcat(dst, src, 5);
    printf("ftstrlcat1: %zu\n", ftstrlcat1);
    printf("dst1: %s\n", dst);
    printf("src1: %s\n", src);
    //Para que se cumpla el while
    size_t ftstrlcat2 = ft_strlcat(dst, src, 16);
    printf("ftstrlcat2: %zu\n", ftstrlcat2);
    printf("dst2: %s\n", dst);
    printf("src2: %s", src);
    return(0);
}