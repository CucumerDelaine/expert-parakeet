/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <erichell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:39:06 by erichell          #+#    #+#             */
/*   Updated: 2021/11/18 13:08:24 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_freez(void *freez)
{
	free(freez);
	freez = NULL;
	return (1);
}

char	*ft_find_doll(char *str, int *i, int j, char *tmp2)
{
	char	*freez;
	char	*tmp;
	char	*tmp3;

	freez = NULL;
	tmp = NULL;
	tmp3 = NULL;
	tmp = ft_substr(str, 0, j);
	tmp3 = ft_substr(str, (*i), ft_strlen(str) - (*i));
	freez = str;
	str = ft_strjoin(tmp, tmp2);
	ft_freez(freez);
	freez = str;
	str = ft_strjoin(str, tmp3);
	*i = ft_strlen(str) - 2;
	ft_freez(freez);
	ft_freez(tmp);
	ft_freez(tmp3);
	return (str);
}

char	*ft_no_find_doll(int *i, int j, char *str)
{
	char	*tmp;
	char	*tmp3;
	char	*freez;

	tmp = NULL;
	tmp3 = NULL;
	tmp = ft_substr(str, 0, j);
	tmp3 = ft_substr(str, (*i), ft_strlen(str) - (*i));
	if (ft_strlen(tmp) == 0 && ft_strlen(tmp3) == 0)
	{
		ft_freez(str);
		ft_freez(tmp);
		ft_freez(tmp3);
		return (NULL);
	}
	freez = str;
	str = ft_strjoin(tmp, tmp3);
	ft_freez(freez);
	ft_freez(tmp);
	ft_freez(tmp3);
	(*i) = j - 1;
	return (str);
}

char	*ft_dollar(char *str, int *i, t_env **env)
{
	int		j;
	char	*tmp;
	char	*tmp2;

	j = (*i);
	tmp = NULL;
	tmp2 = NULL;
	if (str[(*i) + 1] == '$' || str[(*i) + 1] == '?' || str[(*i) + 1] \
	== ' ' || ft_is_space(str[(*i) + 1]))
		return (ft_other_dollar(str, (*i)));
	while (str[++(*i)])
	{
		if (!ifkey(str[(*i)]))
			break ;
	}
	if ((*i) == j + 1)
		return (str);
	tmp = ft_substr(str, j + 1, (*i) - j - 1);
	if (ft_find_list_env(tmp, env))
		tmp2 = ((ft_find_list_env(tmp, env))->value);
	ft_freez(tmp);
	if (tmp2)
		return (ft_find_doll(str, i, j, tmp2));
	else
		return (ft_no_find_doll(i, j, str));
}

char	*ft_other_dollar(char *str, int i)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*freez;

	(i)++;
	tmp2 = "";
	tmp = ft_substr(str, 0, i - 1);
	if (str[i] == '$')
		tmp2 = ft_itoa(getpid());
	else if (str[i] == '?')
		tmp2 = ft_itoa(g_status_error);
	else
		tmp2 = ft_strdup("$ ");
	tmp3 = ft_strdup(str + i + 1);
	freez = str;
	str = ft_strjoin(tmp, tmp2);
	ft_freez(freez);
	freez = str;
	str = ft_strjoin(str, tmp3);
	ft_freez(freez);
	return (ft_freez_three(tmp, tmp2, tmp3, str));
}
