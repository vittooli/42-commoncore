/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:12:49 by volivier          #+#    #+#             */
/*   Updated: 2024/09/18 19:45:29 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	init_philos(t_philos **philos, char **av)
{
	int	i;

	i = 0;
	while (i <= ft_atoi(av[1]))
	{
		philos[i] = (t_philos *)malloc(sizeof(t_philos));
		philos[i]->id = i + 1; //philosopher's id
		philos[i]->n_philos = ft_atoi(av[1]);
		philos[i]->time_to_die = ft_atoi(av[2]);
		philos[i]->time_to_sleep = ft_atoi(av[4]);
		philos[i]->time_to_eat = ft_atoi(av[3]);
		if (av[5])
			philos[i]->n_meals = ft_atoi(av[5]);
		else
			philos[i]->n_meals = -1;
		i++;
	}
}

void	init_landlord()
{
	
}