/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:56:31 by volivier          #+#    #+#             */
/*   Updated: 2024/05/16 17:43:27 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>

typedef struct s_move
{
	int cost;
	int	cases;
	t_list	*target_a;
	t_list	*target_b;
} t_move;

/* validation */
int 	check_list(char **list);
char 	**get_av(int ac, char **av);
char    **ft_validate(int ac, char **av);
t_list  *get_stack(char **mat);
int 	check_stack(t_list  *node);
int		check_dup(char **mat);
/* utils */
int		lst_size(t_list *list);
int 	is_sorted_a(t_list *stack);
int 	is_sorted_b(t_list *stack);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		find_max_three(t_list **head);
/* operations */
int		swap(t_list **stack);
int		push(t_list **src, t_list **dest);
int		pa(t_list **stack_b, t_list **stack_a);
int		pb(t_list **stack_a, t_list **stack_b);
int		sa(t_list **stack);
int		sb(t_list **stack);
int		ss(t_list **stack_a, t_list **stack_b);
int		rotate(t_list **stack);
int		ra(t_list **stack);
int		rb(t_list **stack);
int		rr(t_list **stack_a, t_list	**stack_b);
int		rev_rotate(t_list **stack);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);
int		print_list(t_list *stack);
/* sort */
int		sort(t_list **a, t_list **b, t_move move);
int		sort_three(t_list **stack);
void 	sort_else(t_list **stack, t_list **b);
t_list 	*return_max(t_list *stack);
t_list 	*return_min(t_list *stack);
t_list 	*find_target(int value, t_list *b);
int		get_target(t_list **stack, int target);
t_list 	*find_target(int value, t_list *b);
void 	find_cost(t_list *a, t_list *b, t_move *move);
int		get_index(t_list *stack, t_list	*target);
/* move */
void 	move_stacks(t_list **a, t_list **b, t_move *move);
void	optimize(t_list **stack, int inde);
int 	free_list(t_list **stack);
void	free_mat(char **mat);

#endif