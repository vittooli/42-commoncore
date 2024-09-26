/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:16:46 by volivier          #+#    #+#             */
/*   Updated: 2024/09/26 15:24:37 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

/* void	think(t_philos philos)
{
	printf("%d is thinking\n", philos.id);
}

/* controlla se la forchetta è busy, */
int	fork_routine(t_forks *fork)
{
	while (fork->busy == 1)
	{
		pthread_mutex_lock(&fork);//soltanto un lucchetto
		if (fork->busy == 0)
		{
			fork->busy = 1;
			pthread_mutex_unlock(&fork);
			return (1);
		}
		pthread_mutex_unlock(&fork);		
	}
	return (0);
	
}

void	eat(t_philos *philos)
{
	//function to check if fork is busy and if philo is dead 
	fork_routine(&philos->first_fork);
	printf("%d has taken a fork\n", philos->id);
	fork_routine(&philos->second_fork);
	printf("%d has taken a fork\n", philos->id);
	printf("%d is eating\n", philos->id);
}

void	*routine(void *pointer)
{
	t_philos	*philos;

	philos = pointer;
	while (philos->dead != 1)
	{
		eat(philos);
		usleep(philos->time_to_eat * 1000);
		/* sblocca fochette */
		usleep(philos->time_to_sleep * 1000);
		printf("%d is thinking\n", philos->id);
	}
};