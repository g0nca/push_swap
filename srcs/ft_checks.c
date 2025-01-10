/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:21:41 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/01/10 16:32:27 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_checks(int ac, char **av)
{
    (void)av;
    if (ac < 2)
    {
        ft_error();
        return (1);
    }
    else if (ac == 2)
    {
        return (1);
    }
    //else
        //ft_check_is_number(ac, av);
    return (0);
}
/*int     ft_check_is_number(int ac, char **av)
{
    int     i;
    int     j;
    int     control;

    control = 0;
    j = 1;
    i = 0;
    while (av[j][i] != '\0')
    {
        i = 0;
        while (av[j][i] != '\0')
        {
            if (!(av[j][i] >= '0' && av[j][i] <= '9'))
            {
                ft_error();
                control = 1;
            }
            i++;
        }   
        j++;
    }
}*/
