/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_export_comand3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:43:27 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/18 12:45:27 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_copy_env(t_env *env, t_env **copy)
{
	t_env	*tmp;
	t_env	*new;
	char	*key;
	char	*value;

	tmp = env;
	while (tmp != NULL)
	{
		new = (t_env *)malloc(sizeof(t_env));
		if (!new)
			return (NULL);
		key = tmp->key;
		value = tmp->value;
		new->key = key;
		new->value = value;
		new->next = NULL;
		ft_lstadd_back_env(copy, new);
		tmp = tmp->next;
	}
	return (*copy);
}

int	check_var(char *var)
{
	int	i;

	i = 0;
	while (var[i] && var[i] != '=')
	{
		if (i == 0 && !ft_isalpha(var[i]))
			return (1);
		if (i != 0 && !ft_isalpha(var[i])
			&& !ft_isdigit(var[i]) && var[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

void	get_key_value(char **key, char **value, char *var)
{
	char	*sep;

	sep = ft_strchr(var, '=');
	if (sep)
	{
		*key = ft_substr(var, 0, ft_strlen(var) - ft_strlen(sep));
		*value = ft_strdup(sep + 1);
	}
	else
	{
		*key = ft_strdup(var);
		*value = NULL;
	}
}
