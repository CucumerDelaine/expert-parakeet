#include "minishell.h"

t_cmd	*ft_lstnew_cmd(char *command)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->flags = (char**)malloc(sizeof(char *) * 10);
	new->argum = (char**)malloc(sizeof(char *) * 30);
	new->arg_num = 0;
	new->flag_num = 0;
	new->fd_in = 0;
	new->fd_out = 1;
	new->next = NULL;
	new->cmd = command;

	return (new);
}

void ft_lstadd_flags(t_cmd **cmd, char *flag)
{
	(*cmd)->flags[(*cmd)->flag_num] = ft_strdup(flag);
	(*cmd)->flag_num++;
}

void ft_lstadd_argum(t_cmd **cmd, char *argm)
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
