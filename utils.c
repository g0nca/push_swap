/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:47:38 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/02/04 15:07:10 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_free(char **str)
{
    int i;

    i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}
void    ft_error(void)
{
    ft_printf("Error\n");
}
//Check if the stack is sorted
int	ft_checksorted(t_list *stack_a)
{
	int	i;

	i = stack_a->value;
	while (stack_a)
	{
		if (i > stack_a->value)
			return (0);
		i = stack_a->value;
		stack_a = stack_a->next;
	}
	return (1);
}
//finds and returns the smallest number in the given stack.
int	ft_min(t_list *a)
{
	int		i;

	i = a->value;
	while (a)
	{
		if (a->value < i)
			i = a->value;
		a = a->next;
	}
	return (i);
}

//finds and returns the biggest number in the given stack.
int	ft_max(t_list *a)
{
	int		i;

	i = a->value;
	while (a)
	{
		if (a->value > i)
			i = a->value;
		a = a->next;
	}
	return (i);
}
void    move_min_to_top(t_list **stack)
{
    t_list *head;
    int min_value = INT_MAX;
    int min_index = 0;
    int i = 0;
    int size = ft_lstsize(*stack);
    head = *stack;
    while (head)
    {
        if (head->value < min_value)
        {
            min_value = head->value;
            min_index = i;
        }
        head = head->next;
        i++;
    }
    if (min_index <= size / 2)
        while (min_index-- > 0)
            ft_ra(stack, 0);
    else
    {
        min_index = size - min_index;
        while (min_index-- > 0)
            ft_rra(stack, 0);
    }
}
