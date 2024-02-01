/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:25:18 by volivier          #+#    #+#             */
/*   Updated: 2024/02/01 10:49:26 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_len(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	ft_pointer(void *pointer)
{
	write(1, "0x", 2);
	ft_lowhex((unsigned long int)(pointer));
	return (ft_len((unsigned long int)(pointer)) + 2);
}
