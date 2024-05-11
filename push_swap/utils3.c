#include "push_swap.h"

int	check_dup(char **mat)
{
	int	i;
	int	j;

	i = 0;
	while(mat[i]) //prima stringa
	{
		j = i + 1;
		while (mat[j]) //tutte le altre
		{
			if (ft_atoi(mat[i]) == ft_atoi(mat[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int free_list(t_list **stack)
{
    t_list *head;

    head = *stack;
    
    while (head)
    {
        free(head);
        head = head->next;
    }
    return (0);
}