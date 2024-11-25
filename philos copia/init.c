/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:12:49 by volivier          #+#    #+#             */
/*   Updated: 2024/11/25 13:21:15 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	init_forks(t_forks *forks, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_init(&forks[i].mutex, NULL);
		forks[i].id = i + 1;
		forks[i].busy = 0;
		if (num == 1)
			forks[i].single = 1;
		else
			forks[i].single = 0;
		i++;
	}
	return (0);
}

int	init_philos(t_philos *philos, t_forks *forks, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].start_of_sim = get_time();
		philos[i].id = i + 1; //philosopher's id
		philos[i].n_philos = ft_atoi(av[1]);
		philos[i].time_to_die = ft_atoi(av[2]);
		philos[i].time_to_sleep = ft_atoi(av[4]);
		philos[i].time_to_eat = ft_atoi(av[3]);
		philos[i].full = 0;
		philos[i].dead = 0;
		philos[i].last_meal_time = get_time();
		philos[i].first_fork = forks[i]; //every philosopher has a fork with the same id as his own
		if (i == ft_atoi(av[1]) - 1)
			philos[i].second_fork = forks[0]; //last philosopher has as second fork the first of the first philosopher
		else
			philos[i].second_fork = forks[i + 1];
		if (av[5])
			philos[i].n_meals = 0;
		else
			philos[i].n_meals = -1;
		i++;
	}
	return (0);
}



int	init_data(t_data *data, char **av)
{
	int		num_philos;

	num_philos = ft_atoi(av[1]);
	data->end_of_sim = 0;
	data->philos = malloc(sizeof(t_philos) * num_philos); //creates an empty array of philos
	data->forks = malloc(sizeof(t_forks) * num_philos); //creates an empty array of forks
	if (data->forks == NULL || data->philos == NULL)
	{
		printf("Malloc error with data\n");
		free(data->philos);
		free(data->forks);
		return (1);
	}
	init_forks(data->forks, num_philos);
	init_philos(data->philos, data->forks, av);
	return (0);
}
