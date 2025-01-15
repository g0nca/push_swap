/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:24:35 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/01/07 11:29:23 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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
    int     ft_atoi(const char *nptr);

#endif
