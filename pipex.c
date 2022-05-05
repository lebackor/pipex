#include <stdio.h>
#include "pipex.h"

void    child_process(t_data p)
{
    int i;
    char *cmd;

    i = 0;
    
    cmd = ft_strjoin(p.paths[i], p.av[2]);
    printf("%s\n", cmd);
    dup2(p.f1, STDIN_FILENO);
    dup2(p.end[1], STDOUT_FILENO);
    /*while (p.paths[++i])
    {
    }*/
    
    cmd = ft_strjoin(p.paths[i], p.av[2]);

    
    close(p.end[0]);
    close(p.f1);
    exit(EXIT_FAILURE);
}

void parent_process(t_data p)
{
    waitpid(-1, &p.status, 0);
    dup2(p.f2, p.end[1]);
    dup2(p.end[0], p.f1);
    
    close(p.end[1]);
    close(p.f2);
    exit(EXIT_FAILURE);
}

void pipex(t_data p)
{

    pipe(p.end);
    p.parent = fork();

    p.str = parse_split(p);
    if (p.parent < 0)
        return ;
 //   printf("%d\n", p.parent);
    if (p.parent == 0)
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
    pipex(p);
    

}