#include "printf.h"
#include <stdio.h>

int main()
{
	char *str = "hello";
	char c = 'a';
	int				n = 7483648;
	//unsigned int	u = 4;
	//int				*p = n;
	//printf("libprintf: %u", u);
	printf("\n%d\n", printf("libprintf: %c, %s, %d", c, str, n));
	printf("\n%d", ft_printf("ft_printf: %c, %s, %d", c, str, n));
	return (0);
}
