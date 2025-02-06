/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:22:51 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/02/06 11:44:18 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// ra (rotate a) : shift up all elements of stack a by 1. 
// The first element becomes the last one.
void	ft_ra(t_list **a)
{
	t_list	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

// sa (swap a) : swap the first 2 elements at the top of stack a. 
// Do nothing if there is only one or no elements).
void	ft_sa(t_list **a)
{
	t_list	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	write(1, "sa\n", 3);
}

// pa (push a) : take the first element at the top of b and 
// put it at the top of a. Do nothing if b is empty.
void	ft_pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	write(1, "pa\n", 3);
}

// rra (reverse rotate a) : shift down all elements of stack a by 1. 
// The last element becomes the first one.
void	ft_rra(t_list **a)
{
	t_list	*tmp;
	int		i;

	if (!*a || !(*a)->next)
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	write(1, "rra\n", 4);
}

// ss : sa and sb at the same time.
void	ft_ss(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	write(1, "ss\n", 3);
}
