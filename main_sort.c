/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:04:34 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/02/04 13:29:32 by ggomes-v         ###   ########.fr       */
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
		ft_pb(stack_a, &stack_b, 0);
	if (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
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
	if (ft_lstsize(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		i = ft_find_index(*stack_a, ft_min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->value != ft_min(*stack_a))
				ft_ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->value != ft_min(*stack_a))
				ft_rra(stack_a, 0);
		}
    }
}



/*//===============================================================================
// This function calculate and decides which rotation
// combination is best to use to sort the stack. Of
// course, after rotation there is always one push
// operation is left to do which i embeded to code.
// Function is used during push from B to A.
int	ft_rotate_type_ba(t_list *a, t_list *b)
{
	int		i;
	t_list	*tmp;

	tmp = b;
	i = ft_case_rrarrb_a(a, b, b->value);
	while (tmp)
	{
		if (i > ft_case_rarb_a(a, b, tmp->value))
			i = ft_case_rarb_a(a, b, tmp->value);
		if (i > ft_case_rrarrb_a(a, b, tmp->value))
			i = ft_case_rrarrb_a(a, b, tmp->value);
		if (i > ft_case_rarrb_a(a, b, tmp->value))
			i = ft_case_rarrb_a(a, b, tmp->value);
		if (i > ft_case_rrarb_a(a, b, tmp->value))
			i = ft_case_rrarb_a(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}

// This function calculate and decides which rotation
// combination is best to use to sort the stack. Of
// course, after rotation there is always one push
// operation is left to do which i embeded to code.
// Function is used during push from A to B.
int	ft_rotate_type_ab(t_list *a, t_list *b)
{
	int		i;
	t_list	*tmp;

	tmp = a;
	i = ft_case_rrarrb(a, b, a->value);
	while (tmp)
	{
		if (i > ft_case_rarb(a, b, tmp->value))
			i = ft_case_rarb(a, b, tmp->value);
		if (i > ft_case_rrarrb(a, b, tmp->value))
			i = ft_case_rrarrb(a, b, tmp->value);
		if (i > ft_case_rarrb(a, b, tmp->value))
			i = ft_case_rarrb(a, b, tmp->value);
		if (i > ft_case_rrarb(a, b, tmp->value))
			i = ft_case_rrarb(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}*/

//====================================================================
/*int	ft_apply_rarb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c && ft_find_place_b(*b, c) > 0)
			ft_rr(a, b, 0);
		while ((*a)->value != c)
			ft_ra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b)->value != c && ft_find_place_a(*a, c) > 0)
			ft_rr(a, b, 0);
		while ((*b)->value != c)
			ft_rb(b, 0);
		while (ft_find_place_a(*a, c) > 0)
			ft_ra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

// This function rotate both stack_a and stack_b in the
// reverse direction as required amount.
int	ft_apply_rrarrb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c && ft_find_place_b(*b, c) > 0)
			ft_rrr(a, b, 0);
		while ((*a)->value != c)
			ft_rra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b)->value != c && ft_find_place_a(*a, c) > 0)
			ft_rrr(a, b, 0);
		while ((*b)->value != c)
			ft_rrb(b, 0);
		while (ft_find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

// This function rotate the stack_a in reverse direction,
// the stack_b in oppsite direction of stack_a as required amount.
int	ft_apply_rrarb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			ft_rra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		while ((*b)->value != c)
			ft_rb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

// This function rotate the stack_b in reverse direction,
// the stack_a in oppsite direction of stack_a as required amount.
int	ft_apply_rarrb(t_list **a, t_list **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->value != c)
			ft_ra(a, 0);
		while (ft_find_place_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_ra(a, 0);
		while ((*b)->value != c)
			ft_rrb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}*/
