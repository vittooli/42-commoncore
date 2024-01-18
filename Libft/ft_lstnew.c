#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}