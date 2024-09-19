/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:15:42 by volivier          #+#    #+#             */
/*   Updated: 2024/09/18 19:46:56 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	*routine();

int	create_threads(t_philos	*philos)
{
	int i;

	i = 0;
	while (i++ < philos[i].n_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, &routine, NULL) != 0)
			return (1);
	}
	i = 0;
	while (i++ < philos[i].n_philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return (1);
	}
}