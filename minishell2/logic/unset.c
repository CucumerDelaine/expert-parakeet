/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:43:34 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/18 12:43:53 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (s2 == NULL || s1 == NULL)
		return (1);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_delete_list_env(char *key, t_env **env)
{
	t_env	*tmp;
	t_env	*tmp_2;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->next->key, key))
		{
			tmp_2 = tmp->next->next;
			if (tmp->next->key)
				free(tmp->next->key);
			if (tmp->next->value)
				free(tmp->next->value);
			free(tmp->next);
			tmp->next = tmp_2;
			return ;
		}
		tmp = tmp->next;
	}
}

t_env	*ft_find_list_env(char *find, t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strcmp(find, tmp->key))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int	comand_unset(t_cmd *cmd, t_env *envp)
{
	int	i;

	i = 0;
	while (cmd->argum[i])
	{	
		if (ft_find_list_env(cmd->argum[i], &envp))
			ft_delete_list_env(cmd->argum[i], &envp);
		i++;
	}
	return (0);
}
