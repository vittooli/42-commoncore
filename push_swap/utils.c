/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:56:40 by volivier          #+#    #+#             */
/*   Updated: 2024/04/11 15:56:41 by volivier         ###   ########.fr       */
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

int is_sorted(t_list *stack)
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