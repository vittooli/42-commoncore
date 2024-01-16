/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:15:13 by volivier          #+#    #+#             */
/*   Updated: 2024/01/16 18:52:46 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_start(char const *s, char c, int i)
{
	while (i >= 0 && s[i] != '\0')
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			return (i);
		i++;
	}
	return (i);
}

int	ft_find_end(char const *s, char c, int i)
{
	while (i >= 0 && s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			return (i);
		i++;
	}
	return (i);
}

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*ft_alloc(char const *s, int start, int end)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (str == NULL)
		return (NULL);
	while (i <= (end - start))
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		end;
	char	**arr;

	arr = (char **)malloc(sizeof(s) * (ft_count_words(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	start = ft_find_start(s, c, 0);
	while (i < ft_count_words(s, c))
	{
		end = ft_find_end(s, c, start);
		arr[i] = ft_alloc(s, start, end);
		if (arr[i] == NULL)
			return (NULL);
		start = ft_find_start(s, c, end + 1);
		i++;
	}
	arr[i] = 0;
	return (arr);
}
