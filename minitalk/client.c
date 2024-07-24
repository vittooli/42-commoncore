/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:17:54 by volivier          #+#    #+#             */
/*   Updated: 2024/07/04 17:02:45 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf/ft_printf.h"
#include <signal.h>

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

void	send_signal(char c, int pid)
{
	int	i;
	int	shifted_c;

	i = 7;
	while (i >= 0)
	{
		shifted_c = c >> i;
		if ((shifted_c & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	char	*string;

	if (ac != 3)
	{
		if (ac > 3)
			ft_printf("Too many arguments");
		else if (ac < 3)
			ft_printf("Too few arguments");
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (1);
	string = av[2];
	i = 0;
	while (string[i])
	{
		send_signal(string[i], pid);
		i++;
	}
	send_signal(string[i], pid);
}
