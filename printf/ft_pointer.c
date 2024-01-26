/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:25:18 by volivier          #+#    #+#             */
/*   Updated: 2024/01/27 00:54:39 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	ft_len(unsigned long int n)
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

int	ft_pointer(unsigned long int pointer)
{
	write(1, "0x", 2);
	ft_lowhex(pointer);
	printf("pointer: %d", ft_len(pointer));
	return (ft_len(pointer) + 2);
}