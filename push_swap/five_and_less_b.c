#include "push_swap.h"

void	three_elem_b(t_struct **head_b)
{
	if (ft_lstlast(*head_b)->order > (*head_b)->order \
	&& ft_lstlast(*head_b)->order \
	> (*head_b)->next->order && (*head_b)->order > (*head_b)->next->order)
		sb(head_b);
	else if ((*head_b)->order > (*head_b)->next->order && (*head_b)->order > \
	ft_lstlast(*head_b)->order \
	&& (*head_b)->next->order > ft_lstlast(*head_b)->order)
		zamena3(head_b);
	else if ((*head_b)->order > (*head_b)->next->order && (*head_b)->order > \
	ft_lstlast(*head_b)->order && ft_lstlast(*head_b)->order > \
	(*head_b)->next->order)
		rb(head_b);
	else if ((*head_b)->next->order > (*head_b)->order \
	&& (*head_b)->next->order > \
	ft_lstlast(*head_b)->order && ft_lstlast(*head_b)->order > (*head_b)->order)
		zamena4(head_b);
	else if ((*head_b)->next->order > (*head_b)->order \
	&& (*head_b)->next->order > ft_lstlast(*head_b)->order \
	&& (*head_b)->order > ft_lstlast(*head_b)->order)
		rrb(head_b);
}

static void	four_elem_b(t_struct **head_b, t_struct **head_a, t_main *base)
{
	while ((*head_b)->order != base->next)
		rb(head_b);
	pa(head_b, head_a, *base);
	three_elem_b(head_b);
	pb(head_a, head_b);
}

int	five_and_less_b(t_struct **head_b, t_struct **head_a, t_main *base)
{
	if (ft_lstsize(*head_b) <= 5)
	{
		if (ft_lstsize(*head_b) == 2)
		{
			if ((*head_b)->order > (*head_b)->next->order)
				sb(head_b);
		}
		else if (ft_lstsize(*head_b) == 3)
			three_elem_b(head_b);
		else if (ft_lstsize(*head_b) == 4 )
			four_elem_b(head_b, head_a, base);
		else if (ft_lstsize(*head_b) == 5)
		{
			pa(head_b, head_a, *base);
			four_elem_b(head_b, head_a, base);
			pb(head_a, head_b);
		}
		return (1);
	}
	else
		return (0);
}
