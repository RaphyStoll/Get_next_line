#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
    int		*fd;
    char	**lines;
    int		i;
    int		active_fds;

    if (argc < 2)
    {
        printf("Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return (1);
    }
    fd = malloc((argc - 1) * sizeof(int));
    lines = malloc((argc - 1) * sizeof(char *));
    if (!fd || !lines)
        return (1);
    for (i = 0; i < argc - 1; i++)
    {
        fd[i] = open(argv[i + 1], O_RDONLY);
        if (fd[i] < 0)
        {
            perror("Error opening file");
            while (i-- > 0)
                close(fd[i]);
            free(fd);
            free(lines);
            return (1);
        }
        lines[i] = NULL;
    }
    active_fds = argc - 1;
    while (active_fds > 0)
    {
        for (i = 0; i < argc - 1; i++)
        {
            if (fd[i] >= 0)
            {
                lines[i] = get_next_line(fd[i]);
                if (lines[i])
                {
                    printf("File%d: %s\n", i + 1, lines[i]);
                    free(lines[i]);
                }
                else
                {
                    close(fd[i]);
                    fd[i] = -1;
                    active_fds--;
                }
            }
        }
    }
    free(fd);
    free(lines);
    return (0);
}