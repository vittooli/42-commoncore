/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:15:42 by volivier          #+#    #+#             */
/*   Updated: 2024/09/26 22:43:23 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	create_threads(t_philos	*philos) //starts the threads and joins them (which means the threads start executing in parallel)
{
	int i;

	i = 0;
	while (i < philos[i].n_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, &routine, philos) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < philos[i].n_philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}