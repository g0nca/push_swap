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
int     is_sorted(t_list *stack_a)
{
    while (stack_a->next)
    {
        if (stack_a->value > stack_a->next->value)
            return (0);
        stack_a = stack_a->next;
    }
    return (1);
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
            ra(stack);
    else
    {
        min_index = size - min_index;
        while (min_index-- > 0)
            rra(stack);
    }
}
