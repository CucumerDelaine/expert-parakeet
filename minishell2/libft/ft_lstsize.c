#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*lok;

	len = 0;
	lok = lst;
	if (lst)
	{
		while (lok->next != NULL)
		{
			lok = lok->next;
			len++;
		}
		if (lok->next == NULL)
			len++;
	}
	return (len);
}
