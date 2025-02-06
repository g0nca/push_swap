/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:32 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/02/06 11:47:17 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;

	head_a = *stack_a;
	move_min_to_top(stack_a);
	ft_pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	t_list	*next_a;
	t_list	*third_elem;
	t_list	*last;

	head_a = *stack_a;
	next_a = head_a->next;
	third_elem = next_a->next;
	move_min_to_top(stack_a);
	ft_pb(stack_a, stack_b);
	move_min_to_top(stack_a);
	sort_3(stack_a);
	head_a = *stack_a;
	last = ft_lstlast(*stack_a);
	if (head_a->value > last->value || third_elem->value > last->value)
		ft_sa(stack_a);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}

void	sort_3(t_list **stack_a)
{
	t_list	*head;
	t_list	*next;
	t_list	*last;

	last = ft_lstlast(*stack_a);
	head = *stack_a;
	next = head->next;
	if (ft_checksorted(*stack_a) == 0 && head->value < next->value)
		ft_rra(stack_a);
	if (ft_checksorted(*stack_a) == 0 && head->value > last->value)
	{
		ft_ra(stack_a);
		if (ft_checksorted(*stack_a) == 0)
			ft_sa(stack_a);
	}
	if (ft_checksorted(*stack_a) == 0)
		ft_sa(stack_a);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	(void)stack_b;
	if (ft_lstsize(*stack_a) < 2)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		ft_sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
