#include "pipex.h"
void ft_exit(t_data *p)
{
    if (p->avsplit)
        free(p->avsplit);
    if (p->str)
        free(p->str);
    if (p->paths)
        free(p->paths);
    exit(1);
}