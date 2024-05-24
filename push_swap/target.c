/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:46:14 by volivier          #+#    #+#             */
/*   Updated: 2024/05/24 13:25:11 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_target(int value, t_list *b)
{
	t_list	*head;
	t_list	*target;

	head = b;
	target = return_min(head);
	while (head)
	{
		if (value > head->content)
			if (head->content > target->content)
				target = head;
		head = head->next;
	}
	if (target->content < value)
		return (target);
	return (return_max(b));
}

int	get_index(t_list *stack, t_list	*target)
{
	int	index;

	index = 1;
	while (stack)
	{
		if (stack == target)
			return (index);
		index++;
		stack = stack->next;
	}
	return (index);
}

void	find_cost(t_list *a, t_list *b, t_move *move)
{
	int	index_a;
	int	index_b;

	index_a = get_index(a, move->target_a);
	index_b = get_index(b, move->target_b);
	if (index_a <= lst_size(a) / 2 && index_b <= lst_size(b) / 2)
	{
		move->cost = ft_max(index_a, index_b);
		move->cases = 1;
	}
	else if (index_a <= lst_size(a) / 2 && index_b > lst_size(b) / 2)
	{
		move->cost = index_a + lst_size(b) - index_b;
		move->cases = 2;
	}
	else if (index_a > lst_size(a) / 2 && index_b <= lst_size(b) / 2)
	{
		move->cost = index_b + lst_size(a) - index_a;
		move->cases = 3;
	}
	else
	{
		move->cost = ft_max(lst_size(a) - index_a, lst_size(b) - index_b);
		move->cases = 4;
	}
}
