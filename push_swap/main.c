/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volivier <volivier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:56:36 by volivier          #+#    #+#             */
/*   Updated: 2024/04/11 16:33:25 by volivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_list  *a;
	t_list	*b;
	int		size;
    
    if (ac < 2)
        return (0);
    if (ft_validate(ac, av) == NULL)
        return (0);
    a = get_stack(ft_validate(ac, av));
    b = (t_list *)malloc(sizeof(t_list));
    b = NULL;
    /* if (check_stack(a) == 0)
    {
        printf("doppio\n");
        return (0);
    }*/
    if (is_sorted(a) == 0)
        return (0);
    sort(&a, &b);
    /* da qui in poi lo sto usando per testare il progresso del codice */
    /* if (is_sorted(a) == 0)
    {
        printf("sorted!\n");
        while(a)
        {
            printf("%d\n", a->content);
            a = a->next;
        }
        return 0;
    }
    if (size == 2)
        sa(&a);
    while(a)
    {
        printf("%d\n", a->content);
        a = a->next;
    }
    printf("a\n");
    while(b)
    {
        printf("%d\n", b->content);
        b = b->next;
    }
    printf("b\n"); */
    free(b);
}