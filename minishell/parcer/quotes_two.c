#include "../minishell.h"

char	*ft_quotes_two_cont(char *tmp, char *tmp2, char *tmp3, int *i)
{
	char	*freez;
	char	*str;

	str = ft_strjoin(tmp, tmp2);
	if (ft_strlen(str) == 0)
		*i = 0;
	else
		*i = ft_strlen(str) - 1;
	freez = str;
	str = ft_strjoin(str, tmp3);
	ft_freez(freez);
	if (ft_strlen(tmp) == 0 && ft_strlen(tmp2) == 0 && ft_strlen(tmp3) == 0)
	{	
		ft_freez(str);
		return (ft_freez_three(tmp, tmp2, tmp3, NULL));
	}
	return (ft_freez_three(tmp, tmp2, tmp3, str));
}

char	*ft_quotes_two_two_cont(char *tmp, char *tmp2, char *tmp3, int *i)
{
	char	*freez;
	char	*str;

	str = ft_strjoin(tmp, tmp2);
	*i -= 1;
	freez = str;
	str = ft_strjoin(str, tmp3);
	ft_freez(freez);
	if (ft_strlen(tmp) == 0 && ft_strlen(tmp2) == 0)
	{
		ft_freez(str);
		return (ft_freez_three(tmp, tmp2, tmp3, NULL));
	}
	return (ft_freez_three(tmp, tmp2, tmp3, str));
}

char	*ft_quotes_two(char *str, int *i, t_env **env)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*freez;

	j = *i;
	(*i)++;
	while (str[*i])
	{
		if (str[(*i)] == '\"')
			break ;
		if (str[*i] == '$')
		{
			str = ft_dollar(str, *i, env);
			(*i)--;
		}
		(*i)++;
	}
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str, j + 1, *i - j - 1);
	tmp3 = ft_strdup(str + *i + 1);
	if (only_service(tmp2[0]) && tmp[ft_strlen(tmp) - 1] == ' ' && (tmp3[0] == ' ' || tmp3[0] == '\0' || ft_strlen(tmp3) == 0))
		return (ft_freez_three(tmp, tmp2, tmp3, str));
	ft_freez(str);
	return (ft_quotes_two_cont(tmp, tmp2, tmp3, i));
}

char	*ft_quotes_two_two(char *str, int *i, t_env **env)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*freez;

	j = *i;
	(*i)++;
	while (str[*i])
	{
		if (str[(*i)] == '\"')
			break ;
		if (str[*i] == '$')
			str = ft_dollar(str, *i, env);
		(*i)++;
	}
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str, j + 1, *i - j - 1);
	tmp3 = ft_strdup(str + *i + 1);
	ft_freez(str);
	return (ft_quotes_two_two_cont(tmp, tmp2, tmp3, i));
}