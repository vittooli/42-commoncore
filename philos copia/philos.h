/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:13:14 by volivier          #+#    #+#             */
/*   Updated: 2024/09/18 19:43:39 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <pthread.h>
# include <stdlib.h>

typedef struct s_philos
{
	int			id;
	int			n_philos;
	int			n_meals;
	int			time_to_die;
	int			time_to_sleep;
	int			time_to_eat;
	pthread_t	thread;
	
}t_philos;

typedef struct s_landlord
{
	t_philos	*philos;
}t_landlord;

void	init_philos(t_philos **philos, char **av);
int		ft_atoi(const char *str);

#endif