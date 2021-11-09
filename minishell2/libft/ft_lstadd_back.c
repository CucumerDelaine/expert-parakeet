#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*low;

	if (lst && new)
	{
		low = *lst;
		if (low == NULL)
			(*lst) = new;
		else
		{
			while (low->next != NULL)
				low = low->next;
			low->next = new;
		}
	}
}
