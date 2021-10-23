/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_d_red.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 12:19:00 by cdelaine          #+#    #+#             */
/*   Updated: 2021/10/23 12:19:02 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	strcount(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->red_words[i])
		i++;
	return (i);
}

void	ctrl_wd(int signum)
{
	(void)signum;
	g_status_error = 130;
}

void	back_d_red_child(t_cmd *cmd, int *fd, int count)
{
	int		i;
	char	*str;

	i = 0;
	close(fd[0]);
	while (i < count)
	{
		if (i < count)
			str = readline("> ");
		if (i < count)
		{
			if (!ft_strncmp_nr(str, cmd->red_words[i], ft_strlen(str)))
				i++;
			else if (i == count - 1)
			{
				ft_putstr_fd(str, fd[1]);
				write(fd[1], "\n", 1);
			}
			// if (g_status_error == 130)
			// 	exit(130);
		}
		free(str);
	}
	close(fd[1]);
	// if (g_status_error == 130)
	// 	exit(130);
	exit(0);
}

void	back_d_red(t_cmd *cmd)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	// signal(SIGINT, ctrl_wd);
	// signal(SIGQUIT, SIG_IGN);
	if (!pid)
		back_d_red_child(cmd, fd, strcount(cmd));
	errr1(pid, 1);
	if (g_status_error == 130)
	{
		close(fd[0]);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		cmd->fd_red = fd[0];
	}
	signal(SIGINT, ft_ctrl_c);
}
