/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_d_red2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:07:12 by cdelaine          #+#    #+#             */
/*   Updated: 2021/10/25 15:07:13 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_c_fork(int signum)
{
	(void)signum;
	g_status_error = 130;
	write(1, "\n", 1);
}

void static	ctrl_wd(int signum)
{
	(void)signum;
	g_status_error = 130;
}

void	back_d_red_child2(t_cmd *cmd, int *fd, int count)
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
			if (!ft_strncmp_nr(str, cmd->red_words[i], \
			ft_strlen(cmd->red_words[i])))
				i++;
			else if (i == count - 1)
				ft_putstr_fd2(str, fd);
		}
		free(str);
		if (!str)
			break ;
	}
	close(fd[1]);
	if (g_status_error == 130)
		exit (130);
	exit(0);
}

void	back_d_red2(t_cmd *cmd)
{
	int		fd[2];
	pid_t	pid;
	void	*sgnl;

	pipe(fd);
	pid = fork();
	signal(SIGINT, ctrl_wd);
	signal(SIGQUIT, SIG_IGN);
	(sgnl = rl_getc_function);
	rl_getc_function = getc;
	if (!pid)
		back_d_red_child2(cmd, fd, strcount(cmd));
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
	(rl_getc_function = sgnl);
	signal(SIGINT, cmd_c_fork);
}

int	back_d_red21(t_cmd *cmd_o)
{
	t_cmd	*cmd;

	cmd = cmd_o;
	if (cmd->back_d_red)
	{
		if (cmd->red_words[0][0] == '\0')
		{
			g_status_error = 258;
			printf("syntax error near unexpected token \n");
			return (130);
		}
	}
	while (cmd)
	{
		if (cmd->back_d_red)
			back_d_red2(cmd);
		if (g_status_error == 130)
			return (130);
		cmd = cmd->next;
	}
	return (0);
}
