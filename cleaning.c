#include "pipex.h"
void ft_exit(t_data *p, int i)
{
    /*if (i == 0)
    {
        if (p->pathschild)
            free(p->pathschild);
        if (p->cmdargschild) 
            free(p->cmdargschild);
    }
    if (i == 1)
    {
        if (p->paths)
            ft_free_table(p->paths);
        if (p->cmdargs)
            free(p->cmdargs);
    }*/
    (void) p;
    (void )i;
 //  exit(0);
}

void ft_exit_fail(t_data *p)
{
    if (p->str)
        free(p->str);
    if (p->strchild)
        free(p->strchild);
    if (p->cmdargschild)
        free(p->cmdargschild);
    if (p->cmdargs)
        free(p->cmdargs);
    if (p->avsplit)
        ft_free_table(p->avsplit);
    if (p->avsplitchild)
        ft_free_table(p->avsplitchild);    
    if (p->paths)
        ft_free_table(p->paths);
    exit(0);
    //exit(EXIT_FAILURE);
}