#include "push_swap.h"

int	ft_command_two(char *command, t_list **a, t_list **b)
{
	if (ft_strncmp(command, "ra\n", ft_strlen(command)) == 0)
		return (rotate(a));
	if (ft_strncmp(command, "rb\n", ft_strlen(command)) == 0)
		return (rotate(b));
	if (ft_strncmp(command, "rr\n", ft_strlen(command)) == 0)
	{
		rotate(a);
		return (rotate(b));
	}
	if (ft_strncmp(command, "rra\n", ft_strlen(command)) == 0)
		return (rev_rotate(a));
	if (ft_strncmp(command, "rrb\n", ft_strlen(command)) == 0)
		return (rev_rotate(b));
	if (ft_strncmp(command, "rrr\n", ft_strlen(command)) == 0)
	{
		rev_rotate(b);
		return (rev_rotate(a));
	}
	return (-1);
}

int	ft_command(char *command, t_list **a, t_list **b)
{
	if (ft_strncmp(command, "sa\n", ft_strlen(command)) == 0)
		return (swap(a));
	if (ft_strncmp(command, "sb\n", ft_strlen(command)) == 0)
		return (swap(b));
	if (ft_strncmp(command, "ss\n", ft_strlen(command)) == 0)
	{
		swap(b);
		return (swap(a));
	}
	if (ft_strncmp(command, "pa\n", ft_strlen(command)) == 0)
		return (push(b, a));
	if (ft_strncmp(command, "pb\n", ft_strlen(command)) == 0)
		return (push(a, b));
	return (ft_command_two(command, a, b));
}
int	checker_loop(t_list **a, t_list **b)
{
	char	*tmp;

	while(1)
	{
		tmp = get_next_line(0);
		if (tmp == NULL)
			break ;
		if (ft_command(tmp, a, b) == -1)
		{
			write(2, "Error\n", 6);
			free_list(a);
			free_list(b);
			free(tmp);
			return (0);
		}
		free(tmp);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char    **mat;
    
    if (ac < 2)
        return (write(2, "Error\n", 6));
    mat = ft_validate(ac, av);
    if (mat == NULL)
        return (write(2, "Error\n", 6));
    a = get_stack(mat);
	if (a == NULL)
    {
        write(2, "Error\n", 6);
        return (free_list(&a));
    }
    b = (t_list *)malloc(sizeof(t_list));
    b = NULL;
	if (checker_loop(&a, &b) == 0)
		return (0);
	if (is_sorted_a(a) == 0 && lst_size(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(&a);
	free_list(&b);
}

