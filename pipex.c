#include <stdio.h>
#include "pipex.h"

void    child_process(t_data p)
{
    dup2(p.f1, STDIN_FILENO);
    return ;
}

void parent_process(t_data p)
{
    waitpid(-1, &p.status, 0);

    printf("c bon mgl ta fini\n");
    return ;
}

void pipex(t_data p)
{

    pipe(p.end);
    p.parent = fork();
    p.str = parse_split(p);
    if (p.parent < 0)
        return ;
    if (!p.parent)
        child_process(p);
    else
        parent_process(p);
}
int main(int ac, char **av, char **envp)
{
    t_data p;

    (void) ac;
    p.av = av;
    p.env = envp;
    p.i = -1;
    p.f1 = open(av[1], O_RDONLY);
    p.f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644); // comprendre 0644
    if (!p.f1 | !p.f2)
        return (-1);
    while (p.env[++p.i])
        printf("%s\n", p.env[p.i]);
    pipex(p);
    

}