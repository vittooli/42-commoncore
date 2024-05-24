/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:56:36 by volivier          #+#    #+#             */
/*   Updated: 2024/05/24 13:59:17 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_list(t_list *stack)
{
	t_list	*head;

	head = stack;
	while (head)
	{
		printf("%d\n", head->content);
		head = head->next;
	}
	return (0);
}

t_move	find_move(t_list *a, t_list *b, t_move *move)
{
	t_list	*head;
	t_move	good_move;

	good_move.cost = 10000000;
	head = a;
	while (head)
	{
		move->target_a = head;
		move->target_b = find_target(move->target_a->content, b);
		find_cost(a, b, move);
		if (good_move.cost > move->cost)
		{
			good_move.cost = move->cost;
			good_move.cases = move->cases;
			good_move.target_a = move->target_a;
			good_move.target_b = move->target_b;
		}
		head = head->next;
	}
	return (good_move);
}

void	big_sort(t_list **a, t_list **b, t_move move)
{
	int	final_index;

	pb(a, b);
	pb(a, b);
	while (*a)
	{
		move = find_move(*a, *b, &move);
		move_stacks(a, b, &move);
	}
	final_index = get_index(*b, (return_max(*b)));
	while (*b != return_max(*b))
		optimize(b, final_index);
	while (*b)
		pa(b, a);
}

int	sort(t_list **a, t_list **b, t_move move)
{
	if (lst_size(*a) < 2)
		return (1);
	else if (lst_size(*a) == 2)
		sa(a);
	else if (lst_size(*a) == 3)
		sort_three(a);
	else if (lst_size(*a) == 4 || lst_size(*a) == 5)
		sort_else(a, b);
	else
		big_sort(a, b, move);
	return (0);
}
