
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(const char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len || !*s)
	{
		str[i] = s[start + i],
		i++;
	}
	return (str);
}

int	main()
{
	printf("%s", ft_substr("you can't catch me, now", 0, 1));
	return (0);
}
