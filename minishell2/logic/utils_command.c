/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelaine <cdelaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:43:39 by cdelaine          #+#    #+#             */
/*   Updated: 2021/11/18 12:43:53 by cdelaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	new_null(t_cmd	*new)
{
	new->arg_num = 0;
	new->flag_num = 0;
	new->fd_in = 0;
	new->fd_out = 1;
	new->next = NULL;
	new->back_d_red = 0;
	new->fd_red = 0;
	new->word_num = 0;
}

t_cmd	*ft_lstnew_cmd(char *command)
{
	t_cmd	*new;
	int		i;

	i = 0;
	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	if (command != NULL)
		new->cmd = ft_strdup(command);
	else
		new->cmd = NULL;
	new->flags = (char **)malloc(sizeof(char *) * 10);
	new->argum = (char **)malloc(sizeof(char *) * 10);
	new->red_words = (char **)malloc(sizeof(char *) * 10);
	while (i < 10)
	{
		new->flags[i] = NULL;
		new->argum[i] = NULL;
		new->red_words[i] = NULL;
		i++;
	}
	new_null(new);
	return (new);
}

void	ft_lstadd_flags(t_cmd **cmd, char *flag)
{
	(*cmd)->flags[(*cmd)->flag_num] = ft_strdup(flag);
	(*cmd)->flag_num++;
}

void	ft_lstadd_argum(t_cmd **cmd, char *argm)
{
	(*cmd)->argum[(*cmd)->arg_num] = ft_strdup(argm);
	(*cmd)->arg_num++;
}

void	ft_lstadd_back_cmd(t_cmd **lst, t_cmd *new)
{
	t_cmd	*low;

	if (lst && new)
	{
		low = *lst;
		if (low == NULL)
		{
			(*lst) = new;
		}
		else
		{
			while (low->next != NULL)
				low = low->next;
			low->next = new;
		}
	}
}
