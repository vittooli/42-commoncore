/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:01:03 by volivier          #+#    #+#             */
/*   Updated: 2024/01/16 17:45:59 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;
	size_t			i;

	i = 0;
	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1_ptr[i] && s2_ptr[i])
	{
		if (s1_ptr[i] != s2_ptr[i])
			return (s1_ptr[i] - s2_ptr[i]);
		i++;
	}
	return (s1_ptr[i] - s2_ptr[i]);
}*/

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *s1_ptr = (const unsigned char *)s1;
    const unsigned char *s2_ptr = (const unsigned char *)s2;

    while (n--)
    {
        if (*s1_ptr != *s2_ptr)
            return (*s1_ptr - *s2_ptr);

        s1_ptr++;
        s2_ptr++;
    }

    return 0;
}