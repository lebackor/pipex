#include <stdio.h>
#include "pipex.h"

void    child_process(t_data p)
{
    p.str = parse_split(&p);
    dup2(p.f1, STDIN_FILENO);
    dup2(p.end[1], STDOUT_FILENO);
    close(p.end[0]);
    close(p.f1);
    free(p.pathschild);
    free(p.cmdargschild);
    execve(p.str, p.avsplit, p.env);
    perror("Error");
    exit(EXIT_FAILURE);
}

void second_child(t_data p)
{  
    p.strchild = parse_child(&p);
    dup2(p.end[0], STDIN_FILENO);
    dup2(p.f2, STDOUT_FILENO);
    close(p.end[1]);
    close(p.f2);

    free(p.paths);
    free(p.cmdargs);
    execve(p.strchild, p.avsplitchild, p.env);
    perror("Error");
   exit(EXIT_FAILURE);
}

void pipex(t_data p)
{
    int i;
   
    i = -1;
    pipe(p.end);
  //  p.str = parse_split(&p);
   // p.strchild = parse_child(&p);
  //  if (!p.str || !p.strchild)
    //    return (ft_exit_fail(&p));
    p.parent = fork();
    if (p.parent < 0)
        return ;
    p.stock[0] = p.parent;
    if (p.parent == 0)
        child_process(p);
    p.parent = fork();
    if (p.parent < 0)
        return ;
    p.stock[1] = p.parent;
    if (p.parent == 0)
        second_child(p);
  while (++i < 1)
        waitpid(p.stock[i], &p.status, 0);
    //ft_exit(&p);
}
int main(int ac, char **av, char **envp)
{
    t_data p;

    if (ac != 5)
        return (1);
    p = (t_data){0};
    p.av = av;
    p.env = envp;
    p.i = -1;
    p.f1 = open(av[1], O_RDONLY);
    p.f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644); // comprendre 0644
    if (p.f1 < 0 || p.f2 < 0)
    {
        if (p.f1 < 0)
            perror(av[1]);
       // else
         //   perror(av[4]);
        ft_exit(&p);
    }
    pipex(p);
}