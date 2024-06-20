/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:39:40 by volivier          #+#    #+#             */
/*   Updated: 2024/06/20 16:18:30 by volivier         ###   ########.fr       */
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

void    send_signal(char c, int pid)//sends the single bits starting from the MSB
{
	int	i;
	int	shifted_c;
	
	i = 7;
	while (i >= 0) //for each bit
	{
		shifted_c = c>>i; //moves the bit i'm interested in to the LSB position
		if (shifted_c & 1 == 1) //the bitwise & operator checks LSB
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

void    confirmation(int signal)
{
    if (signal == SIGUSR1)
        ft_printf("Server received 1\n");
    else if (signal == SIGUSR2)
        ft_printf("Server received 0\n");
}

int main(int ac, char **av)
{
	int		pid;
	int		i;
	char	*string;
	
    signal(SIGUSR1, confirmation);
    signal(SIGUSR2, confirmation);
	if (ac != 3)//program name, PID, string to be sent
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
	while (string[i]) //for each character
	{
		send_signal(string[i], pid);
		i++;
	}
	send_signal(string[i], pid);
}