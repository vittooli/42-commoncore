// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line_utils.c                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/01/30 20:33:40 by volivier          #+#    #+#             */
// /*   Updated: 2024/02/03 21:24:18 by jnenczak         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"

// int	ft_strlen(const char *s)
// {
// 	int	len;

// 	len = 0;
// 	while (s[len] != '\0')
// 	{
// 		len += 1;
// 	}
// 	return (len);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*str;
// 	int		i;
// 	int		j;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	str = (char *)malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
// 	if (!str)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i])
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j])
// 	{
// 		str[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// char	*ft_strdup(const char *src)
// {
// 	size_t	len;
// 	char	*res;

// 	len = ft_strlen((char *)src);
// 	if (src == NULL)
// 		return (NULL);
// 	res = malloc(sizeof(char) * (len + 1));
// 	len = 0;
// 	if (res == NULL)
// 		return (NULL);
// 	while (src[len])
// 	{
// 		res[len] = src[len];
// 		len++;
// 	}
// 	res[len] = '\0';
// 	return (res);
// }

// int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;
// 	int		srcsize;

// 	srcsize = ft_strlen((char *)src);
// 	i = 0;
// 	if (dstsize != 0)
// 	{
// 		while (src[i] && i < dstsize - 1)
// 		{
// 			dst[i] = src[i];
// 			i++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	return (srcsize);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if (s[i] == c)
// 		return ((char *)&s[i]);
// 	return (NULL);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnenczak <jnenczak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:24:47 by jakubnencza       #+#    #+#             */
/*   Updated: 2024/02/02 17:25:47 by jnenczak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	converted;

	if (!s)
		return (NULL);
	converted = (char)c;
	while (*s)
	{
		if ((*s) == converted)
			return ((char *)s);
		s++;
	}
	if ((*s) == converted)
		return ((char *)s);
	return (NULL);
}

int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	size;
	size_t	curr;
	int		size_1;
	int		size_2;

	if (!s1 || !s2)
		return (NULL);
	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	size = size_1 + size_2 + 1;
	ret = (char *)malloc(sizeof(char) * size);
	if (!ret)
		return (NULL);
	curr = 0;
	while (*s1)
		ret[curr++] = *s1++;
	ft_strlcpy(ret + curr, s2, size - size_1);
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*alloc;

	if (!s1)
		return (NULL);
	i = 0;
	alloc = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!alloc)
		return (NULL);
	while (*s1)
		alloc[i++] = *s1++;
	alloc[i] = '\0';
	return (alloc);
}

/*char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	size;
	size_t	curr;
	int		size_1;
	int		size_2;

	if (!s1 || !s2)
		return (NULL);
	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	size = size_1 + size_2 + 1;
	ret = (char *)malloc(sizeof(char) * size);
	if (!ret)
		return (NULL);
	curr = 0;
	while (*s1)
		ret[curr++] = *s1++;
	ft_strlcpy(ret + curr, s2, size - size_1);
	return (ret);
}*/
