/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:56:36 by volivier          #+#    #+#             */
/*   Updated: 2024/05/07 16:25:41 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_structs(t_move *move)
{
	move->cases = 0;
	move->cost = 0;
	move->target_a = NULL;
	move->target_b = NULL;
}
int print_list(t_list *stack)
{
    t_list  *head;
    head = stack;
    while (head)
    {
        printf("%d\n", head->content);
        head = head->next;
    }
    return(0);
}

int free_list(t_list **stack)
{
    t_list *head;

    head = *stack;
    
    while (head)
    {
        free(head);
        head = head->next;
    }
    return (0);
}
t_move find_move(t_list *a, t_list *b, t_move *move)
{
    t_list  *head;
    t_move good_move;
    
    good_move.cost = 10000000;
    head = a;
    while(head)
    {
        move->target_a = head;
        move->target_b = find_target(move->target_a->content, b);
        find_cost(a, b, move);
        if(good_move.cost > move->cost)
        {
            good_move.cost = move->cost;
            good_move.cases = move->cases;
            good_move.target_a = move->target_a;
            good_move.target_b = move->target_b;
        } //dopo questo move conterrà cost, caso per target_a e target_b
        head = head->next;
    }
    return(good_move);
}
int	sort(t_list **a, t_list **b, t_move move)
{
	if (lst_size(*a) < 2)
		return (1);
	else if (lst_size(*a) == 2) //se la lista ha solo due elementi non ordinati basta scambiarli
		sa(a);
	else if (lst_size(*a) == 3)
		sort_three(a);
    else if (lst_size(*a) == 4 || lst_size(*a) == 5 )
        sort_else(a, b);
    else    
    {
        pb(a, b);
        pb(a, b);
        while(*a)
        {
            move = find_move(*a, *b, &move);
            move_stacks(a, b, &move);
        }
        while(is_sorted_b(*b) == 1)
            optimize(b);
        while(*b)
            pa(b, a);
    }
	return (0);
}
int main(int ac, char **av)
{
    t_list  *a;
	t_list	*b;
    t_move  move;
    char    **mat;
    
    set_structs(&move);
    if (ac < 2)
        return (write(2, "Error\n", 6));
    mat = ft_validate(ac, av);
    if (mat == NULL)
        return (write(2, "Error\n", 6));
    a = get_stack(mat);
    print_list(a);
    if (a == NULL)
    {
        write(2, "Error\n", 6);
        return (free_list(&a));
    }
    b = (t_list *)malloc(sizeof(t_list));
    b = NULL;
    if (is_sorted_a(a) == 0)
    {
        printf("boh");
        return (0);
    }
    sort(&a, &b, move);
    return (free_list(&a));
}

