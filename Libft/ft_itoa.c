/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:26:34 by volivier          #+#    #+#             */
/*   Updated: 2024/01/15 18:53:38 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_int(int n, int base)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n = n / base;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;
	const char	*digits = "0123456789";

	len = ft_len_int(n, 10);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		printf("%s", "ff");
		return (NULL);
	ret[len] = '\0';
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
		ret[0] = '-';
	while (n)
	{
		if (n > 0)
			ret[len--] = digits[n % 10];
		else
			ret[len--] = digits[n % 10 * -1];
		n = n / 10;
		//printf("%s", ret);
	}
	return (ret);
}

int	main()
{
	printf("%s", ft_itoa(12345));
	return (0);
}
