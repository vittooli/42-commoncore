/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:16:46 by volivier          #+#    #+#             */
/*   Updated: 2025/02/17 17:24:42 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"
#include <unistd.h>

void	*monitor(void *pointer)
{
	t_data	*data;
	int		i;

	data = (t_data *)pointer;
	while (!data->end_of_sim)
	{
		i = 0;
		while (i < data->philos[0].n_philos)
		{
			if (is_dead(&data->philos[i]))
			{
				data->end_of_sim = 1;
				break ;
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}