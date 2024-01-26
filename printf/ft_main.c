#include "printf.h"
#include <stdio.h>

int main()
{
	char *str = "hello";
	char c = 'a';
	int				n = 7483648;
	//unsigned int	u = 4;
	char			*p;
	p = str;
	//printf("libprintf: %u", u);
	printf("\n%d\n", printf("libprintf: %c, %s, %d, %p", c, str, n, p));
	printf("\n%d", ft_printf("ft_printf: %c, %s, %d, %p", c, str, n, p));
	return (0);
}
