/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:01:50 by volivier          #+#    #+#             */
/*   Updated: 2024/01/13 15:00:40 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	int		srcsize;
	size_t	d_len;

	d_len = ft_strlen((char *)dst);
	d = d_len;
	s = 0;
	if (dstsize < d_len)
		return (ft_strlen((char *)src) + dstsize);
	while (src[s] != '\0' && d + 1 < dstsize)
	{
		dst[d] = src[s];
		s++;
		d++;
	}
	dst[d] = '\0';
	srcsize = ft_strlen((char *)src);
	return (d_len + srcsize);
}
