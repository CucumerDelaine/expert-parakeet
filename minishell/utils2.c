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

#include "minishell.h"

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
