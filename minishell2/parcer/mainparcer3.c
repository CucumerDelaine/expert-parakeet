/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainparcer3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erichell <erichell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:39:16 by erichell          #+#    #+#             */
/*   Updated: 2021/11/18 12:39:51 by erichell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_min_exit(void)
{
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	write(1, "exit\n", 5);
	exit(g_status_error);
}

int	print_prepars_invalid(char *str)
{
	char	*freez;

	if (ft_check_only_pipe(str))
	{
		freez = str;
		str = ft_strdup("|");
		ft_freez(freez);
	}
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" : invalid command\n", 2);
	free(str);
	str = NULL;
	return (0);
}

int	preparser2(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == '\'')
			return (0);
		if (str[*i + 1] == '\0' && str[*i] != '\'')
			return (1);
		(*i)++;
	}
	return (0);
}

int	preparser3(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == '\"')
			return (0);
		if (str[*i + 1] == '\0' && str[*i] != '\"')
			return (1);
		(*i)++;
	}
	return (0);
}

int	ft_free_iter(t_iter **iter)
{
	if ((*iter) != NULL)
	{
		if ((*iter)->res != NULL)
			free((*iter)->res);
		free(*iter);
		*iter = NULL;
	}
	return (1);
}
