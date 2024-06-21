/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:55:46 by volivier          #+#    #+#             */
/*   Updated: 2024/06/22 00:17:15 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf/ft_printf.h"
#include <signal.h>

void	signal_handler(int signal)
{
	static char	c;
	static int	counter;

	if (signal == SIGUSR1)
		c = c | 1;
	counter++;
	if (counter == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		c = 0;
		counter = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (1);
}
