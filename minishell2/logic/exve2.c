/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exve2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <erichell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:03:43 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/12 15:05:56 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_count(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char	**get_flag(t_cmd *cmd)
{
	int		i;
	int		j;
	char	**flags;

	init_count(&i, &j);
	while (cmd->flags[i])
		i++;
	while (cmd->argum[j++])
		i++;
	flags = (char **)malloc(sizeof(char *) * (i + 2));
	flags[i + 1] = NULL;
	init_count(&i, &j);
	flags[0] = ft_strdup(cmd->cmd);
	while (cmd->flags[i])
	{
		flags[i + 1] = ft_strdup(cmd->flags[i]);
		i++;
	}
	while (cmd->argum[j])
	{
		flags[i + 1] = ft_strdup(cmd->argum[j]);
		i++;
		j++;
	}
	return (flags);
}

void	free_memory(char **str1, char **str2)
{
	int	i;

	i = 0;
	while (str1[i])
		free(str1[i++]);
	i = 0;
	while (str2[i])
		free(str2[i++]);
	free(str1);
	free(str2);
}

char	*print_exit(t_pipex *str, int i)
{
	ft_putstr_fd(str->comand[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	if (i)
		free_memory(str->strings_way, str->comand);
	exit (127);
}

char	*get_addres(char **oenvp, char *cmd_string)
{
	t_pipex	str;

	str.i = 0;
	while (ft_strncmp(oenvp[str.i], "PATH=", 5))
		if (str.i++ == 1000)
			print_exit(&str, 0);
	str.strings_way = ft_split(oenvp[str.i] + 5, ':');
	str.comand = ft_split(cmd_string, ' ');
	str.i = 0;
	while (str.strings_way[str.i])
	{
		str.addres = ft_strjoin(str.strings_way[str.i], "/");
		str.addres_full = ft_strjoin(str.addres, str.comand[0]);
		free(str.addres);
		if (access(str.addres_full, F_OK) == 0)
		{
			free_memory(str.strings_way, str.comand);
			return (str.addres_full);
		}
		free(str.addres_full);
		str.i++;
	}
	return (print_exit(&str, 1));
}
