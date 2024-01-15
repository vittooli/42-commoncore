
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	int		i;
	int		j;

	str = (char *)malloc(sizeof(char const) * (ft_strlen((char *)s1) /
	+ ft_strlen((char *)s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int main()
{
	printf("%s", ft_strjoin("hello, ", ""));
	return (0);
}
