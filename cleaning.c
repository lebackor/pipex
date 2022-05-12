#include "pipex.h"
void ft_exit(t_data *p)
{
    if (p->paths)
        ft_free_table(p->paths);
    if (p->cmdargs)
        free(p->cmdargs);
 //  exit(0);
}

void ft_exit_fail(t_data *p)
{
    if (p->str)
        free(p->str);
    if (p->cmdargs)
        free(p->cmdargs);
    if (p->avsplit)
        ft_free_table(p->avsplit);
    if (p->paths)
        ft_free_table(p->paths);
    exit(1);
}