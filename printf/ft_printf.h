/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:51:01 by volivier          #+#    #+#             */
/*   Updated: 2024/02/02 16:26:07 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# ifdef __APPLE__
#  define NIL_STRING "0x0"
# endif
# ifdef __unix__
#  define NIL_STRING "(nil)"
# endif

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_put_unsigned(unsigned int nb);
int	ft_lowhex(unsigned long nb);
int	ft_uphex(unsigned long nb);
int	ft_pointer(void *pointer);

#endif
