#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	size_t	i;
	char	*str;

    if (!s1 || !s2)
		return (NULL);
	i = 0;
	a = ft_strlen(s1);
	//str = ft_calloc(a + ft_strlen(s2) + 1, sizeof(char));
    str = malloc(sizeof(char) * (a + ft_strlen(s2) + 1));
    if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[a] = s2[i];
		a++;
		i++;
	}
    str[a] = '\0';
	return (str);
}