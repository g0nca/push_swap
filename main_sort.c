/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:04:34 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/02/06 11:55:23 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_b_till_3(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*tmp;

	while (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
	{
		tmp = *stack_a;
		i = ft_rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb(*stack_a, *stack_b, tmp->value))
				i = ft_apply_rarb(stack_a, stack_b, tmp->value, 'a');
			else if (i == ft_case_rrarrb(*stack_a, *stack_b, tmp->value))
				i = ft_apply_rrarrb(stack_a, stack_b, tmp->value, 'a');
			else if (i == ft_case_rarrb(*stack_a, *stack_b, tmp->value))
				i = ft_apply_rarrb(stack_a, stack_b, tmp->value, 'a');
			else if (i == ft_case_rrarb(*stack_a, *stack_b, tmp->value))
				i = ft_apply_rrarb(stack_a, stack_b, tmp->value, 'a');
			else
				tmp = tmp->next;
		}
	}
}

// This function one by one pushes all the elements
// in stack_a to the stack_b, until only three elements
// are left in stack_a. While pushing, it makes sure if
// the stack_b is sorted. When three elements are left,
// it calls the ft_sort_three function to sort left over
// elements in stack_a.
t_list	*ft_sort_b(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		ft_pb(stack_a, &stack_b);
	if (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		ft_pb(stack_a, &stack_b);
	if (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		ft_sort_b_till_3(stack_a, &stack_b);
	if (!ft_checksorted(*stack_a))
		sort_3(stack_a);
	return (stack_b);
}

// This function is pushing back the elements from stack_b
// to stack_a until stack_b is empty. 
t_list	**ft_sort_a(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = ft_rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb_a(*stack_a, *stack_b, tmp->value))
				i = ft_apply_rarb(stack_a, stack_b, tmp->value, 'b');
			else if (i == ft_case_rarrb_a(*stack_a, *stack_b, tmp->value))
				i = ft_apply_rarrb(stack_a, stack_b, tmp->value, 'b');
			else if (i == ft_case_rrarrb_a(*stack_a, *stack_b, tmp->value))
				i = ft_apply_rrarrb(stack_a, stack_b, tmp->value, 'b');
			else if (i == ft_case_rrarb_a(*stack_a, *stack_b, tmp->value))
				i = ft_apply_rrarb(stack_a, stack_b, tmp->value, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

// This function sorts the stack_a if there are more 
// than 2 elements in the stack_a.
// And finally it makes final sort in stack_a after
// all values pushed to stack_b, sorted and pushed
// back to stack_a. Because, even the stack_a is
// sorted at the end, the minimum number have to 
// at the top of the stack_a. So, it simply brings
// the smallest number of the stack_a to the top.
void	ft_sort(t_list **stack_a)
{
	t_list	*stack_b;
	int		i;

	stack_b = NULL;
	stack_b = ft_sort_b(stack_a);
	stack_a = ft_sort_a(stack_a, &stack_b);
	i = ft_find_index(*stack_a, ft_min(*stack_a));
	if (i < ft_lstsize(*stack_a) - i)
	{
		while ((*stack_a)->value != ft_min(*stack_a))
			ft_ra(stack_a);
	}
	else
	{
		while ((*stack_a)->value != ft_min(*stack_a))
			ft_rra(stack_a);
	}
}
