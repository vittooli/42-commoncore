#include <stdio.h>

int	check_input(char **av) //verifica che gli argomenti siano degli interi
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while(av[i][j] == ' ')
			j++;
		while (av[i][j] >= 48 && av[i][j] <= 57)
			j++;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("too few args\n");
		return (0);
	}
	if (check_input(av) == 0)
	{
		printf("input not ok\n");
		return (0);
	}
	return (0);
}