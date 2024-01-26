/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:51:18 by volivier          #+#    #+#             */
/*   Updated: 2024/01/26 18:59:19 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	ft_put_args(char type, va_list *args)
{
	if (type == '%')
		return(ft_putchar('%'));
	else if (type == 'c')
		return(ft_putchar((char)va_arg(*args, int)));
	else if (type == 's')
		return(ft_putstr((char *)va_arg(*args, char *)));
	/*else if (type == 'p')
		ft_pointer(va_arg(args, int));*/
	else if (type == 'd' || type == 'i') //da vedere la distinzione tra i due
		return(ft_putnbr(va_arg(*args, int)));
	else if (type == 'u')
		return(ft_put_unsigned(va_arg(*args, unsigned int)));
	//printf("%d", len);
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