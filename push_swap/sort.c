/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:25:55 by volivier          #+#    #+#             */
/*   Updated: 2024/04/11 16:33:50 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_list **a, t_list **b)
{
	if (lst_size(*a) < 2)
		return (1);
	if (lst_size(*a) == 2) //se la lista ha solo due elementi non ordinati basta scambiarli
		sa(a);
	if (lst_size(*a) == 3)
	return (0);
}