#include "pipex.h"

char *parsing(t_data *p)
{
    char *str;

    p->i = 0;
    while (p->i < 62)
    {
        p->k = 0;
        p->j = 0;
        str = malloc(sizeof(char) * ft_strlen(p->env[p->i]) + 1);
        if (!str)
            ft_exit_fail(p);
        while (p->env[p->i][p->j])
        {
            str[p->k] = p->env[p->i][p->j];
            p->k++;
            p->j++;
        }
        str[p->k] = '\0';
        if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T')
            break;
        free(str);
        str = NULL;
        p->i++;
    }
    return (str);
}

char *parse_split(t_data *p)
{
    char *str;
    char *raciste;
    int i;

    i = 0;
    p->j = 1;
    str = parsing(p);
    while (str[i] != '/' && str[i])
        i++;
    p->paths = ft_split(&str[i], ':');
    if (str)
        free(str);
    i = -1;
    p->avsplit = ft_split(p->av[2], ' ');
    while (p->paths[++i] && p->j != 0)
    {
        raciste = ft_strjoin(p->paths[i], "/");
        p->cmdargs = ft_strjoin(raciste, p->avsplit[0]);
        free(raciste);
        p->j = access(p->cmdargs, X_OK);
        if (p->j == 0)
            return p->cmdargs;
        free(p->cmdargs);
        p->cmdargs = NULL;
    }
    // ft_putstr_fd(p->av[2], STDOUT_FILENO);
    // ft_putstr_fd(": command not found\n", STDOUT_FILENO);
    ft_free_table(p->avsplit);
    return (NULL);
}
char    *parse_child(t_data *p)
{
    char *str;
    int i;
    char *raciste;

    i = 0;
    p->j = 1;
    str = parsing(p);
    while (str[i] != '/')
        i++;
    p->pathschild = ft_split(&str[i], ':');
    if (str)
        free(str);
    i = -1;
    p->avsplitchild = ft_split(p->av[3], ' ');
    while (p->pathschild[++i] && p->j != 0)
    {
            raciste = ft_strjoin(p->pathschild[i], "/");
            p->cmdargschild = ft_strjoin(raciste, p->avsplitchild[0]);
            free(raciste);
        p->j = access(p->cmdargschild, X_OK);
        if (p->j == 0)
            return p->cmdargschild;
        free(p->cmdargschild);
        p->cmdargschild = NULL;
    }
    // ft_putstr_fd(p.av[3], STDOUT_FILENO);
    // ft_putstr_fd(": command not found\n", STDOUT_FILENO);
    ft_free_table(p->avsplitchild);
    p->avsplitchild = NULL;
    return (NULL);    
}
/*
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
    if (p->j < 0)
        perror("");// not workingp
    return (NULL);
}*/