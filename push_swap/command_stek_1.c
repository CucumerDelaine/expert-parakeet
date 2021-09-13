#include "push_swap.h"

void	sa(t_struct **head_stek_a)
{
	t_struct	*tmp;

	tmp = NULL;
	tmp = (*head_stek_a);
	(*head_stek_a) = (*head_stek_a)->next;
	tmp->next = tmp->next->next;
	(*head_stek_a)->next = tmp;
	ft_putstr("sa");
}

void	sb(t_struct **head_stek_b)
{
	t_struct	*tmp;

	tmp = NULL;
	tmp = (*head_stek_b);
	(*head_stek_b) = (*head_stek_b)->next;
	tmp->next = tmp->next->next;
	(*head_stek_b)->next = tmp;
	ft_putstr("sb");
}

void	ss(t_struct **head_stek_a, t_struct **head_stek_b)
{
	t_struct	*tmp;
	t_struct	*temp;

	temp = NULL;
	tmp = NULL;
	tmp = (*head_stek_a);
	(*head_stek_a) = (*head_stek_a)->next;
	tmp->next = tmp->next->next;
	(*head_stek_a)->next = tmp;
	temp = (*head_stek_b);
	(*head_stek_b) = (*head_stek_b)->next;
	temp->next = temp->next->next;
	(*head_stek_b)->next = temp;
	ft_putstr("ss");
}

void	pb(t_struct **head_stek_a, t_struct **head_stek_b)
{
	t_struct	*tmp;

	tmp = NULL;
	tmp = (*head_stek_a);
	(*head_stek_a) = (*head_stek_a)->next;
	tmp->next = (*head_stek_b);
	(*head_stek_b) = tmp;
	ft_putstr("pb");
}

void	pa(t_struct **head_stek_b, t_struct **head_stek_a, t_main base)
{
	t_struct	*tmp;

	tmp = NULL;
	tmp = (*head_stek_b);
	(*head_stek_b)->flag = base.flag;
	(*head_stek_b) = (*head_stek_b)->next;
	tmp->next = (*head_stek_a);
	(*head_stek_a) = tmp;
	ft_putstr("pa");
}
