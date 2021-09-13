#include "push_swap.h"

int	found_mid_and_more(t_struct *head, t_main *base)
{
	while (head != NULL)
	{
		if (head->order >= base->mid)
			return (1);
		else
			head = head->next;
	}
	return (0);
}

int	found_next_start(t_struct *head_a, t_main *base)
{
	int	length;

	length = 1;
	while (head_a != NULL)
	{
		if ((head_a)->order == base->next)
			return (length);
		else if ((head_a)->order != base->next)
		{
			(head_a) = (head_a)->next;
			length++;
		}
	}
	return (0);
}

int	found_next_end(t_struct *head_a, t_main *base)
{
	int	i;
	int	count;
	int	size;

	i = 0;
	count = 0;
	size = ft_lstsize(head_a);
	while (head_a != NULL)
	{
		if ((head_a)->order == base->next)
		{
			(head_a) = (head_a)->next;
			i++;
			count = i;
		}
		else if ((head_a)->order != base->next)
		{
			(head_a) = (head_a)->next;
			i++;
		}
	}
	count = (size - count) + 1;
	return (count);
}
