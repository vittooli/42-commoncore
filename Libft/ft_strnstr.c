/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:02:11 by volivier          #+#    #+#             */
/*   Updated: 2024/01/13 14:15:42 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ptr;

	i = 0;
	j = 0;
	ptr = -1;
	while (n[j] != '\0' && i <= len && j <= len)
	{
		printf("i: %zu\n",i);
		if (h[i] == n[j])
		{
			ptr = i;
			j = 0;
			while (h[i] == n[j])
			{
				i++;
				j++;
			}
		}
		else
			i++;
		printf("j: %zu\n",j);
		if ((int)j == ft_strlen((char *)n))
			return ((char *)&h[ptr]);
	}
	return (NULL);
}

/*int	main()
{
	printf("%p", ft_strnstr("casalale", "le", 8));
	return(0);
}*/
