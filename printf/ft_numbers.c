/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:12:37 by volivier          #+#    #+#             */
/*   Updated: 2024/01/26 19:04:03 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr(int nb)
{
	int i;

	i = 0;
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
		return (11);
	}
	else if (nb < 0)
	{
		i += ft_putchar('-');
		ft_putnbr(-nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		i += ft_putchar(nb + 48);
	return (i);
}

int ft_put_unsigned(unsigned int nb)
{
	int i;

	i = 0;
	if (nb >= 10)
	{
		ft_put_unsigned(nb / 10);
		ft_put_unsigned(nb % 10);
	}
	else
		i += ft_putchar(nb + 48);
	return (i);
}