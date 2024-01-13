/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:45:00 by volivier          #+#    #+#             */
/*   Updated: 2024/01/13 11:24:16 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	return (str);
}

/*int main() 
{
    char myArray[10];
    ft_memset(myArray, 'A', sizeof(myArray));
    printf("Array dopo l'inizializzazione: %s\n", myArray);
    return 0;
}*/
