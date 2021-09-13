#include "push_swap.h"

void	three_elem_a(t_struct **head_a)
{
	if (ft_lstlast(*head_a)->order > (*head_a)->order \
	&& ft_lstlast(*head_a)->order > (*head_a)->next->order
		&& (*head_a)->order > (*head_a)->next->order)
		sa(head_a);
	else if ((*head_a)->order > (*head_a)->next->order && (*head_a)->order > \
	ft_lstlast (*head_a)->order && (*head_a)->next->order \
	> ft_lstlast(*head_a)->order)
		zamena(head_a);
	else if ((*head_a)->order > (*head_a)->next->order && (*head_a)->order > \
	ft_lstlast(*head_a)->order && ft_lstlast(*head_a)->order > \
	(*head_a)->next->order)
		ra(head_a);
	else if ((*head_a)->next->order > (*head_a)->order
		&& (*head_a)->next->order > \
	ft_lstlast(*head_a)->order && ft_lstlast(*head_a)->order > (*head_a)->order)
		zamena2(head_a);
	else if ((*head_a)->next->order > (*head_a)->order \
	&& (*head_a)->next->order > \
	ft_lstlast(*head_a)->order && (*head_a)->order > ft_lstlast(*head_a)->order)
		rra(head_a);
}

static void	four_elem_a(t_struct **head_a, t_struct **head_b, t_main *base)
{
	while ((*head_a)->order != base->next)
		ra(head_a);
	pb(head_a, head_b);
	three_elem_a(head_a);
	pa(head_b, head_a, *base);
}

int	five_or_less_arg(t_struct **head_a, t_struct **head_b, t_main *base)
{
	if (ft_lstsize(*head_a) <= 5)
	{
		if (ft_lstsize(*head_a) == 2)
		{
			if ((*head_a)->order > (*head_a)->next->order)
				sa(head_a);
		}
		else if (ft_lstsize(*head_a) == 3)
			three_elem_a(head_a);
		else if (ft_lstsize(*head_a) == 4)
			four_elem_a(head_a, head_b, base);
		else if (ft_lstsize(*head_a) == 5)
		{
			while ((*head_a)->order != base->next)
				ra(head_a);
			base->next++;
			pb(head_a, head_b);
			four_elem_a(head_a, head_b, base);
			pa(head_b, head_a, *base);
		}
		return (1);
	}
	else
		return (0);
}

void	first_corr_stack(t_struct **head_a, t_struct **head_b, t_main *base)
{
	while (found_mid_and_less(*head_a, base))
	{
		if ((*head_a)->order <= base->mid)
			pb(head_a, head_b);
		else if ((*head_a)->order > base->mid && (*head_a) != NULL)
		{
			if (found_best_way_start_low((*head_a), base) <= \
			found_best_way_end_low((*head_a), base) && \
			found_mid_and_less(*head_a, base))
			{
				while ((*head_a)->order > base->mid && (*head_a) != NULL)
					ra(head_a);
				if ((*head_a)->order <= base->mid)
					pb(head_a, head_b);
			}
			else if (found_best_way_start_low((*head_a), base) > \
			found_best_way_end_low((*head_a), base) && \
			found_mid_and_less(*head_a, base))
			{
				rra(head_a);
				if ((*head_a)->order <= base->mid)
					pb(head_a, head_b);
			}
		}
	}
}

int	step_one_two(t_struct **head_a, t_struct **head_b, t_main *base, int i)
{
	base->next = 1;
	base->max = i;
	base->mid = (base->max / 2) + base->next;
	base->flag = 0;
	if (five_or_less_arg(head_a, head_b, base))
		return (0);
	first_corr_stack(head_a, head_b, base);
	while (*head_b != NULL)
	{
		base->max = (base)->mid;
		base->mid = (((base)->max - (base)->next) / 2) + (base)->next;
		base->flag++;
		back_to_stek_a(head_a, head_b, base);
	}
	return (1);
}
