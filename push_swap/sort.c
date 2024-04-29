/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:25:55 by volivier          #+#    #+#             */
/*   Updated: 2024/04/28 19:18:19 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *return_max(t_list *stack)
{
	t_list	*max;
	t_list	*head;

	head = stack;
	max = head;
	while(head)
	{
		if (head->content > max->content)
			max = head;
		head = head->next;
	}
	return (max);
}

/* potrebbe servirmi ma boh */
t_list *return_min(t_list *stack)
{
	t_list *min;
	t_list *head;

	head = stack;
	min = head; 
	while(head)
	{
		if (head->content < min->content)
			min = head;
		head = head->next;
	}
	return (min);
}

/* potrebbe servirmi ma boh */
int	find_min(t_list **head)
{
	t_list *tmp;

	tmp = (*head)->next;
	if((*head)->content < tmp->content && (*head)->content < tmp->next->content)
		return (1);	
	else if(tmp->content < (*head)->content && tmp->content < tmp->next->content)
		return (2);
	else
		return(3);
}

int	find_max_three(t_list **head)
{
	t_list *tmp;

	tmp = (*head)->next;
	if((*head)->content > tmp->content && (*head)->content > tmp->next->content)
		return (1);	
	else if(tmp->content > (*head)->content && tmp->content > tmp->next->content)
		return (2);
	else
		return(3);
}

int	sort_three(t_list **stack)
{
	if (find_max_three(stack) == 1)
		ra(stack);
	if (find_max_three(stack) == 2)
		rra(stack);
	if (find_max_three(stack) == 3 && is_sorted_a(*stack) == 1)
		sa(stack);
	return(0);
}


