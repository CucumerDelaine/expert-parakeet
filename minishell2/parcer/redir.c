/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <erichell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:39:30 by erichell          #+#    #+#             */
/*   Updated: 2021/11/18 12:39:31 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_forward_one(t_cmd **cmd, int *i, char *str)
{
	char	*file;
	int		fd_next;
	int		j;

	*i = (*i) + 2;
	while (ft_is_space(str[*i]))
		(*i)++;
	j = (*i);
	while (!service_char(str[(*i)]))
		(*i)++;
	file = ft_substr(str, j, (*i) - j);
	fd_next = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd_next < 0)
	{
		printf("minishell:> %s: %s\n", file, strerror(errno));
		ft_freez(file);
		return (1);
	}
	(*cmd)->fd_out = fd_next;
	if (ft_strchr(str + (*i), '>'))
		close(fd_next);
	while (ft_is_space(str[*i]))
		(*i)++;
	free(file);
	return (0);
}

int	ft_forward_two(t_cmd **cmd, int *i, char *str)
{
	char	*file;
	int		fd_next;
	int		j;

	*i = (*i) + 1;
	while (ft_is_space(str[*i]))
		(*i)++;
	j = (*i);
	while (!service_char(str[(*i)]))
		(*i)++;
	file = ft_substr(str, j, (*i) - j);
	fd_next = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_next < 0)
	{
		printf("minishell:> %s: %s\n", file, strerror(errno));
		ft_freez(file);
		return (1);
	}
	(*cmd)->fd_out = fd_next;
	if (ft_strchr(str + (*i), '>'))
		close(fd_next);
	while (ft_is_space(str[*i]))
		(*i)++;
	free(file);
	return (0);
}

void	ft_back_one(t_cmd **cmd, int *i, char *str)
{
	int	j;

	(*cmd)->back_d_red = 1;
	*i = (*i) + 2;
	while (ft_is_space(str[*i]))
		(*i)++;
	j = (*i);
	while (!service_char(str[(*i)]))
		(*i)++;
	(*cmd)->red_words[(*cmd)->word_num] = ft_substr(str, j, (*i) - j);
	(*cmd)->word_num++;
	while (ft_is_space(str[*i]))
		(*i)++;
}

int	ft_back_two(t_cmd **cmd, int *i, char *str)
{
	char	*file;
	int		fd_back;
	int		j;

	*i = (*i) + 1;
	while (ft_is_space(str[*i]))
		(*i)++;
	j = (*i);
	while (!service_char(str[(*i)]))
		(*i)++;
	file = ft_substr(str, j, (*i) - j);
	fd_back = open(file, O_RDONLY, 0644);
	if (fd_back < 0)
	{
		printf("minishell:> %s: %s\n", file, strerror(errno));
		ft_freez(file);
		return (1);
	}
	(*cmd)->fd_in = fd_back;
	if (ft_strchr(str + (*i), '<'))
		close(fd_back);
	while (ft_is_space(str[*i]))
		(*i)++;
	free(file);
	return (0);
}

int	ft_redir(t_cmd **cmd, char *str, int *i)
{
	if (str[*i] == '<' && str[*i + 1] == '<' && str[*i + 2] == '<')
	{	
		printf("syntax error near unexpected token '<<'\n");
		return (1);
	}
	if (str[*i] == '>')
	{
		if (str[*i + 1] == '>')
			return (ft_forward_one(cmd, i, str));
		else if (str[*i + 1] != '>')
			return (ft_forward_two(cmd, i, str));
	}
	else if (str[(*i)] == '<')
	{
		if (str[(*i) + 1] == '<')
			ft_back_one(cmd, i, str);
		else if (str[*i + 1] != '<')
			return (ft_back_two(cmd, i, str));
	}
	return (0);
}
