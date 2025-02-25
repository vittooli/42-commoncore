/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:15:42 by volivier          #+#    #+#             */
/*   Updated: 2025/02/15 17:25:54 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	create_threads(t_philos	*philos) //starts the threads and joins them (which means the threads start executing in parallel)
{
	int i;

	i = 0;
	while (i < philos[0].n_philos) //threads for philos
	{
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]) != 0)
			return (1);
		i++;
		usleep(30);
	}
	i = 0;
	while (i < philos[0].n_philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}