/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:56:26 by volivier          #+#    #+#             */
/*   Updated: 2024/04/11 15:56:27 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* funzioni sa, sb, ss */

int	swap(t_list **stack)
{
	int		tmp;
	if (lst_size(*stack) < 2)
		return (1);
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	return (0);
}

int	sa(t_list **stack)
{
	if (swap(stack) == 1)
		return (1);
	printf("sa ");
	return (0);
}

int	sb(t_list **stack)
{
	if (swap(stack) == 1)
		return (1);
	printf("sb ");
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a) == 1 || swap(stack_b) == 1)
		return (1);
	printf("ss ");
	return (0);
}

/* funzioni pa, pb, */

int	push(t_list **src, t_list **dest)
{
	int		tmp;
	t_list	*node;
	if (*src == NULL)
		return (1);
	tmp = (*src)->content;
	*src = (*src)->next;
	node = ft_lstnew(tmp);
	ft_lstadd_front(dest, node);
	return (0);
}
int	pa(t_list **stack_b, t_list **stack_a)
{
	if (push(stack_b, stack_a) == 1)
		return (1);
	printf("pa ");
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == 1)
		return (1);
	printf("pb ");
	return (0);
}

/* rotate: ra, rb, rr */

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return (1);
	head = *stack;
	last = ft_lstlast(*stack);
	*stack = head->next;
	last->next = head;
	head->next = NULL;
	return (0);
}

int	rev_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;

	if (lst_size(*stack) < 2)
		return (1);
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
	return (0);
}