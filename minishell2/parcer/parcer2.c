#include "../minishell.h"

void	free_iter_res_or_word(t_iter *iter)
{
	if (iter->res == NULL || ft_strlen(iter->res) == 0)
	{
		free(iter->word);
		iter->word = NULL;
	}
	else
	{
		free (iter->res);
		iter->res = NULL;
	}
}

void	ft_iter_cont(t_iter **iter, char **str, int i)
{
	(*iter)->res = ft_substr((*str), 0, i + 1);
	(*iter)->full = 1;
}

void	ft_parcer(char **str, t_env **our_env, t_iter **iter)
{
	int		i;

	i = 0;
	while ((*str) != NULL && (*str)[i])
	{
		if ((*str)[i] == '\'')
			(*str) = ft_quotes_one((*str), &i);
		else if ((*str)[i] == '$')
			(*str) = ft_dollar((*str), i, our_env);
		else if ((*str)[i] == '\"')
		{
			(*str) = ft_quotes_two((*str), &i, our_env);
			if ((*str)[i] == '\"' && (*str)[i + 1] == '|')
				(*str) = ft_quotes_two((*str), &i, our_env);
		}
		if (((*str) != NULL && ((ft_is_space((*str)[i + 1]) || \
		(*str)[i + 1] == '\0')) && (*iter)->full == 0) || \
		((*str) != NULL && (only_service((*str)[i + 1])) \
		&& (*iter)->full == 0 && ((*str)[i + 1] == ' ' \
		|| (*str)[i - 1] == ' ')))
			ft_iter_cont(iter, str, i);
		if ((*str) == NULL)
			return ;
		i++;
	}
}

void	ft_find_flags(char *str, t_cmd *new, t_iter *iter, int *i)
{
	int	j;

	while (str[*i] == '-' && !service_char(str[(*i) + 1]))
	{
		j = (*i);
		while (!service_char(str[(*i)]))
			(*i)++;
		iter->flags = ft_substr(str, j, (*i) - j);
		ft_lstadd_flags(&new, iter->flags);
		free(iter->flags);
		iter->flags = NULL;
		while (ft_is_space(str[(*i)]) && str[(*i)] != '\0')
			(*i)++;
	}
}
