#include "libft-h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if(lst == NULL || del == NULL)
		return ;
	tmp = *lst;
	while (*lst->next)
		tmp
}