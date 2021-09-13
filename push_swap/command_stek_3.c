#include "push_swap.h"

void	rrr(t_struct **head_stek_a, t_struct **head_stek_b)
{
	t_struct	*tmp;
	t_struct	*temp;

	tmp = NULL;
	temp = NULL;
	tmp = ft_lstlast(*head_stek_a);
	ft_lstlast_size(*head_stek_a, (ft_lstsize(*head_stek_a) - 1))->next = NULL;
	tmp->next = (*head_stek_a);
	(*head_stek_a) = tmp;
	temp = ft_lstlast(*head_stek_b);
	ft_lstlast_size(*head_stek_b, (ft_lstsize(*head_stek_b) - 1))->next = NULL;
	temp->next = (*head_stek_b);
	(*head_stek_b) = temp;
	ft_putstr("rrr");
}
