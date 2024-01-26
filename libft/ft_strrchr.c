/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:02:17 by volivier          #+#    #+#             */
/*   Updated: 2024/01/13 15:23:11 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (i != 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
