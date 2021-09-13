#include "push_swap.h"

void	ra(t_struct **head_stek_a)
{
	t_struct	*tmp;

	tmp = NULL;
	tmp = (*head_stek_a);
	(*head_stek_a) = (*head_stek_a)->next;
	ft_lstlast(*head_stek_a)->next = tmp;
	tmp->next = NULL;
	ft_putstr("ra");
}

void	rb(t_struct **head_stek_b)
{
	t_struct	*tmp;

	tmp = NULL;
	tmp = (*head_stek_b);
	(*head_stek_b) = (*head_stek_b)->next;
	ft_lstlast(*head_stek_b)->next = tmp;
	tmp->next = NULL;
	ft_putstr("rb");
}

void	rr(t_struct **head_stek_a, t_struct **head_stek_b)
{
	t_struct	*tmp;
	t_struct	*temp;

	temp = NULL;
	tmp = NULL;
	tmp = (*head_stek_a);
	(*head_stek_a) = (*head_stek_a)->next;
	ft_lstlast(*head_stek_a)->next = tmp;
	tmp->next = NULL;
	temp = (*head_stek_b);
	(*head_stek_b) = (*head_stek_b)->next;
	ft_lstlast(*head_stek_b)->next = temp;
	temp->next = NULL;
	ft_putstr("rr");
}

void	rra(t_struct **head_stek_a)
{
	t_struct	*tmp;

	tmp = NULL;
	tmp = ft_lstlast(*head_stek_a);
	ft_lstlast_size(*head_stek_a, (ft_lstsize(*head_stek_a) - 1))->next = NULL;
	tmp->next = (*head_stek_a);
	(*head_stek_a) = tmp;
	ft_putstr("rra");
}

void	rrb(t_struct **head_stek_b)
{
	t_struct	*tmp;

	tmp = NULL;
	tmp = ft_lstlast(*head_stek_b);
	ft_lstlast_size(*head_stek_b, (ft_lstsize(*head_stek_b) - 1))->next = NULL;
	tmp->next = (*head_stek_b);
	(*head_stek_b) = tmp;
	ft_putstr("rrb");
}
