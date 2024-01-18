/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:15:13 by volivier          #+#    #+#             */
/*   Updated: 2024/01/18 18:01:28 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_start(char const *s, char c, int i)
{
	if (!s)
		return (0);
	while (i >= 0 && s[i] != '\0')
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			return (i);
		i++;
	}
	return (i);
}

static int	ft_find_end(char const *s, char c, int i)
{
	if (!s)
		return (0);
	while (i >= 0 && s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			return (i);
		i++;
	}
	return (i);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	if (!s)
		return (0);
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

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (str == NULL)
		return (NULL);
	while (i < (end - start + 1))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0'; 
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		end;
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(s) * (ft_count_words(s, c) + 1));
	if (arr == NULL || s == NULL)
		return (NULL);
	i = 0;
	start = ft_find_start(s, c, 0);
	while (i < ft_count_words(s, c))
	{
		printf("start: %d\t", start);
		end = ft_find_end(s, c, start);
		printf("end: %d\t", end);
		arr[i] = ft_alloc(s, start, end);
		if (arr[i] == NULL)
			return (NULL);
		printf("arr = %s\n", arr[i]);
		start = ft_find_start(s, c, end);
		i++;
	}
	arr[i] = 0;
	return (arr);
}

int main(void)
{
    // Test string
    char const *input_string = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";

    // Character to split on
    char delimiter = ' ';

    // Call the ft_split function
    char **result = ft_split(input_string, delimiter);

    // Print the result
    if (result != NULL)
    {
        int i = 0;
        while (result[i] != NULL)
        {
            printf("%s\n", result[i]);
            free(result[i]); // Don't forget to free each string
            i++;
        }

        free(result); // Don't forget to free the array of strings
    }
    else
    {
        printf("Error in ft_split\n");
    }

    return 0;
}

