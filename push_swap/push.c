#include "push_swap.h"

int	push(t_list **src, t_list **dest)
{
	t_list	*tmp;
	//t_list	*node;
	
	if (*src == NULL)
		return (0);
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
	return (1);
}
int	pa(t_list **stack_b, t_list **stack_a)
{
	if (push(stack_b, stack_a) == 0)
		return (0);
	printf("pa\n");
	return (1);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == 0)
		return (0);
	printf("pb\n");
	return (1);
}