
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	ret;
	t_list	*temp;

	if (lst == NULL)
		return (0);
	ret = 0;
	temp = lst;
	while (temp->next)
	{
		temp = temp->next;
		ret++;
	}
	return (ret);
}