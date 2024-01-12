/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:05:51 by volivier          #+#    #+#             */
/*   Updated: 2024/01/09 17:11:55 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	i = -1;
	d = (char *)dst;
	s = (char *)src;
	while(i++ < len)
		d[i] = s[i];
	d[i] = '\0';
	return (dst);
}
