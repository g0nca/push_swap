/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <marvin@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:23:55 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/01/07 10:25:06 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void init_stack(t_list **stack, int ac, char **av)
{
    t_list  *new;
    char    **args;
    int     i;
    int     j;

    i = 1;
    while (i < ac)
    {
        args = ft_split(av[i], ' ');
        j = 0;
        while (args[j])
        {
            new = ft_lstnew(ft_atol(args[j]));
            ft_lstadd_back(stack, new);
            j++;
        }
        ft_free(args);
        i++;
    }
}
void    sort_stack(t_list **stack_a, t_list **stack_b)
{
    if (ft_lstsize(*stack_a) <= 5)
        simple_sort(stack_a, stack_b);
    else
        printf("ADEUS");
}

int     main(int ac, char **av)
{
    t_list **stack_a;
    t_list **stack_b;

    if(ft_checks(ac, av) == 1)
    {
        ft_error();
        return (1);
    }
    stack_a = (t_list **)malloc(sizeof(t_list));
    stack_b = (t_list **)malloc(sizeof(t_list));
    *stack_a = NULL;
    *stack_b = NULL;
    init_stack(stack_a, ac, av);
    if (is_sorted(*stack_a) == 1)
    {
        ft_lstfree(stack_a);
        ft_lstfree(stack_b);
        return (0);
    }   
    sort_stack(stack_a, stack_b);
    //printf("---> Stack_a <---\n");
    //printlist(*stack_a);
    //printf("---> Stack_b <---\n");
    printlist(*stack_b);
    ft_lstfree(stack_a);
    ft_lstfree(stack_b);
    return (0);
}
