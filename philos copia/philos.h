/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:13:14 by volivier          #+#    #+#             */
/*   Updated: 2025/02/17 17:48:00 by volivier         ###   ########.fr       */
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
	int				philo_id;
	int				single;
}t_forks;


typedef struct s_philos
{
	int			id;
	int			n_philos;
	size_t		time_to_die;
	size_t		time_to_sleep;
	size_t		time_to_eat;
	int			n_meals; //a number or a flag (-1) which idicates there is no specified limit
	size_t		last_meal_time;
	int			full;
	int			dead;
	size_t		start_of_sim;
	t_forks		*first_fork;
	t_forks		*second_fork;
	pthread_t	thread;
	int			someone_died;
	
}t_philos;

typedef struct s_data
{
	t_philos	*philos; //array of philosophers
	t_forks		**forks; //array of forks;
	int			end_of_sim; //flag
	
}t_data;

//initialise structs
int		init_philos(t_philos *philos, t_forks **forks, char **av);
int		init_data(t_data *data, char **av);
int		init_forks(t_forks **forks, int num);


//dinner
void	*routine(void *pointer);
size_t	get_time(void);

//utils
int		ft_atoi(const char *str);

int		create_threads(t_philos	*philos);
int		is_dead(t_philos *philos);
void	*monitor(void *pointer);

#endif