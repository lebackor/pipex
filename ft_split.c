#include "pipex.h"
int	is_not_sep(char const s, char c)
{
	if (s == c)
		return (0);
	return (1);
}

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (((!is_not_sep(s[i - 1], c) || i == 0)
				&& is_not_sep(s[i], c)) && s[i])
			count++;
		i++;
	}
	return (count);
}

char	**ft_free_table(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	*put_str_in_tab(char const *s, char c)
{
	int		i;
	char	*tab;

	i = 0;
	while (s[i] && is_not_sep(s[i], c))
		i++;
	tab = malloc(sizeof(*tab) * (i + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (s[i] && is_not_sep(s[i], c) && s[i] != '\n')
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		string;

	i = 0;
	string = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(*tab) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		if (((!is_not_sep(s[i - 1], c) || i == 0)
				&& is_not_sep(s[i], c)) && s[i])
		{
			tab[string] = put_str_in_tab(&s[i], c);
			if (!tab || tab == NULL)
				return (ft_free_table(tab));
			string++;
		}
		i++;
	}
	tab[string] = NULL;
	return (tab);
}