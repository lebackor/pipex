#include "pipex.h"

char *parsing(t_data p)
{
    char *str;

    p.i = 0;
    while (p.i < 62)
    {
        p.k = 0;
        p.j = 0;
        str = malloc(sizeof(char) * ft_strlen(p.env[p.i]));
        while (p.env[p.i][p.j])
        {
            str[p.k] = p.env[p.i][p.j];
            p.k++;
            p.j++;
        }
        if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T')
            break;
        free(str);
        p.i++;
    }
    return (str);
}

char **parse_split(t_data p)
{
    char *str;
    int i = 0;
    str = parsing(p);
    while (str[i] != '/')
        i++;
    p.paths = ft_split(&str[i], ':');
    free(str);
    i = -1;
    p.cmdargs = ft_split(p.av[2], ' ');
   // while (p.cmdargs[++i])
   //     printf("%s\n", p.cmdargs[i]);

    return (p.paths);
}