/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:56:31 by volivier          #+#    #+#             */
/*   Updated: 2024/04/11 16:32:30 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>

/* validation */
int 	check_list(char **list);
char 	**get_av(int ac, char **av);
char    **ft_validate(int ac, char **av);
t_list  *get_stack(char **mat);
int 	check_stack(t_list  *node);
/* utils */
int		lst_size(t_list *list);
int 	is_sorted(t_list *stack);
/* operations */
int		swap(t_list **stack);
int		push(t_list **src, t_list **dest);
int		pa(t_list **stack_b, t_list **stack_a);
int		pb(t_list **stack_a, t_list **stack_b);
int		sa(t_list **stack);
int		sb(t_list **stack);
int		ss(t_list **stack_a, t_list **stack_b);
int		rotate(t_list **stack);
int		rev_rotate(t_list **stack);
/* sort */
int		sort(t_list **a, t_list **b);

#endif