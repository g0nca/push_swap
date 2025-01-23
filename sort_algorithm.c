#include "push_swap.h"

void    sort_5(t_list **stack_a, t_list **stack_b)
{
    t_list *head_a;

    head_a = *stack_a;
    move_min_to_top(stack_a);
    pb(stack_a, stack_b);
    sort_4(stack_a, stack_b);
}

void    sort_4(t_list **stack_a, t_list **stack_b)
{
    t_list *head_a;
    t_list *next_a;
    t_list *third_elem;
    t_list *last;

    head_a = *stack_a;
    next_a = head_a->next;
    third_elem = next_a->next;
    move_min_to_top(stack_a);
    pb(stack_a, stack_b);
    move_min_to_top(stack_a);
    pb(stack_a, stack_b);
    head_a = *stack_a;
    last = ft_lstlast(*stack_a);
    if (head_a->value > last->value || third_elem->value > last->value)
        sa(stack_a);   
    while(*stack_b)
        pa(stack_a, stack_b);
}
void    sort_3(t_list **stack_a)
{
    t_list  *head;
    t_list  *next;
    t_list  *last;

    last = ft_lstlast(*stack_a);
    head = *stack_a;
    next = head->next;
    if (head->value > next->value && next->value > last->value)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (head->value > next->value && head->value > last->value && next->value < last->value)
        ra(stack_a);
    else if (head->value > next->value && head->value > last->value && next->value > last->value)
        sa(stack_a);
    else if (head->value < next->value && head->value < last->value && next->value > last->value)
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (head->value < next->value && head->value > last->value)
        rra(stack_a);
    else if (next->value < head->value && next->value < last->value)
        sa(stack_a);
}

void    simple_sort(t_list **stack_a, t_list **stack_b)
{
    int     size;
    (void)stack_b;

    if (ft_lstsize(*stack_a) < 2)
        return ;
    size = ft_lstsize(*stack_a);
    if (size ==  2)
        sa(stack_a);
    else if (size == 3)
        sort_3(stack_a);
    else if (size == 4)
        sort_4(stack_a, stack_b);
    else if (size == 5)
        sort_5(stack_a, stack_b);

}