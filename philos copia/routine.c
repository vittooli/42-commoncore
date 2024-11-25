/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:16:46 by volivier          #+#    #+#             */
/*   Updated: 2024/11/25 13:20:28 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	philos_is_full(t_philos *philos)
{
	if (philos->n_meals == 0)
		philos->full = 1;
}

/* controlla se la forchetta è busy, */
int	fork_routine(t_forks *fork, t_philos *philos)
{
	pthread_mutex_lock(&fork->mutex);
	if (fork->busy == 0) //fork is not busy
	{
		//soltanto un lucchetto
		if (philos->dead == 1)
		{
			pthread_mutex_unlock(&fork->mutex);
			return (-1);
		}
		fork->busy = 1;
		pthread_mutex_unlock(&fork->mutex);
		return (1);
	}
	return (0);
	
}

int	eat(t_philos *philos)
{
	//function to check if fork is busy and if philo is dead
	if ((get_time() - philos->last_meal_time) >= philos->time_to_die || philos->dead == 1)
	{
		philos->dead = 1;
		return (-1);
	}
	if (fork_routine(&philos->first_fork, philos) == 1)
		printf("%li %d has taken a fork\n", get_time() - philos->start_of_sim, philos->id);
	else
		return (1);
	if (fork_routine(&philos->second_fork, philos) == 1 && philos->second_fork.single == 0)
		printf("%li %d has taken a fork\n", get_time() - philos->start_of_sim, philos->id);
	else
	{
		philos->dead = 1;
		return (-1);
	}
	printf("%li %d is eating\n", get_time() - philos->start_of_sim, philos->id);
	philos->last_meal_time = get_time();
	philos->n_meals = philos->n_meals - 1;
	return (0);
}

void	*routine(void *pointer) //void pointer contains single philosopher
{
	t_philos	*philos;

	philos = pointer; //now philos contains single philosopher
	while (philos->dead != 1 && philos->full == 0)
	{
		usleep(300);
		//printf("timestamp: %li", timestamp);
		if (eat(philos) == 1) //error with forks
			break ;
		if (philos->dead == 1) //philosopher died
		{
			printf("%li %d died\n", get_time() - philos->start_of_sim, philos->id);
			break ;
		}
		usleep(philos->time_to_eat * 1000);
		philos->first_fork.busy = 0;
		philos->second_fork.busy = 0;
		printf("%li %d is sleeping\n", get_time() - philos->start_of_sim, philos->id);
		usleep(philos->time_to_sleep * 1000);
		printf("%li %d is thinking\n", get_time() - philos->start_of_sim, philos->id);
		philos_is_full(philos);
	}
	
	return(philos);
}