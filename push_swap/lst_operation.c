#include "push_swap.h"

void	ft_lstadd_back(t_struct **lst, t_struct *new)
{
	t_struct	*low;

	if (lst && new)
	{
		low = *lst;
		if (low == NULL)
			(*lst) = new;
		else
		{
			while (low->next != NULL)
				low = low->next;
			low->next = new;
		}
	}
}

t_struct	*ft_lstlast_size(t_struct *lst, int size)
{
	if (lst)
	{
		while (size > 1)
		{
			lst = lst->next;
			size--;
		}
	}
	return (lst);
}

t_struct	*ft_lstlast(t_struct *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

void	new_list(t_struct **head, int order, int value)
{
	t_struct	*list;

	list = (t_struct *)malloc(sizeof(t_struct));
	if (!list)
		return ;
	list->order = order;
	list->value = value;
	list->next = NULL;
	ft_lstadd_back(head, list);
}

int	ft_lstsize(t_struct *lst)
{
	int		len;

	len = 0;
	if (lst)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
			len++;
		}
		if (lst->next == NULL)
			len++;
	}
	return (len);
}
