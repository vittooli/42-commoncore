/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:16:46 by volivier          #+#    #+#             */
/*   Updated: 2025/02/17 17:46:52 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"


/* controlla se la forchetta è busy, */
int	fork_routine(t_forks *fork1, t_forks *fork2)
{
	int	ret;
	
	ret = 0;
	pthread_mutex_lock(&fork1->mutex);
	pthread_mutex_lock(&fork2->mutex);
	if (fork1->busy == 0 && fork2->busy == 0) //fork is not busy
	{
		ret = 1;
		fork1->busy = 1;
		fork2->busy = 1;
	}
	pthread_mutex_unlock(&fork1->mutex);
	pthread_mutex_unlock(&fork2->mutex);
	return (ret);
}

int	eat(t_philos *philos)
{
	//function to check if fork is busy and if philo is deadz
	while (1)
	{
		if (fork_routine(philos->first_fork, philos->second_fork) == 1 && is_dead(philos) == 0 && philos->n_meals != 0)
		{
			printf("%li %d has taken a fork\n", get_time() - philos->start_of_sim, philos->id);
			printf("%li %d has taken a fork\n", get_time() - philos->start_of_sim, philos->id);
			printf("%li %d is eating\n", get_time() - philos->start_of_sim, philos->id);
			return (0);
		}
		if (is_dead(philos) == 1)
		{
			return (1);
		}
	}
}

void	*routine(void *pointer) //void pointer contains single philosopher
{
	t_philos	*philos;
	
	philos = pointer; //now philos contains single philosopher
	philos->last_meal_time = get_time();
	while (philos->dead != 1 && philos->full == 0)
	{
		usleep(300);
		if (eat(philos) == 1) //error with forks
			break ;
		usleep(philos->time_to_eat * 1000);
		philos->last_meal_time = get_time();
		pthread_mutex_lock(&philos->first_fork->mutex);
		pthread_mutex_lock(&philos->second_fork->mutex);
		philos->first_fork->busy = 0;
		philos->second_fork->busy = 0;
		pthread_mutex_unlock(&philos->first_fork->mutex);
		pthread_mutex_unlock(&philos->second_fork->mutex);
		philos->n_meals--;
		if (philos->n_meals == 0)
			philos->full = 1;
		printf("%li %d is sleeping\n", get_time() - philos->start_of_sim, philos->id); //philos COULD die while sleeping (?)
		usleep(philos->time_to_sleep * 1000);
		printf("%li %d is thinking\n", get_time() - philos->start_of_sim, philos->id); //philos COULD die while thinking (?)
	}
	return(philos);
}

