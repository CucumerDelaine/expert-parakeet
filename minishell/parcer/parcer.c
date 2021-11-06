#include "../minishell.h"

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

void	ft_find_command(char **str, int *i, t_cmd **new, t_iter *iter, t_env **env)
{
	int	j;
	
	j = *i;
	if ((*str)[(*i)] == '\'' && ((*str)[(*i) + 1] == '|' || (*str)[(*i) + 1] == '<' || (*str)[(*i) + 1] == '>'))
		(*str) = ft_quotes_one_two((*str), i);
	else if ((*str)[(*i)] == '\"' && ((*str)[(*i) + 1] == '|' || (*str)[(*i) + 1] == '<' || (*str)[(*i) + 1] == '>'))
		(*str) = ft_quotes_two_two((*str), i, env);
	while (!service_char((*str)[*i]))
		(*i)++;
	if (iter->res == NULL || ft_strlen(iter->res) == 0)
	{
		iter->word = ft_substr((*str), j, (*i) - j);
		(*new) = ft_lstnew_cmd(iter->word);
		free(iter->word);
		iter->word = NULL;
	}
	else
	{
		(*new) = ft_lstnew_cmd(iter->res);
		(*i) = ft_strlen(iter->res);
		free (iter->res);
		iter->res = NULL;
	}
	while (ft_is_space((*str)[*i]) && (*str)[*i] != '\0')
		(*i)++;
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

void	ft_find_argum(char **str, int *i, t_iter *iter, t_cmd *new, t_env **env)
{
	int	j;

	while (!service_char((*str)[*i]))
	{
		j = (*i);
		if ((*str)[(*i)] == '\'' && ((*str)[(*i) + 1] == '|' || (*str)[(*i) + 1] == '<' || (*str)[(*i) + 1] == '>'))
			(*str) = ft_quotes_one_two((*str), i);
		else if ((*str)[(*i)] == '\"' && ((*str)[(*i) + 1] == '|' || (*str)[(*i) + 1] == '<' || (*str)[(*i) + 1] == '>'))
			(*str) = ft_quotes_two_two((*str), i, env);
		while (!service_char((*str)[*i]))
			(*i)++;
		iter->argum = ft_substr((*str), j, (*i) - j);
		ft_lstadd_argum(&new, iter->argum);
		free(iter->argum);
		iter->argum = NULL;
		while (ft_is_space((*str)[(*i)]))
			(*i)++;
	}
}

void	ft_pipe_redir(char *str, int *i, t_cmd **cmd, t_cmd *new)
{
	if (str[*i] == '|')
	{
		(*i)++;
		while (ft_is_space(str[*i]) && str[*i] != '\0')
			(*i)++;
		ft_lstadd_back_cmd(cmd, new);
		new = NULL;
	}
	else if ((str[*i] == '>' || str[*i] == '<'))
	{
		if (new == NULL)
			new = ft_lstnew_cmd(NULL);
		ft_redir(&new, str, i);
	}
}

int	ft_common_parcer(char **str, t_cmd **cmd, t_cmd **new, t_iter *iter, t_env **env)
{
	int	i;

	i = 0;
	while ((*str)[i] != '\0')
	{
		while (ft_is_space((*str)[i]))
			i++;
		if (!service_char((*str)[i]))
		{
			ft_find_command(str, &i, new, iter, env);
			ft_find_flags(*str, *new, iter, &i);
			ft_find_argum(str, &i, iter, *new, env);
		}
		ft_pipe_redir(*str, &i, cmd, *new);
	}
	return (i);
}

int	postparser(char *str, t_cmd *new, t_cmd **cmd, t_env **our_env)
{
	int		i;
	int		j;
	t_iter	*iter;

	ft_init_iter(&iter);
	i = 0;
	str = ft_strtrim(str, "\t\n\v\f\r ");
	if (str[i] == '\0')
		return (1);
	ft_parcer(&str, our_env, &iter);
	if (str == NULL)
		return (ft_freez(iter));
	i = ft_common_parcer(&str, cmd, &new, iter, our_env);
	if (str[i] == '\0')
	{
		ft_lstadd_back_cmd(cmd, new);
		free (str);
		str = NULL;
		new = NULL;
		free (iter);
		iter = NULL;
		return (0);
	}
	return (0);
}
