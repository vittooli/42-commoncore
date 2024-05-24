/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:06:13 by volivier          #+#    #+#             */
/*   Updated: 2024/05/24 10:06:49 by volivier         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_move	move;
	char	**mat;

	set_structs(&move);
	if (ac < 2)
		return (write(2, "Error\n", 6));
	mat = ft_validate(ac, av);
	if (mat == NULL)
		return (write(2, "Error\n", 6));
	a = get_stack(mat);
	if (a == NULL)
	{
		write(2, "Error\n", 6);
		return (free_list(&a));
	}
	b = NULL;
	if (is_sorted_a(a) == 0)
	{
		return (0);
	}
	sort(&a, &b, move);
	return (free_list(&a));
}
