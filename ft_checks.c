/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:21:41 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/01/07 11:59:37 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "push_swap.h"

int     ft_checks(int ac, char **av)
{
    if (ac < 2 || (ac == 2 && !av[1][0]))
        return (1);
    if (ft_check_is_number(ac, av) == 1)
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


/*int     ft_check_is_double(int ac, char **av)
{
    int i;
    int j;

    j = 1;
    i = 0;
    
    return (0);
}*/


/*int     ft_check_is_number_ac(int ac, char **av)
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
            if (!(av[j][i] >= '0' && av[j][i] <= '9'))
                return (1);
            i++;
        }
        j++;
    }
    return (0);
}*/