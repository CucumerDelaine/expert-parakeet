/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exve.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:02:57 by cdelaine          #+#    #+#             */
/*   Updated: 2021/10/07 16:02:59 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	path(char *name_programm)
{
	int	i;

	i = 0;
	while (name_programm[i])
	{
		if (name_programm[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

void	call_execve_proc(t_cmd *cmd, t_env *env, char **oenv)
{
	char	*name_program;
	char	**flags;

	if (path(cmd->cmd))
		name_program = ft_strdup(cmd->cmd);
	else
		name_program = get_addres(oenv, env, cmd->cmd);
	flags = get_flag(cmd);
	check_minishel(name_program, oenv, cmd);
	if (cmd->back_d_red)
		back_d_red(cmd);
	execve(name_program, flags, oenv);
	perror(name_program);
	exit (127);
}

int	comand_exve(t_cmd *cmd, t_env *env, char **oenv)
{
	int	pid;
	int	err;
	int	d;

	err = 0;
	if (!path(cmd->cmd) && check_path(cmd, env))
		return (g_status_error);
	d = dup(0);
	if (cmd->fd_in != 0)
		dup2(cmd->fd_in, STDIN_FILENO);
	pid = fork();
	if (pid < 0)
		exit (1);
	if (pid == 0)
	{
		if (cmd->fd_out != 1)
			dup2(cmd->fd_out, STDOUT_FILENO);
		call_execve_proc(cmd, env, oenv);
	}
	waitpid(pid, &err, WUNTRACED | WCONTINUED);
	g_status_error = WEXITSTATUS(err);
	norma2(cmd, d);
	return (g_status_error);
}

void	norma2(t_cmd *cmd, int d)
{
	if (cmd->fd_in != 0)
	{
		close(cmd->fd_in);
		dup2(d, STDIN_FILENO);
	}
	if (cmd->fd_out != 1)
		close(cmd->fd_out);
}

char *ustal(char *str)
{
	int i;
	int j;
	char *str2;

	i = 0;
	j = ft_strlen(str);
	str2 = malloc(sizeof (char *) * j + 6);
	while (i < j + 1)
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

int strcount(t_cmd *cmd)
{
	int i;

	i = 0;
	while (cmd->red_words[i])
		i++;
	return (i);
}

void init_str(char **str2)
{
	int i;

	i = 0;
	str2 = (char **)malloc(sizeof(char *) * 100);
	while (i < 100)
		str2[i++] = NULL;
}

void term_str(char **str2)
{
	int i;

	i = 0;
	while (str2[i])
	{
		if (str2[i])
			free(str2[i]);
		i++;
	}
	free(str2);
}

void back_d_red(t_cmd *cmd)
{
	char *str;
	int i;
	int count;
	int j;
	char **str2;

	i = 0;
	j = 0;
	// init_str(str2);
	count = strcount(cmd);
	printf("count = %d\n", count);
	while (i < count)
	{
		if (i < count)
			str = readline("> ");
		if (i < count)
		{
			if (!ft_strncmp_nr(str, cmd->red_words[i], ft_strlen(cmd->red_words[i])))
				i++;
			// else if (i == count - 1 && !ft_strncmp_nr("cat", cmd->cmd, 3) && cmd->argum[0] == NULL)
			// {
			// 	write(1, "ZAHEL\n", 6);
			// 	// str2[j] = ustal(str);
			// 	j++;
			// }
		}
		// else
		// 	break ;
		printf("i = %d\n", i);
		printf("CMD = %s\n", cmd->cmd);
		printf("str = %s\n", str);
		free(str);
	}
	// i = 0;
	// write(1, "1\n", 2);
	// while (str2[i])
	// 	printf("%s\n", str2[i++]);
	// term_str(str2);
}