/*//====================================================================
// This function calculates how many times 
// we should rotate the stacks together.
// Because after a certain amoun of rotate, we will
// proceed only with one stack rotation.
int	ft_case_rarb(t_list *a, t_list *b, int c)
{
	int	i;

	i = ft_find_place_b(b, c);
	if (i < ft_find_index(a, c))
		i = ft_find_index(a, c);
	return (i);
}

// This function calculates how many times we should rotate the stacks together.
// Because after a certain amoun of rotate, we will proceed only with one stack
// rotation. Since here we have reverse rotate,rather than index number,
// we check reverse index number which is 
// calculated by list_size - index_number.
int	ft_case_rrarrb(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = ft_lstsize(b) - ft_find_place_b(b, c);
	if ((i < (ft_lstsize(a) - ft_find_index(a, c))) && ft_find_index(a, c))
		i = ft_lstsize(a) - ft_find_index(a, c);
	return (i);
}

// Again, this function makes similar calculations.
// This function do same calculations for rra+rb case.
int	ft_case_rrarb(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index(a, c))
		i = ft_lstsize(a) - ft_find_index(a, c);
	i = ft_find_place_b(b, c) + i;
	return (i);
}

// Again, this function makes similar calculations.
// This function do same calculations for ra+rrb case.
int	ft_case_rarrb(t_list *a, t_list *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = ft_lstsize(b) - ft_find_place_b(b, c);
	i = ft_find_index(a, c) + i;
	return (i);
}*/
//======================================================================

// This function calculates the required amount of rotation.
// Calculations are done for ra+rb case.
/*int	ft_case_rarb_a(t_list *a, t_list *b, int c)
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
}*/

//=======================================================================
// rr : ra and rb at the same time
/*void	ft_rr(t_list **a, t_list **b, int j)
{
	t_list	*tmp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	tmp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rr\n", 3);
}

// Second part of the rrr function
void	ft_rrr_sub(t_list **b, int j)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		write(1, "rrr\n", 4);
}

// rrr : rra and rrb at the same time.
void	ft_rrr(t_list **a, t_list **b, int j)
{
	t_list	*tmp;
	int		i;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		i++;
		*a = (*a)->next;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	ft_rrr_sub(b, j);
}

// pb (push b) : take the first element at the top of a and put it 
// at the top of b. Do nothing if a is empty.
void	ft_pb(t_list **stack_a, t_list **stack_b, int j)
{
	t_list	*tmp;

	if (!*stack_a)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (j == 0)
		write(1, "pb\n", 3);
}

// rrb (reverse rotate b) : shift down all elements of stack b by 1. 
// The last element becomes the first one.
void	ft_rrb(t_list **b, int j)
{
	t_list	*tmp;
	int		i;

	if (!*b || !(*b)->next)
		return ;
	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		write(1, "rrb\n", 4);
}*/

//================================================================

// ra (rotate a) : shift up all elements of stack a by 1. 
// The first element becomes the last one.
/*void	ft_ra(t_list **a, int j)
{
	t_list	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "ra\n", 3);
}

// sa (swap a) : swap the first 2 elements at the top of stack a. 
// Do nothing if there is only one or no elements).
void	ft_sa(t_list **a, int j)
{
	t_list	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "sa\n", 3);
}

// pa (push a) : take the first element at the top of b and 
// put it at the top of a. Do nothing if b is empty.
void	ft_pa(t_list **a, t_list **b, int j)
{
	t_list	*tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (j == 0)
		write(1, "pa\n", 3);
}

// rra (reverse rotate a) : shift down all elements of stack a by 1. 
// The last element becomes the first one.
void	ft_rra(t_list **a, int j)
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
	if (j == 0)
		write(1, "rra\n", 4);
}

// ss : sa and sb at the same time.
void	ft_ss(t_list **a, t_list **b, int j)
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
	if (j == 0)
		write(1, "ss\n", 3);
}*/
//=========================================================
// rb (rotate b) : shift up all elements of stack b by 1. 
// The first element becomes the last one.
/*void	ft_rb(t_list **b, int j)
{
	t_list	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
}

// sb (swap b) : swap the first 2 elements at the top of stack b. 
// Do nothing if there is only one or no elements).
void	ft_sb(t_list **b, int j)
{
	t_list	*tmp;

	if (!*b || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (j == 0)
		write(1, "sb\n", 3);
}*/

//====================================================================
// This function checks the index of a number
// 	 in the stack.
/*int	ft_find_index(t_list *a, int value)
{
	int		i;

	i = 0;
	while (a->value != value)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}

// This function finds the correct place of the number in stack_b.
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
}*/
//======================================================================
/*// This function finds and returns the smallest number
// in the given stack.
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

// This function finds and returns the biggest number
// in the given stack.
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
}*/
//====================================================================
/*int	ft_checksorted(t_list *stack_a)
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
}*/