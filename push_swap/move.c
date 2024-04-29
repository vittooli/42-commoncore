#include "push_swap.h"

void	move_case_one(t_list **a, t_list **b, t_move *move)
{
	while (*a != move->target_a && *b != move->target_b)
		rr(a, b);
	if (*a == move->target_a)
	{
		while (*b != move->target_b)
			rb(b);
	}
	else if (*b == move->target_b)
	{
		while (*a != move->target_a)
			ra(a);
	}
	pb(a, b);
}
void	move_case_two(t_list **a, t_list **b, t_move *move)
{
	while (*a != move->target_a)
		ra(a);
	while (*b != move->target_b)
		rrb(b);
	pb(a, b);
}

void	move_case_three(t_list **a, t_list **b, t_move *move)
{
	while (*a != move->target_a)
		rra(a);
	while (*b != move->target_b)
		rb(b);
	pb(a, b);
}

void	move_case_four(t_list **a, t_list **b, t_move *move)
{
	while (*a != move->target_a && *b != move->target_b)
			rrr(a, b);
	if (*a == move->target_a)
	{
		while (*b != move->target_b)
			rrb(b);
	}
	else if (*b == move->target_b)
	{
		while (*a != move->target_a)
			rra(a);
	}
	pb(a, b);
}

void	move_stacks(t_list **a, t_list **b, t_move *move)
{
	if (move->cases == 1)
		move_case_one(a, b, move);
	else if (move->cases == 2)
		move_case_two(a, b, move);
	else if (move->cases == 3)
		move_case_three(a, b, move);
	else
		move_case_four(a, b, move);
}