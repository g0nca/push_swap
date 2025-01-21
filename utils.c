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