/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromiti <gromiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:17:47 by gromiti           #+#    #+#             */
/*   Updated: 2024/01/22 15:56:23 by gromiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	cont;
	size_t	i;

	cont = 0;
	i = 0;
	if (!s)
		return (NULL);
	sub = (char *)malloc(sizeof(*s) * len + 1);
	if (!sub)
		return (NULL);
	while (s[cont])
	{
		if (start <= cont && i < len)
		{
			sub[i] = s[cont];
			i++;
		}
		cont++;
	}
	sub[i] = '\0';
	return (sub);
}
