/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:21:41 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/01/21 16:24:19 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_checks(int ac, char **av)
{
    if (ac < 2 || (ac == 2 && !av[1][0]))
        return (1);
    if (ft_check_is_number(ac, av) == 1)
        return (1);
    if (ft_ints(ac, av) == 1)
        return (1);
    if (ft_is_double(ac, av) == 1)
        return (1);
    return (0);
}

int     ft_check_is_number(int ac, char **av)
{
    int i;
    int j;

    j = 1;
    i = 0;
    while (j < ac)
    {
        i = 0;
        while (av[j][i])
        {
            if (av[j][i] >= '0' && av[j][i] <= '9' && av[j][i] != ' ')
                i++;
            else if ((av[j][i] == '-' || av[j][i] == '+') && (av[j][i + 1] >= '0' && av[j][i + 1] <= '9'))
                i++;
            else if (av[j][i] == ' ')
                i++;
            else
                return (1);
        }
        j++;
    }
    return (0);
}


int     ft_ints(int ac, char **av)
{
    int i;
    int j;
    char **args;
    long num;

    i = 1;
    while (i < ac)
    {
        args = ft_split(av[i], ' ');
        j = 0;
        while (args[j])
        {
            num = ft_atol(args[j]);
            if (num < INT_MIN || num > INT_MAX)
            {
                ft_free(args);    
                return (1);
            }
            j++;   
        }
        ft_free(args);
        i++;     
    }
    return (0);
}

int     ft_is_double(int ac, char **av)
{
    int i;
    int j;
    char **args;
    long num;

    i = 1;
    while (i < ac)
    {
        args = ft_split(av[i], ' ');
        j = 0;
        while (args[j])
        {
            num = ft_atol(args[j]);
            if(ft_compare(num, &args[j + 1]) == 1 || ft_compare(num, &av[i + 1]) == 1)
            {
                ft_free(args);
                return (1);
            }
            j++;   
        }
        ft_free(args);
        i++;     
    }
    return (0);
}
int     ft_compare(int n, char **args)
{
    int i;
    
    i = 0;
    while(args[i])
    {
        if (n == ft_atol(args[i]))
            return (1);
        i++;
    }
    return(0);
}
