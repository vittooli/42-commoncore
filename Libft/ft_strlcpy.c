/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:18:57 by volivier          #+#    #+#             */
/*   Updated: 2024/01/09 17:29:54 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int srcsize;

	srcsize = strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

/*int	main()
{
	char	dst[5];
	char	src[] = "ciao";
	size_t	i = 3;


	ft_strlcpy(dst, src, i);
	printf("ft_strlcpy: %s\n", dst);
	
	strlcpy(dst, src, i);
	printf("strlcpy: %s", dst);
}*/
