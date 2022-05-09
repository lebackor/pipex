#include "pipex.h"

char *parsing(t_data *p)
{
    char *str;

    p->i = 0;
    while (p->i < 62)
    {
        p->k = 0;
        p->j = 0;
        str = malloc(sizeof(char) * ft_strlen(p->env[p->i]));
        while (p->env[p->i][p->j])
        {
            str[p->k] = p->env[p->i][p->j];
            p->k++;
            p->j++;
        }
        if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T')
            break;
        free(str);
        p->i++;
    }
    return (str);
}

char *parse_split(t_data *p)
{
    char *str;
    int i = 0;
    p->j = 1;
    str = parsing(p);
    while (str[i] != '/')
        i++;
    p->paths = ft_split(&str[i], ':');
    free(str);
    i = -1;
   // while (p->paths[++i])
     //   printf("%s\n", p->paths[i]);
    p->avsplit = ft_split(p->av[2], ' ');
    while (p->paths[++i] && p->j != 0)
    {
        p->cmdargs = ft_strjoin(p->paths[i], "/");
        p->cmdargs = ft_strjoin(p->cmdargs, p->avsplit[0]);
        p->j = access(p->cmdargs, X_OK);
        if (p->j == 0)
            return p->cmdargs;
        free(p->cmdargs);
    }
    free(p->avsplit);
    //printf(" acces -> %s %d\n", p->cmdargs, p->j);
    return (NULL);
}

char    *parse_child(t_data *p)
{
    int i = -1;

    if (p->cmdargs)
        free(p->cmdargs);
    p->avsplit = ft_split(p->av[3], ' ');
    p->j = 1;
    while (p->paths[++i] && p->j != 0)
    {
        p->cmdargs = ft_strjoin(p->paths[i], "/");
        p->cmdargs = ft_strjoin(p->cmdargs, p->avsplit[0]);
        p->j = access(p->cmdargs, X_OK);
        if (p->j == 0)
            return p->cmdargs;
        free(p->cmdargs);
    }
    printf(" acces -> %s %d\n", p->cmdargs, p->j);
    return (NULL);
}