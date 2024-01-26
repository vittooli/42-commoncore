/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:51:18 by volivier          #+#    #+#             */
/*   Updated: 2024/01/27 00:49:03 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	ft_put_args(char type, va_list *args)
{
	if (type == '%')
		return (ft_putchar('%'));
	else if (type == 'c')
		return (ft_putchar((char)va_arg(*args, int)));
	else if (type == 's')
		return (ft_putstr((char *)va_arg(*args, char *)));
	else if (type == 'p')
		return (ft_pointer(va_arg(*args, unsigned long int)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (type == 'u')
		return (ft_put_unsigned(va_arg(*args, unsigned int)));
	else if (type == 'x')
		return (ft_lowhex(va_arg(*args, unsigned long int)));
	else if (type == 'X')
		return (ft_uphex(va_arg(*args, unsigned long int)));
	return(0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			len += ft_put_args(*format, &args);
		}
		else 
			len += ft_putchar(*format);
		format++;	
	}
	va_end(args);
	return (len);
}