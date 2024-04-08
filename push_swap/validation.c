#include "push_swap.h"
#include <stdio.h> 

int check_list(char **list)
{
    int     i;
    int     j;
    int     sign;
    char    *str;

    j = 0;
    while(list[j] != NULL)
    {    
        i = 0;
        sign = 1;
        str = list[j];
        while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' \
                || str[i] == '\t' || str[i] == '\v' || str[i] == '\f')
            i++;
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
        j++;
    }
    return (1);
}

char **get_av(int ac, char **av)
{
    char    **mat;
    int     i;

    i = 1;
    mat = (char **)malloc((sizeof(char *)) * ac);
    if (mat == NULL)
        return (NULL);
    while (i < ac)
    {
        mat[i - 1] = ft_strdup(av[i]);
        i++;
    }
    mat[i] = NULL;
    return (mat);
}

char    **ft_validate(int ac, char **av)
{
    int i;

    char **mat;

    if (ac == 2)
        mat = ft_split(av[1], 32);
    else
        mat = get_av(ac, av);
    if(check_list(mat) == 0)
        return (NULL);
    return (mat); 
}
t_list  *get_stack(char **mat)
{
    int     i;
    t_list  *head;
    t_list  *node;

    i = 1;
    head = ft_lstnew(ft_atoi(mat[0]));
    while (mat[i] != NULL)
    {
        node = ft_lstnew(ft_atoi(mat[i]));
        ft_lstadd_back(&head, node);    
        i++;
    }
    return (head);
}

int check_stack(t_list  *node)
{
    t_list  *tmp;

    while(node)
    {
        tmp = node->next;
        while(tmp)
        {
            if (node->content == tmp->content)
                return (0);
            tmp = tmp->next;
        }
        node = node->next;
    }
    return (1);
}

int main(int ac, char **av)
{
    t_list  *node;
    
    if (ac >= 2)
    {
        //printf("%d", ft_validate(ac, av));
        if (ft_validate(ac, av) == NULL)
            return (0);
        node = get_stack(ft_validate(ac, av));
        if (check_stack(node) == 0)
        {
            printf("doppio\n");
            return (0);
        }
        while(node)
        {
            printf("%d\n", node->content);
            node = node->next;
        }
    }
}