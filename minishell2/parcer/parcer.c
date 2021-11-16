/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <erichell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:53:37 by erichell          #+#    #+#             */
/*   Updated: 2021/11/16 18:50:57 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_find_command(char **str, int *i, t_cmd **new, \
t_iter *iter)
{
	int	j;

	j = *i;
	if ((*new) != NULL && (*new)->cmd != NULL)
		return ;
	if ((*str)[(*i)] == '\'')
		(*str) = ft_quotes_one_two((*str), i);
	else if ((*str)[(*i)] == '\"')
		(*str) = ft_quotes_two_two((*str), i);
	while (!service_char((*str)[*i]))
		(*i)++;
	if (iter->res == NULL || ft_strlen(iter->res) == 0)
	{
		iter->word = ft_substr((*str), j, (*i) - j);
		if (*new == NULL)
			(*new) = ft_lstnew_cmd(iter->word);
		else
			(*new)->cmd = ft_strdup(iter->word);
		free_iter_res_or_word(iter);
	}
	else
	{
		(*new) = ft_lstnew_cmd(iter->res);
		(*i) = ft_strlen(iter->res);
		free_iter_res_or_word(iter);
	}
	while (ft_is_space((*str)[*i]) && (*str)[*i] != '\0')
		(*i)++;
}

void	ft_find_argum(char **str, int *i, t_iter *iter, t_cmd *new)
{
	int	j;

	while (!service_char((*str)[*i]))
	{
		j = (*i);
		if ((*str)[(*i)] == '\'')
			(*str) = ft_quotes_one_two((*str), i);
		else if ((*str)[(*i)] == '\"')
			(*str) = ft_quotes_two_two((*str), i);
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

int	ft_pipe_redir(char *str, int *i, t_cmd **cmd, t_cmd **new)
{
	if (str[*i] == '|')
	{
		(*i)++;
		while (ft_is_space(str[*i]) && str[*i] != '\0')
			(*i)++;
		ft_lstadd_back_cmd(cmd, *new);
		*new = NULL;
	}
	else if ((str[*i] == '>' || str[*i] == '<'))
	{
		if (*new == NULL)
			*new = ft_lstnew_cmd(NULL);
		if (ft_redir(new, str, i))
		{
			g_status_error = 1;
			return (1234);
		}
	}
	return (0);
}

int	ft_common_parcer(char **str, t_cmd **cmd, t_cmd **new, \
t_iter *iter)
{
	int	i;

	i = 0;
	while ((*str)[i] != '\0')
	{
		while (ft_is_space((*str)[i]))
			i++;
		if (!service_char((*str)[i]))
		{
			ft_find_command(str, &i, new, iter);
			ft_find_flags(*str, *new, iter, &i);
			ft_find_argum(str, &i, iter, *new);
		}
		if (ft_pipe_redir(*str, &i, cmd, new))
			return (1234);
		if (iter->res != NULL)
		{
			free(iter->res);
			iter->res = NULL;
		}
	}
	return (i);
}

int	postparser(char *str, t_cmd *new, t_cmd **cmd, t_env **our_env)
{
	int		i;
	t_iter	*iter;

	ft_init_iter(&iter);
	i = 0;
	str = ft_strtrim(str, "\t\n\v\f\r ");
	if (str[i] == '\0')
		return (1);
	ft_parcer(&str, our_env, &iter);
	if (str == NULL)
		return (ft_freez(iter));
	i = ft_common_parcer(&str, cmd, &new, iter);
	if (str[i] == '\0')
	{
		ft_lstadd_back_cmd(cmd, new);
		free (str);
		str = NULL;
		new = NULL;
		ft_free_iter(&iter);
		if ((*cmd) == NULL || i == 1234)
			return (1);
		return (0);
	}
	return (0);
}
