/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:46:04 by volivier          #+#    #+#             */
/*   Updated: 2024/05/24 13:20:39 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize(t_list **stack, int index)
{
	if (index < lst_size(*stack) / 2)
		rb(stack);
	else
		rrb(stack);
}

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return (0);
	head = *stack;
	last = ft_lstlast(*stack);
	*stack = head->next;
	last->next = head;
	head->next = NULL;
	return (1);
}

int	ra(t_list **stack)
{
	if (rotate(stack) == 0)
		return (0);
	ft_printf("ra\n");
	return (1);
}

int	rb(t_list **stack)
{
	if (rotate(stack) == 0)
		return (0);
	ft_printf("rb\n");
	return (1);
}

int	rr(t_list **stack_a, t_list	**stack_b)
{
	if (rotate(stack_a) == 0 || rotate(stack_b) == 0)
		return (0);
	ft_printf("rr\n");
	return (1);
}
