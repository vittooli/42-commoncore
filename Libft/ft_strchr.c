#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    if (s == NULL)
        return (NULL);
    while (s[i])
    {  
        if (s[i] == c)
            return ((char *)&s[i]); 
		i++;
    }
    if (s[i] == c)
        return ((char *)&s[i]);
    return (NULL);
}

/*int main()
{
    printf("%p",strchr("", '\0'));
    return(0);
}*/
