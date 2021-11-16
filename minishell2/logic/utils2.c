/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:49:24 by cdelaine          #+#    #+#             */
/*   Updated: 2021/10/25 18:49:26 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_putstr_fd2(char *s, int *fd)
{
	ft_putstr_fd(s, fd[1]);
	write(fd[1], "\n", 1);
}

int	strcount(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->red_words[i])
		i++;
	return (i);
}

void	free_func(char *key, char *value, t_env *env)
{
	free(key);
	free(env);
	if (value != NULL)
		free(value);
}

int	ft_search_sumb(char *tmp2)
{
	if (ft_strchr(tmp2, '<') || ft_strchr(tmp2, '>') || ft_strchr(tmp2, '|'))
		return (1);
	else
		return (0);
}

void	ft_ctrl_bs_cat(int id)
{
	(void) id;
	write(1, "Quit: 3\n", 8);
	g_status_error = 131;
}
