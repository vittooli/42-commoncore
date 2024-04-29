/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:56:26 by volivier          #+#    #+#             */
/*   Updated: 2024/04/29 21:02:36 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;

	if (lst_size(*stack) < 2)
		return (0);
	head = *stack;
	last = ft_lstlast(*stack);
	while (head)
	{
		if (head->next->next == NULL) //se è il penultimo nodo
		{
			head->next = NULL; //diventa l'ultimo nodo
			break ;
		}
		head = head->next;
	}
	last->next = *stack;
	*stack = last;
	return (1);
}

int	rra(t_list **stack_a)
{
	if (rev_rotate(stack_a) == 0)
		return (0);
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_list **stack_b)
{
	if (rev_rotate(stack_b) == 0)
		return (0);
	ft_printf("rrb\n");
	return (1);
}
int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (rev_rotate(stack_a) == 0 && rev_rotate(stack_b) == 0)
		return (0);
	ft_printf("rrr\n");
	return (1);
}