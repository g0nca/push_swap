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

void     init_stack(t_list **stack, int ac, char **av)
{
    t_list  *new;
    char **args;
    int i;

    i = 0;
    if (ac == 2)
        args = ft_split(av[1], ' ');
    else
    {
        i = 1;
        args = av;
    }
    while (args[i])
    {
        new = ft_lstnew(ft_atoi(args[i]));
        ft_lstadd_back(stack, new);
        i++;
    }
    if (ac == 2)
        ft_free(args);
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
    printlist(*stack_a);
    ft_lstfree(stack_a);
    ft_lstfree(stack_b);

    return (0);
}
