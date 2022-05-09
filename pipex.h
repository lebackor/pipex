#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
#include <sys/wait.h>
#include <stdio.h>

typedef struct s_data{
    char **av;
    char **env;
    char *str;
    char **paths;
    char *cmdargs;
    char **avsplit;
    int f1;
    int f2;
    int cmd1;
    int cmd2;
    int end[2];
    int status;
    int i;
    int j;
    int k;
    pid_t parent;

}   t_data;

size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_strcmp(char *s1, char *s2);
char *parsing(t_data *p);
int	ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char *parse_split(t_data *p);
char	*ft_strjoin(char const *s1, char const *s2);
int ft_exit(t_data p);
char    *parse_child(t_data *p);
#endif