/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:50:07 by volivier          #+#    #+#             */
/*   Updated: 2025/02/17 17:39:09 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' \
			|| str[i] == '\t' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

size_t	get_time(void)
{
	struct timeval	time;
	size_t			ret;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	ret = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ret);
}

int	is_dead(t_philos *philos)
{
	if ((get_time() - philos->last_meal_time) >= philos->time_to_die)
	{
		philos->dead = 1;
		printf("%li %d died\n", get_time() - philos->start_of_sim, philos->id);
		return (1);
	}
	return (0);
}