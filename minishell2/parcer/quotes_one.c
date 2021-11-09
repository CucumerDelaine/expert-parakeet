#include "../minishell.h"

char	*ft_freez_three(char *tmp, char *tmp2, char *tmp3, char *str)
{
	ft_freez(tmp);
	ft_freez(tmp2);
	ft_freez(tmp3);
	return (str);
}

char	*ft_quotes_one_cont(char *tmp, char *tmp2, char *tmp3, int *i)
{
	char	*freez;
	char	*str;

	str = ft_strjoin(tmp, tmp2);
	*i -= 2;
	freez = str;
	str = ft_strjoin(str, tmp3);
	ft_freez(freez);
	return (ft_freez_three(tmp, tmp2, tmp3, str));
}

char	*ft_quotes_one(char *str, int *i)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*freez;

	j = *i;
	(*i)++;
	while (str[(*i)])
	{
		if (str[(*i)] == '\'')
			break ;
		(*i)++;
	}
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str, j + 1, *i - j - 1);
	tmp3 = strdup(str + *i + 1);
	if (only_service(tmp2[0]) && tmp[ft_strlen(tmp) - 1] == ' ' && \
	(tmp3[0] == ' ' || tmp3[0] == '\0' || ft_strlen(tmp3) == 0))
		return (ft_freez_three(tmp, tmp2, tmp3, str));
	ft_freez(str);
	return (ft_quotes_one_cont(tmp, tmp2, tmp3, i));
}

char	*ft_quotes_one_two_cont(char *tmp, char *tmp2, char *tmp3, int *i)
{
	char	*freez;
	char	*str;

	str = ft_strjoin(tmp, tmp2);
	*i -= 1;
	freez = str;
	str = ft_strjoin(str, tmp3);
	ft_freez(freez);
	return (ft_freez_three(tmp, tmp2, tmp3, str));
}

char	*ft_quotes_one_two(char *str, int *i)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*freez;

	j = *i;
	while (str[++(*i)])
	{
		if (str[(*i)] == '\'')
			break ;
	}
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str, j + 1, *i - j - 1);
	tmp3 = strdup(str + *i + 1);
	ft_freez(str);
	return (ft_quotes_one_two_cont(tmp, tmp2, tmp3, i));
}
