/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:53:36 by volivier          #+#    #+#             */
/*   Updated: 2024/01/13 19:02:02 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

//dichiarazione dei prototipi
void	ft_bzero(void *str, size_t len);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int	ft_strlen(char *str);
int ft_tolower(int c);
int ft_toupper(int c);
int	ft_atoi(const char *str);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *str, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
int	ft_memcmp(const void *str1, const void *str2, size_t n);
int ft_strlcat(char *dst, const char *src, size_t dstsize);
int	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int	ft_strncmp(const char *s1, const char *s2, int n);
char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *h, const char *n, size_t len);
char	*ft_strdup(const char *src);
#endif
