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

#include "push_swap.h"

int     ft_checks(int ac, char **av)
{
    int     i;
    int     j;
    int     control;

    control = 0;
    if (ac < 2)
    {
        ft_error();
        return (1);
    }

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
    return (control);
}
