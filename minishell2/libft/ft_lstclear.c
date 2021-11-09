#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*low;
	t_list	*step;

	low = *lst;
	if (lst && (*lst) && del)
	{
		while (low)
		{
			step = low->next;
			if (del)
				del(low->content);
			free(low);
			low = step;
		}
	}
	*lst = NULL;
}
