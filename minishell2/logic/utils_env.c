/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:43:42 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/18 12:43:53 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_lstnew_env(char *key, char *value)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->next = NULL;
	if (!(ft_strncmp(key, "SHLVL", 5)))
	{
		free(value);
		value = ft_itoa(ft_atoi(value) + 1);
	}
	if (!(ft_strncmp(key, "OLDPWD", 6)))
	{
		free(value);
		value = 0;
	}
	new->key = key;
	new->value = value;
	return (new);
}

void	ft_lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*low;

	if (lst && new)
	{
		low = *lst;
		if (low == NULL)
			(*lst) = new;
		else
		{
			while (low->next != NULL)
				low = low->next;
			low->next = new;
		}
	}
}

void	ft_lstclear_env(t_env **lst)
{
	t_env	*low;
	t_env	*temp;

	low = *lst;
	while (low)
	{
		temp = low;
		low = low->next;
		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

int	ft_fill_env(char **env, t_env **our_env)
{
	int		i;
	int		j;
	t_env	*new;

	i = 0;
	j = 0;
	while (env[i])
	{
		while (env[i][j] != '=')
			j++;
		new = ft_lstnew_env(ft_substr(env[i], 0, j), ft_substr(env[i], \
		j + 1, ft_strlen(env[i])));
		if (!new)
		{
			ft_lstclear_env(&new);
			return (1);
		}
		ft_lstadd_back_env(our_env, new);
		j = 0;
		i++;
	}
	return (0);
}
