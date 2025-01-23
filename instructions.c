#include "push_swap.h"

int     swap(t_list **stack)
{
    t_list  *head;
    t_list  *next;
    int     tmp_val;

    if (ft_lstsize(*stack) < 2)
        return (-1);
    head = *stack;
    next = head->next;
    if (!head && !next)
        ft_error();
    tmp_val = head->value;
    head->value = next->value;
    next->value = tmp_val;
    return (0);
}

int     sa(t_list **stack_a)
{
    if(swap(stack_a) == -1)
        return (-1);
    ft_printf("sa\n");
    return (0);
}
int     sb(t_list **stack_b)
{
    if (swap(stack_b) == -1)
        return (-1);
    ft_printf("sb\n");
    return (0);
}
int     push(t_list **stack_to, t_list **stack_from)
{
    t_list *tmp;
    t_list *head_to;
    t_list *head_from;

    if (ft_lstsize(*stack_from) == 0)
        return (-1);
    head_to = *stack_to;
    head_from = *stack_from;
    tmp = head_from;
    head_from = head_from->next;
    *stack_from = head_from;
    if (!head_to)
    {
        head_to = tmp;
        head_to->next = NULL;
        *stack_to = head_to;
    }
    else
    {
        tmp->next = head_to;
        *stack_to = tmp;
    }
    return (0);

}

int     pa(t_list **stack_a, t_list **stack_b)
{
    if (push(stack_a, stack_b) == -1)
        return (-1);
    ft_printf("pa\n");
    return (0);
}
int     pb(t_list **stack_a, t_list **stack_b)
{
    if (push(stack_b, stack_a) == -1)
        return (-1);
    ft_printf("pb\n");
    return (0);
}

int     rotate(t_list **stack)
{
    t_list *head;
    t_list *last;

    if (ft_lstsize(*stack) < 2)
        return (-1);
    head = *stack;
    last = ft_lstlast(head);
    *stack = head->next;
    head->next = NULL;
    last->next = head;
    return (0);
}

int     ra(t_list **stack_a)
{
    if (rotate(stack_a) == -1)
        return (-1);
    ft_printf("ra\n");
    return (0);
}

int     reverseRotate(t_list **stack)
{
    t_list  *head;
    t_list  *last;

    if (ft_lstsize(*stack) < 2)
        return (-1);
    head = *stack;
    last = ft_lstlast(head);
    while (head)
    {
        if (head->next->next == NULL)
        {
            head->next = NULL;
            break ;
        }
        head = head->next;
    }
    last->next = *stack;
    *stack = last;
    return (0);
    
}

int     rra(t_list **stack_a)
{
    if (reverseRotate(stack_a) == -1)
        return (-1);
    ft_printf("rra\n");
    return (0);
}