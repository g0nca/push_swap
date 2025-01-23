/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:24:35 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/01/23 15:02:01 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#include <stdio.h> //TIRAR ISTO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
typedef struct s_list
{
    int     value;
    struct s_list   *next;
    struct s_list   *prev;
}   t_list;
//----------------------> PUSH_SWASP <------------------------
    void    ft_error(void);
    int     ft_checks(int ac, char **av);
    int     ft_check_is_number(int ac, char **av);
    void     init_stack(t_list **stack, int ac, char **av);
    void    ft_lstadd_back(t_list **stack, t_list *new);
    t_list  *ft_lstlast(t_list *head);
    void    ft_free(char **str);
    t_list  *ft_lstnew(int value);
    void    ft_lstfree(t_list **stack);
    void    printlist(t_list *head);
    void	ft_putnbr_fd(int n, int fd);
    void	ft_putendl_fd(char *s, int fd);
    void	ft_putchar_fd(char c, int fd);  
    void	ft_putstr_fd(char *s, int fd);
    int     ft_ints(int ac, char **av);
    int     ft_is_double(int ac, char **av);
    int     ft_compare(int n, char **av);
    int     is_sorted(t_list *stack_a);
    void    simple_sort(t_list **stack_a, t_list **stack_b);
    void    move_min_to_top(t_list **stack);

    
    int     sa(t_list **stack_a);
    int     sb(t_list **stack_b);

    int     swap(t_list **stack);

    int     pa(t_list **stack_a, t_list **stack_b);
    int     pb(t_list **stack_a, t_list **stack_b);
    int     push(t_list **stack_to, t_list **stack_from);

    int     ra(t_list **stack_a);
    int     rotate(t_list **stack);

    int     rra(t_list **stack_a);
    int     reverseRotate(t_list **stack);

    void    sort_3(t_list **stack_a);
    void    sort_4(t_list **stack_a, t_list **stack_b);





//----------------------> FT_PRINTF <-------------------------
    int	ft_printf(const char *format, ...);
    int	ft_putchar(int c);
    int	ft_putstr(char *str);
    int	ft_pointeraddress(unsigned long n);
    int	ft_putnbr(int n);
    int	ft_unsigned_int(unsigned int n);
    int	ft_hexadecimal(unsigned long nbr, char str);

//-----------------------> LIBFT <----------------------------
    char	**ft_split(char const *s, char c);
    void    free_array(char **array);
    char	*if_null(char **array, int a);
    char	*save_words(const char *s, char c);
    int     count_words(char const *str, char c);
    long    ft_atol(const char *str);
    int	ft_lstsize(t_list *lst);

#endif
