/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:26:16 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/02/05 14:44:51 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	init_index(t_list **stack)
{
	t_list	*head;
	int		index;

	head = *stack;
	while (head)
	{
		head->index = -1;
		head = head->next;
	}
	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

//Checks the index of a number
//in the stack.
int	ft_find_index(t_list *a, int value)
{
	int	i;

	i = 0;
	while (a->value != value)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

// Finds the correct place of the number in stack_b.
// In other words, it check what index number value_push will get 
// after it is being pushed to the stack_b.
int	ft_find_place_b(t_list *stack_b, int value_push)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (value_push > stack_b->value && value_push < ft_lstlast(stack_b)->value)
		i = 0;
	else if (value_push > ft_max(stack_b) || value_push < ft_min(stack_b))
		i = ft_find_index(stack_b, ft_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->value < value_push || tmp->value > value_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

// This function finds the correct place of the number in stack_a.
// In other words, it check what index number value_push will get 
// after it is being pushed to the stack_a.
int	ft_find_place_a(t_list *stack_a, int value_push)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (value_push < stack_a->value && value_push > ft_lstlast(stack_a)->value)
		i = 0;
	else if (value_push > ft_max(stack_a) || value_push < ft_min(stack_a))
		i = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->value > value_push || tmp->value < value_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
