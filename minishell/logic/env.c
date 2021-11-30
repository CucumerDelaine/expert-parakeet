/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:40:43 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/18 12:41:33 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_envp(t_env *envp, int fd)
{
	t_env	*tmp;

	tmp = envp;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd(tmp->key, fd);
			write(fd, "=", 1);
			ft_putendl_fd(tmp->value, fd);
		}
		tmp = tmp->next;
	}
}

int	comand_env(t_cmd *cmd, t_env *env)
{
	print_envp(env, cmd->fd_out);
	return (0);
}
