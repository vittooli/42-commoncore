/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:16:36 by volivier          #+#    #+#             */
/*   Updated: 2024/01/13 18:06:17 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*res;

	len = ft_strlen((char *)src);
	if (src == NULL)
		return (NULL);
	res = malloc(sizeof(char) * (len + 1));
	len = 0;
	if (res == NULL)
		return (NULL);
	while (src[len])
	{
		res[len] = src[len];
		len++;
	}
	res[len] = '\0';
	return (res);
}
