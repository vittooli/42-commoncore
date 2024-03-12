/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:26:34 by volivier          #+#    #+#             */
/*   Updated: 2024/01/16 17:07:30 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_int(long int n)
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
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*ret;
	long int	nbr;

	nbr = (long int)n;
	len = ft_len_int(nbr);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	len--;
	if (nbr == 0)
		ret[0] = '0';
	if (nbr < 0)
	{
		ret[0] = '-';
		nbr *= -1;
	}
	while (nbr != 0)
	{
		ret[len] = (nbr % 10 + '0');
		nbr = nbr / 10;
		len--;
	}
	return (ret);
}
