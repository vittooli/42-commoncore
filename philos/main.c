#include <stdio.h>
#include "philos.h"

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

void	init_data(int ac, char **av, t_data *data)
{
	data->n_phils = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->n_meals = ft_atoi(av[5]);
}

int	main(int ac, char **av)
{
	t_data data;
	
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
	init_data(ac, av, &data);
	return (0);
}