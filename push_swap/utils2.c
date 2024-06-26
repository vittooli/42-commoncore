/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:12:35 by volivier          #+#    #+#             */
/*   Updated: 2024/05/24 13:36:32 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*return_max(t_list *stack)
{
	t_list	*max;
	t_list	*head;

	head = stack;
	max = head;
	while (head)
	{
		if (head->content > max->content)
			max = head;
		head = head->next;
	}
	return (max);
}

t_list	*return_min(t_list *stack)
{
	t_list	*min;
	t_list	*head;

	head = stack;
	min = head;
	while (head)
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
	t_list	*tmp;

	tmp = (*head)->next;
	if ((*head)->content < tmp->content
		&& (*head)->content < tmp->next->content)
		return (1);
	else if (tmp->content < (*head)->content
		&& tmp->content < tmp->next->content)
		return (2);
	else
		return (3);
}

int	find_max_three(t_list **head)
{
	t_list	*tmp;

	tmp = (*head)->next;
	if ((*head)->content > tmp->content
		&& (*head)->content > tmp->next->content)
		return (1);
	else if (tmp->content > (*head)->content
		&& tmp->content > tmp->next->content)
		return (2);
	else
		return (3);
}

void	free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}
