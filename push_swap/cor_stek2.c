#include "push_swap.h"

int	found_mid_and_less_but(t_struct *head, t_main *base)
{
	while (head != NULL)
	{
		if (head->order <= base->mid && head->order >= base->next)
			return (1);
		else
			head = head->next;
	}
	return (0);
}

int	found_best_way_start_low_but(t_struct *some_stek, t_main *base)
{
	int	i;
	int	size;

	i = 1;
	size = ft_lstsize(some_stek);
	while (i <= size)
	{
		if (some_stek->order <= base->mid && some_stek->order >= base->next)
			return (i);
		else if (some_stek->order > base->mid)
		{
			some_stek = some_stek->next;
			i++;
		}
	}
	return (i);
}

int	found_best_way_end_low_but(t_struct *some_stek, t_main *base)
{
	int	i;
	int	count;
	int	size;

	i = 0;
	count = 0;
	size = ft_lstsize(some_stek);
	while (some_stek->order != 1)
	{
		if (some_stek->order <= base->mid && some_stek->order >= base->next)
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
	return (i);
}

void	head_more_base_mid(t_struct **head_a, t_struct **head_b, t_main *base)
{
	if (found_best_way_start_low_but((*head_a), base) <= \
	found_best_way_end_low_but((*head_a), base) && \
	found_mid_and_less_but(*head_a, base))
	{
		if (found_best_way_start_low_but((*head_a), base) == 2)
			sa(head_a);
		else if ((*head_a)->order <= base->mid && \
		(*head_a)->order >= base->next)
			pb(head_a, head_b);
		else if ((*head_a)->order > base->mid && \
		(*head_a) != NULL)
			ra(head_a);
	}
	else if (found_best_way_start_low_but((*head_a), base) > \
	found_best_way_end_low_but((*head_a), base) \
	&& found_mid_and_less_but((*head_a), base))
	{
		rra(head_a);
		if ((*head_a)->order <= base->mid \
		&& (*head_a)->order >= base->next)
			pb(head_a, head_b);
	}
}

void	second_corr_stek_a(t_struct **head_a, t_struct **head_b, t_main *base)
{
	while (found_mid_and_less_but(*head_a, base))
	{
		if ((*head_a)->order == base->next && \
		(ft_lstlast(*head_a)->order) == (base->next - 1))
		{
			ra(head_a);
			base->next++;
		}
		else if ((*head_a)->order <= base->mid \
		&& (*head_a)->order >= base->next)
			pb(head_a, head_b);
		else if ((*head_a)->order > base->mid && (*head_a) != NULL)
			head_more_base_mid(head_a, head_b, base);
	}
}
