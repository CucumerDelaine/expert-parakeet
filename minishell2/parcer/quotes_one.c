/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <erichell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:39:25 by erichell          #+#    #+#             */
/*   Updated: 2021/11/18 12:39:26 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (strchr(tmp2, '|') || strchr(tmp2, '>') || strchr(tmp2, '<'))
		return (ft_freez_three(tmp, tmp2, tmp3, str));
	ft_freez(str);
	return (ft_quotes_one_cont(tmp, tmp2, tmp3, i));
}

char	*ft_quotes_one_two_cont(char *tmp, char *tmp2, char *tmp3, int *i)
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

char	*ft_quotes_one_two(char *str, int *i)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	j = *i;
	while (str[++(*i)])
	{
		if (str[(*i)] == '\'')
			break ;
	}
	tmp2 = ft_substr(str, j + 1, *i - j - 1);
	tmp = ft_substr(str, 0, j);
	tmp3 = strdup(str + *i + 1);
	ft_freez(str);
	return (ft_quotes_one_two_cont(tmp, tmp2, tmp3, i));
}
