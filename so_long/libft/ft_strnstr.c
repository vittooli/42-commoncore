/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:02:11 by volivier          #+#    #+#             */
/*   Updated: 2024/01/13 18:30:25 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((!h || !n) && len == 0)
		return (NULL);
	if (!*n)
		return ((char *)h);
	while (h[i])
	{
		j = 0;
		while (h[i] == n[j] && h[i] && i < len)
		{
			i++;
			j++;
		}
		if (!n[j])
			return ((char *)&h[i - j]);
		i = i - j + 1;
	}
	return (NULL);
}
