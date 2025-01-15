#include "push_swap.h"

t_list  *ft_lstnew(int value)
{
    t_list  *new;

    new = (t_list *)malloc(sizeof(*new));
    if (!new)
        return (NULL);
    new->value = value;
    new->prev = NULL;
    new->next = NULL;
    return (new);
}
t_list  *ft_lstlast(t_list *head)
{
    t_list  *tmp;

    tmp = head;
    while(tmp->next)
    {
        tmp = tmp->next;
        if (tmp->next == NULL)
            return(tmp);
    }
    return(tmp);
}
void    ft_lstfree(t_list **stack)
{
    t_list  *head;
    t_list  *tmp;

    head = *stack;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    free(stack);
}
void    ft_lstadd_back(t_list **stack, t_list *new)
{
    t_list  *n;

    if (*stack)
    {
        n = ft_lstlast(*stack);
        n->next = new;
        new->next = NULL;
    }
    else
    {
        *stack = new;
        (*stack)->next = NULL;
    }
}

void    printlist(t_list *head)
{
    t_list  *tmp;

    tmp = head;
    while (tmp != NULL)
    {
        ft_putnbr_fd(tmp->value, 1);
        ft_putendl_fd("", 1);
        tmp = tmp->next;
    }
}