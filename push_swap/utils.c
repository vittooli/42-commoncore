/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:56:40 by volivier          #+#    #+#             */
/*   Updated: 2024/04/28 19:25:14 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_size(t_list *list)
{
	int len;

	len = 0;
	while(list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

int is_sorted_a(t_list *stack) //resituisce 0 se è sorted
{
    t_list  *head;

    head = stack;
    while (head && head->next)
    {
        if (head->content > head->next->content)
            return (1);
        head = head->next;
    }
    return (0);
}

int is_sorted_b(t_list *stack)
{
	    t_list  *head;

    head = stack;
    while (head && head->next)
    {
        if (head->content < head->next->content)
            return (1);
        head = head->next;
    }
    return (0);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}
int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}