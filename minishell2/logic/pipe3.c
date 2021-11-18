/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:43:13 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/18 12:44:36 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	one_pipe_1(t_cmd *cmd, t_env *env, char **oenv, int *fd)
{
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	find_comand(cmd, env, oenv);
	exit(0);
}

void	one_pipe_2(t_cmd *cmd, t_env *env, char **oenv, int *fd)
{
	int	i;

	dup2(fd[0], 0);
	close(fd[0]);
	i = find_comand(cmd, env, oenv);
	exit(i);
}

void	init_flag_i(int *flag, int *i)
{
	*flag = 0;
	*i = 0;
}

void	find_comand2(t_cmd *cmd, t_env *env, char **oenv)
{
	find_comand(cmd, env, oenv);
	exit(0);
}
