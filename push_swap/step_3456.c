#include "push_swap.h"

void	step_three(t_struct **head_a, t_struct **head_b, t_main *base)
{
	while ((*head_a)->flag > 0)
	{
		if ((*head_a)->flag != base->flag)
			base->flag--;
		while ((*head_a)->flag == base->flag)
		{
			if ((*head_a)->next->order == base->next)
			{
				sa(head_a);
				ra(head_a);
				base->next++;
			}
			else if ((*head_a)->order == base->next)
			{
				ra(head_a);
				base->next++;
			}
			else if ((*head_a)->flag == base->flag)
				pb(head_a, head_b);
			if (found_next_start(*head_b, base))
				sort_at_stek_b(head_a, head_b, base);
		}
	}
}

void	step_four(t_struct **head_a, t_struct **head_b, t_main *base, int i)
{
	base->mid = base->next;
	base->max = i;
	base->mid = ((base->max - base->next) / 2) + base->next;
	base->flag = 0;
	second_corr_stek_a(head_a, head_b, base);
}

void	step_five(t_struct **head_a, t_struct **head_b, t_main *base)
{
	if (found_next_start(*head_b, base))
	{
		while ((*head_b)->order != base->next)
			rrr(head_a, head_b);
	}
	while ((ft_lstlast(*head_a))->order != (base->next - 1))
		rra(head_a);
}

void	step_six(t_struct **head_a, t_struct **head_b, t_main *base, int i)
{
	while ((*head_a)->order != 1 && ft_lstlast(*head_a)->order != base->max)
	{
		while (*head_b != NULL)
		{
			base->max = (base)->mid;
			base->mid = (((base)->max - (base)->next) / 2) + (base)->next;
			base->flag++;
			back_to_stek_a(head_a, head_b, base);
		}
		step_three(head_a, head_b, base);
		step_four(head_a, head_b, base, i);
		step_five(head_a, head_b, base);
	}
}
