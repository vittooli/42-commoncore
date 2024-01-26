/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:32:31 by volivier          #+#    #+#             */
/*   Updated: 2024/01/26 18:51:36 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
		i++;
	}
	return (i);
}