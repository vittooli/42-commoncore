/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:13:14 by volivier          #+#    #+#             */
/*   Updated: 2024/09/26 15:20:45 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_H
# define PHILOS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# ifndef MAX_INT
# define MAX_INT 2147483647
# endif

typedef	struct s_forks
{
	pthread_mutex_t	mutex;
	int				id;
	int				busy;
}t_forks;


typedef struct s_philos
{
	int			id;
	int			n_philos;
	int			time_to_die;
	int			time_to_sleep;
	int			time_to_eat;
	int			n_meals; //a number or a flag (-1) which idicates there is no specified limit
	int			last_meal_time;
	int			full;
	int			dead;
	t_forks		first_fork;
	t_forks		second_fork;
	pthread_t	thread;
	
}t_philos;

typedef struct s_data
{
	t_philos	*philos; //array of philosophers
	t_forks		*forks; //array of forks;
	long		start_of_sim;
	int			end_of_sim; //flag
	
}t_data;

//initialise structs
int	init_philos(t_philos *philos, t_forks *forks, char **av);
int	init_data(t_data *data, char **av);
int	init_forks(t_forks *forks, int num);
int	create_threads(t_philos	*philos);

//dinner
void	*routine();

//utils
int	ft_atoi(const char *str);

#endif