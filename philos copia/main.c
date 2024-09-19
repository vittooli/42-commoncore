/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:43:48 by volivier          #+#    #+#             */
/*   Updated: 2024/09/18 19:46:17 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"
#include <stdio.h>

int	check_input(char **av) //verifica che gli argomenti siano degli interi
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while(av[i][j] == ' ')
			j++;
		while (av[i][j] >= 48 && av[i][j] <= 57)
			j++;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philos	*philos[100];
	
	if (ac < 5 || ac > 6)
	{
		printf("wrong number of args\n");
		return (0);
	}
	if (check_input(av) == 0)
	{
		printf("input not ok\n");
		return (0);
	}
	init_philos(philos, av);
	for (int j = 0; j < ft_atoi(av[1]); j++){
		printf("input data:\n n_philos-> %d\n id-> %d\n", philos[j]->n_philos, philos[j]->id);
	}
	return (0);
}