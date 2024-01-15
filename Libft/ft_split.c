#include "libft.h"

int	ft_find_split(char const *s, char c, int i) 
//i è l'indice da cui inizia a scorrere la stringa
{
	while(s[i])
	{
		if (s[i] == c && s[i + 1] != c) 
			return (i);
		i++;
	}
	return(i);
//restituisce la posizione in cui si trova il carattere che segna lo split
}

/*-----------------------------------------------------------------*/

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;
	
	i = 0;
	words = 0;
	while (s[i])
	{
		i = ft_find_split(s, c, i);
		words++;
		i++;
	}
	if (s[i - 1] == c)
		words-= 1;
	printf("%d\n",words);
	return (words);
}

/*-----------------------------------------------------------------

char	*ft_alloc(char const *s, int start, int end)
{
	int	i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(*s) * (end - start +1));
	while(i <= (end - start))
	{
		str[i] = s[i];
		i++;
	}
	printf("%s\n",str);
	return (str);
}

*----------------------------------------------------------------

char	**ft_split(char const *s, char c)
{
	int	i;
	int	start;
	int	end;
	char **arr;
	
	arr = (char **)malloc(sizeof(s) * (ft_count_words(s, c) + 1));
	if (!arr) 
		return (NULL);
	i = 0;
	start = 0;
	while (arr[i])
	{
		end = ft_find_split(s, c, start);
		if (end != 0)
			arr[i] = ft_alloc(s, start, end);
		start = end + 1;
		i++;
	}
	arr[i] = NULL; 
	return (arr);
}

*---------------------------------------------------------------*/

int	main()
{
	//int	i;
	//char **arr;

	//i = 0;
	//arr = ft_split("lorem ipsum dolor sit amet", ' ');
	/*while(arr[i])
	{
		printf("%s", arr[i]);
		i++;
	}*/
	printf("%d", ft_count_words(" lorem ipsum dolor sit  amet ", ' '));
	return (0);
}
