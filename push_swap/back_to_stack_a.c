#include "push_swap.h"

void	do_way_from_start(t_struct **head_a, t_struct **head_b, t_main *base)
{
	if (found_best_way_start_big((*head_b), base) <= \
	found_best_way_end_big((*head_b), base) && \
	found_mid_and_more(*head_b, base))
	{
		if (found_best_way_start_big((*head_b), base) == 2)
			sb(head_b);
		else if ((*head_b)->order < base->mid && (*head_b) != NULL)
			rb(head_b);
		else if ((*head_b)->order >= base->mid)
			pa(head_b, head_a, *base);
	}
	else if (found_best_way_start_big((*head_b), base) > \
	found_best_way_end_big((*head_b), base) && \
	found_mid_and_more(*head_b, base))
	{
		rrb(head_b);
		if ((*head_b)->order >= base->mid)
			pa(head_b, head_a, *base);
	}
}

void	back_to_stek_a(t_struct **head_a, t_struct **head_b, t_main *base)
{
	while (found_mid_and_more(*head_b, base))
	{
		if ((*head_b)->order == base->next)
		{
			pa(head_b, head_a, *base);
			ra(head_a);
			base->next++;
		}
		else if ((*head_b)->order >= base->mid)
			pa(head_b, head_a, *base);
		else if ((*head_b)->order < base->mid && (*head_b) != NULL)
			do_way_from_start(head_a, head_b, base);
	}
}

void	st_more_end(t_struct **head_a, t_struct **head_b, t_main *base)
{
	while (ft_lstlast(*head_b)->order != base->next)
		rrb(head_b);
	rrb(head_b);
	pa(head_b, head_a, *base);
	ra(head_a);
	base->next++;
}

void	st_less_end(t_struct **head_a, t_struct **head_b, t_main *base)
{
	while ((*head_b)->order != base->next)
		rb(head_b);
	pa(head_b, head_a, *base);
	ra(head_a);
	base->next++;
}

void	sort_at_stek_b(t_struct **head_a, t_struct **head_b, t_main *base)
{
	if ((*head_b)->order == base->next)
	{
		pa(head_b, head_a, *base);
		ra(head_a);
		base->next++;
	}
	else if ((*head_b)->next->order == base->next)
	{
		sb(head_b);
		pa(head_b, head_a, *base);
		ra(head_a);
		base->next++;
	}
	else if (found_next_start(*head_b, base) <= found_next_end(*head_b, base))
		st_less_end(head_a, head_b, base);
	else if ((found_next_start(*head_b, base) > found_next_end(*head_b, base)))
		st_more_end(head_a, head_b, base);
}
