
#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char        *line_read;
    static char *line;

    if (BUFFER_SIZE <= 0 || fd < 0)
    {
        free(line);
        line_read = NULL;
        return (NULL);
    }
    line = ft_read_file(fd, line);
    if (!line)
        return (NULL);
    line_read = ft_extract_line(line);
    line = ft_exclude_line(line);
    return (line_read);
}