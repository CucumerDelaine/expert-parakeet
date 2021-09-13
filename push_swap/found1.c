#include "push_swap.h"

int	found_best_way_end_low(t_struct *some_stek, t_main *base)
{
	int	i;
	int	count;
	int	size;

	i = 0;
	count = 0;
	size = ft_lstsize(some_stek);
	while (i < size)
	{
		if (some_stek->order <= base->mid)
		{
			some_stek = some_stek->next;
			i++;
			count = i;
		}
		else if (some_stek->order > base->mid)
		{
			some_stek = some_stek->next;
			i++;
		}
	}
	count = (size - count) + 1;
	return (count);
}

int	found_best_way_start_low(t_struct *some_stek, t_main *base)
{
	int	i;
	int	size;

	i = 1;
	size = ft_lstsize(some_stek);
	while (i <= size)
	{
		if (some_stek->order <= base->mid)
			return (i);
		else if (some_stek->order > base->mid)
		{
			some_stek = some_stek->next;
			i++;
		}
	}
	return (i);
}

int	found_best_way_start_big(t_struct *some_stek, t_main *base)
{
	int	i;
	int	size;

	i = 1;
	size = ft_lstsize(some_stek);
	while (i <= size)
	{
		if (some_stek->order < base->mid)
		{
			return (i);
		}
		else if (some_stek->order < base->mid)
		{
			some_stek = some_stek->next;
			i++;
		}
	}
	return (i);
}

int	found_best_way_end_big(t_struct *some_stek, t_main *base)
{
	int	i;
	int	count;
	int	size;

	i = 0;
	count = 0;
	size = ft_lstsize(some_stek);
	while (i < size)
	{
		if (some_stek->order >= base->mid)
		{
			some_stek = some_stek->next;
			i++;
			count = i;
		}
		else if (some_stek->order < base->mid)
		{
			some_stek = some_stek->next;
			i++;
		}
	}
	count = (size - count) + 1;
	return (count);
}

int	found_mid_and_less(t_struct *head, t_main *base)
{
	while (head != NULL)
	{
		if (head->order <= base->mid)
			return (1);
		else
			head = head->next;
	}
	return (0);
}
