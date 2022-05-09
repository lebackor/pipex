#include <stdio.h>
#include "pipex.h"

void    child_process(t_data p)
{

    dup2(p.f1, STDIN_FILENO);
    dup2(p.end[1], STDOUT_FILENO);
    execve(p.str, p.avsplit, p.env);
    printf("Command not found: %s\n", p.str);
    close(p.end[0]);
    close(p.f1);
    exit(1);
 //   exit(EXIT_FAILURE);
}

void second_child(t_data p)
{
    p.str = parse_child(&p);
    dup2(p.end[0], STDIN_FILENO);
    dup2(p.f2, STDOUT_FILENO);
    execve(p.str, p.avsplit, p.env);
        printf("Command not found: %s\n", p.str);

    close(p.end[1]);
    close(p.f2);
    exit(1);
   // exit(EXIT_FAILURE);
}

void pipex(t_data p)
{
    int stock[2];
    pipe(p.end);
    p.str = parse_split(&p);
    if (!p.str)
        ft_exit(p);
    p.parent = fork();
    stock[0] = p.parent;
    if (p.parent < 0)
        return ; //
    if (p.parent == 0)
        child_process(p);
    p.parent = fork();
    stock[1] = p.parent;
    //
    if (p.parent == 0)
        second_child(p);
    for (int i = 0;i<2;i++)
        waitpid(stock[i], &p.status, 0);
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
   // if (!p.f1 | !p.f2)
    //    return (-1);
    pipex(p);
    

}