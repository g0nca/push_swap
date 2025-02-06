/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <marvin@42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:23:55 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/02/05 13:08:26 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	init_stack(t_list **stack, int ac, char **av)
{
	t_list	*new;
	char	**args;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		args = ft_split(av[i], ' ');
		j = 0;
		while (args[j])
		{
			new = ft_lstnew(ft_atol(args[j]));
			ft_lstadd_back(stack, new);
			j++;
		}
		ft_free(args);
		i++;
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		ft_sort(stack_a);
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (ft_checks(ac, av) == 1)
	{
		ft_error();
		return (1);
	}
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, ac, av);
	if (ft_checksorted(*stack_a) == 1)
	{
		ft_lstfree(stack_a);
		ft_lstfree(stack_b);
		return (0);
	}
	init_index(stack_a);
	sort_stack(stack_a, stack_b);
	ft_lstfree(stack_a);
	ft_lstfree(stack_b);
	return (0);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_error(void)
{
	ft_printf("Error\n");
}
