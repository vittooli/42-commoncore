/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:43:48 by volivier          #+#    #+#             */
/*   Updated: 2024/11/25 12:44:26 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"
#include <stdio.h>

int	check_input1(char **av) //verify of the arguments are integers
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while(av[i][j] == ' ') //maybe change into a function that check for all types of spaces
			j++;
		while (av[i][j] >= 48 && av[i][j] <= 57)
			j++;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j])
			return (1);
		i++;
	}
	return (0);
}

int	check_input2(char **av)
{
	int i;

	i = 2;
	if (ft_atoi(av[1]) < 0 || ft_atoi(av[1]) > 199)
		return (1);
	while (av[i])
	{
		if (ft_atoi(av[i]) <= 0 || ft_atoi(av[i]) > MAX_INT)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data		data;
	
	if (ac < 5 || ac > 6)
	{
		printf("wrong number of args\n");
		return (0);
	}
	if (check_input1(av) != 0 || check_input2(av) != 0)
	{
		printf("input not ok\n");
		return (0);
	}
	if (init_data(&data, av) != 0) //initializes data, philos structs and forks struct
		return (0);
	//printf("timestamp: %li\n", timestamp);
	create_threads(data.philos); //threads created and running in parallel
	return (0);
}
