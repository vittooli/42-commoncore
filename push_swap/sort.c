/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:25:55 by volivier          #+#    #+#             */
/*   Updated: 2024/05/24 13:21:25 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_list **stack)
{
	if (find_max_three(stack) == 1)
		ra(stack);
	if (find_max_three(stack) == 2)
		rra(stack);
	if (find_max_three(stack) == 3 && is_sorted_a(*stack) == 1)
		sa(stack);
	return (0);
}

void	push_min(t_list **stack, t_list **b)
{
	t_list	*head;
	int		index;

	head = *stack;
	while (head)
	{
		if (head == return_min(*stack))
			index = get_index(*stack, head);
		head = head->next;
	}
	if (index <= 3)
	{
		while (*stack != return_min(*stack))
			ra(stack);
		pb(stack, b);
	}
	else
	{
		while (*stack != return_min(*stack))
			rra(stack);
		pb(stack, b);
	}
}

void	sort_else(t_list **stack, t_list **b)
{
	if (lst_size(*stack) == 4)
		push_min(stack, b);
	else
	{
		push_min(stack, b);
		push_min(stack, b);
	}
	sort_three(stack);
	pa(b, stack);
	pa(b, stack);
}
