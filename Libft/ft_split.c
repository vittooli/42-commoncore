/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:15:13 by volivier          #+#    #+#             */
/*   Updated: 2024/01/15 14:16:22 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_start(char const *s, char c, int i)
{
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			return (i);
		i++;
	}
	return (i);
}

int	ft_find_end(char const *s, char c, int i)
{
	while (s[i] != '\0')
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
	str = (char *)malloc(sizeof(*s) * (end - start + 1));
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
	if (!arr)
		return (NULL);
	i = 0;
	start = ft_find_start(s, c, 0);
	while (i < ft_count_words(s, c))
	{
		end = ft_find_end(s, c, start);
		arr[i] = ft_alloc(s, start, end);
		start = ft_find_start(s, c, end + 1);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

int	main()
{
	int i;
	char **arr;

	i = 0;
	arr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	return(0);
}

