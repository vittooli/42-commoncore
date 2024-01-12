#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h> 

//dichiarazione dei prototipi
void	ft_bzero(void *str, size_t len);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int	ft_strlen(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *str, int c, size_t len);
int ft_strlcat(char *dst, const char *src, size_t dstsize);
int	ft_strlcpy(char *dst, const char *src, size_t dstsize);


#endif
