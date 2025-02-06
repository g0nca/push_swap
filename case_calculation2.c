/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_calculation2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:27:17 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/02/05 14:41:25 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// This function calculates the required amount of rotation.
// Calculations are done for ra+rb case.
int	ft_case_rarb_a(t_list *a, t_list *b, int c)
{
	int	i;

	i = ft_find_place_a(a, c);
	if (i < ft_find_index(b, c))
		i = ft_find_index(b, c);
	return (i);
}

// This function calculates the required amount of rotation.
// Calculations are done for rra+rrb case.
int	ft_case_rrarrb_a(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, c))
		i = ft_lstsize(a) - ft_find_place_a(a, c);
	if ((i < (ft_lstsize(b) - ft_find_index(b, c))) && ft_find_index(b, c))
		i = ft_lstsize(b) - ft_find_index(b, c);
	return (i);
}

// This function calculates the required amount of rotation.
// Calculations are done for ra+rrb case.
int	ft_case_rarrb_a(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index(b, c))
		i = ft_lstsize(b) - ft_find_index(b, c);
	i = ft_find_place_a(a, c) + i;
	return (i);
}

// This function calculates the required amount of rotation.
// Calculations are done for rra+rb case.
int	ft_case_rrarb_a(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, c))
		i = ft_lstsize(a) - ft_find_place_a(a, c);
	i = ft_find_index(b, c) + i;
	return (i);
}
