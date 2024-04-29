#include "push_swap.h"

int	swap(t_list **stack)
{
	int		tmp;
	if (lst_size(*stack) < 2)
		return (0);
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	return (1);
}

int	sa(t_list **stack)
{
	if (swap(stack) == 0)
		return (0);
	ft_printf("sa\n");
	return (1);
}

int	sb(t_list **stack)
{
	if (swap(stack) == 0)
		return (0);
	ft_printf("sb\n");
	return (1);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a) == 0 || swap(stack_b) == 0)
		return (0);
	ft_printf("ss\n");
	return (1);
}
