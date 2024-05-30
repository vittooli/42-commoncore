/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:56:29 by volivier          #+#    #+#             */
/*   Updated: 2024/05/30 17:20:07 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_list(char **list)
{
	int		i;
	int		j;
	char	*str;

	j = -1;
	while (list[++j] != NULL)
	{
		i = 0;
		str = list[j];
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i + 1] != '\0')
				i++;
			else
				return (0);
		}
		while (str[i] != '\0')
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (0);
			i++;
		}
	}
	return (1);
}

char	**get_av(int ac, char **av)
{
	char	**mat;
	int		i;
	int		j;

	i = 1;
	j = 0;
	mat = (char **)malloc((sizeof(char *)) * ac);
	if (mat == NULL)
		return (NULL);
	while (i < ac)
	{
		mat[j] = ft_strdup(av[i]);
		i++;
		j++;
	}
	mat[j] = NULL;
	return (mat);
}

char	**ft_validate(int ac, char **av)
{
	char	**mat;

	if (ac == 2)
		mat = ft_split(av[1], 32);
	else
		mat = get_av(ac, av);
	if (!mat[0] || !av[1][0] || check_list(mat) == 0 || check_dup(mat) == 0)
	{
		free_mat(mat);
		return (NULL);
	}
	return (mat);
}

t_list	*get_stack(char **mat)
{
	int			i;
	t_list		*head;
	t_list		*node;
	long int	num;

	i = 1;
	num = ft_atoi(mat[0]);
	if (num < -2147483648 || num > 2147483647)
		return (NULL);
	head = ft_lstnew(num);
	while (mat[i] != NULL)
	{
		num = ft_atoi(mat[i]);
		if (num < -2147483648 || num > 2147483647)
		{
			free_list(&head);
			return (NULL);
		}
		node = ft_lstnew(num);
		ft_lstadd_back(&head, node);
		i++;
	}
	free_mat(mat);
	return (head);
}

int	check_stack(t_list *node)
{
	t_list	*tmp;

	while (node)
	{
		tmp = node->next;
		while (tmp)
		{
			if (node->content == tmp->content)
				return (0);
			tmp = tmp->next;
		}
		node = node->next;
	}
	return (1);
}
