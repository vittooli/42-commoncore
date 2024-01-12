#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
    size_t	i;
	char	*str;

	str = (char	*)s;
    i = 0;
	if (s == NULL)
		return (NULL);
	while (i < n)
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

int main()
{
    printf("%c",*(char *)(ft_memchr("castoro", 'r', 7)));
    return(0);
}
