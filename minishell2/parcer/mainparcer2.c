/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainparcer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <erichell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:39:13 by erichell          #+#    #+#             */
/*   Updated: 2021/11/18 12:39:14 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strchr_n(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (i);
	return (0);
}

void	ft_init_iter(t_iter **iter)
{
	*iter = malloc(sizeof(t_iter));
	(*iter)->tmp = NULL;
	(*iter)->full = 0;
	(*iter)->res = NULL;
	(*iter)->word = NULL;
	(*iter)->argum = NULL;
	(*iter)->flags = NULL;
}

int	ft_shr_print(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_free_cmd_cont(t_cmd **new)
{
	t_cmd	*tmp;

	free((*new)->cmd);
	(*new)->cmd = NULL;
	free((*new)->red_words);
	(*new)->red_words = NULL;
	free((*new)->flags);
	(*new)->flags = NULL;
	free((*new)->argum);
	(*new)->argum = NULL;
	tmp = *new;
	(*new) = ((*new)->next);
	free(tmp);
	tmp = NULL;
}

int	ft_free_cmd(t_cmd **new)
{
	int	i;

	if (!new)
		return (1);
	if (*new != NULL)
	{
		while (*new)
		{
			i = -1;
			while ((*new)->flags[++i] != NULL)
				free((*new)->flags[i]);
			i = -1;
			while ((*new)->argum[++i] != NULL)
				free((*new)->argum[i]);
			i = -1;
			while ((*new)->red_words[++i] != NULL)
				free((*new)->red_words[i]);
			ft_free_cmd_cont(new);
		}
	}
	return (0);
}
