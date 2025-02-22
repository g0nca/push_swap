/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:24:35 by ggomes-v          #+#    #+#             */
/*   Updated: 2025/02/06 11:46:53 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;
//----------------------> push_swap.c <----------------------
int		main(int ac, char **av);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	init_stack(t_list **stack, int ac, char **av);
void	ft_error(void);
//----------------------> ft_checks.c <-----------------------
int		ft_checks(int ac, char **av);
int		ft_check_is_number(int ac, char **av);
int		ft_ints(int ac, char **av);
int		ft_is_double(int ac, char **av);
//----------------------> ft_checks_double.c  <---------------
int		ft_count_total_numbers(int ac, char **av);
char	**ft_store_numbers(int ac, char **av, int total_count);
int		ft_has_duplicate(char **args, int total_count);
//----------------------> lst.c <-----------------------------
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *head);
void	ft_lstfree(t_list **stack);
void	ft_lstadd_back(t_list **stack, t_list *new);
void	printlist(t_list *head);
//----------------------> utils.c <---------------------------
void	ft_free(char **str);
int		ft_checksorted(t_list *stack_a);
int		ft_min(t_list *a);
int		ft_max(t_list *a);
void	move_min_to_top(t_list **stack);
void	move_min_to_top2(int min_index, int size, t_list **stack);
//----------------------> main_sort.c <-----------------------
void	ft_sort(t_list **stack_a);
t_list	**ft_sort_a(t_list **stack_a, t_list **stack_b);
t_list	*ft_sort_b(t_list **stack_a);
void	ft_sort_b_till_3(t_list **stack_a, t_list **stack_b);
//---------------------> simple_sort.c <----------------------
void	simple_sort(t_list **stack_a, t_list **stack_b);
void	sort_3(t_list **stack_a);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
//---------------------> rotate_type.c <----------------------
int		ft_rotate_type_ba(t_list *a, t_list *b);
int		ft_rotate_type_ab(t_list *a, t_list *b);
//---------------------> index.c <----------------------------
void	init_index(t_list **stack);
t_list	*get_next_min(t_list **stack);
int		ft_find_index(t_list *a, int value);
int		ft_find_place_b(t_list *stack_b, int value_push);
int		ft_find_place_a(t_list *stack_a, int value_push);
//---------------------> case_calculation.c <-----------------
int		ft_case_rarb(t_list *a, t_list *b, int c);
int		ft_case_rrarrb(t_list *a, t_list *b, int c);
int		ft_case_rrarb(t_list *a, t_list *b, int c);
int		ft_case_rarrb(t_list *a, t_list *b, int c);
//---------------------> case_calculation2.c <----------------
int		ft_case_rarb_a(t_list *a, t_list *b, int c);
int		ft_case_rrarrb_a(t_list *a, t_list *b, int c);
int		ft_case_rarrb_a(t_list *a, t_list *b, int c);
int		ft_case_rrarb_a(t_list *a, t_list *b, int c);
//---------------------> apply_cases.c <----------------------
int		ft_apply_rarb(t_list **a, t_list **b, int c, char s);
int		ft_apply_rrarrb(t_list **a, t_list **b, int c, char s);
int		ft_apply_rrarb(t_list **a, t_list **b, int c, char s);
int		ft_apply_rarrb(t_list **a, t_list **b, int c, char s);
//---------------------> instructions.c <----------------------
void	ft_rr(t_list **a, t_list **b);
void	ft_rrr_sub(t_list **b);
void	ft_rrr(t_list **a, t_list **b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_rrb(t_list **b);
//---------------------> instructions2.c <---------------------
void	ft_ra(t_list **a);
void	ft_sa(t_list **a);
void	ft_pa(t_list **a, t_list **b);
void	ft_rra(t_list **a);
void	ft_ss(t_list **a, t_list **b);
//---------------------> instructions3.c <---------------------
void	ft_rb(t_list **b);
void	ft_sb(t_list **b);
//----------------------> FT_PRINTF <-------------------------
int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_pointeraddress(unsigned long n);
int		ft_putnbr(int n);
int		ft_unsigned_int(unsigned int n);
int		ft_hexadecimal(unsigned long nbr, char str);
//-----------------------> LIBFT <----------------------------
char	**ft_split(char const *s, char c);
void	free_array(char **array);
char	*if_null(char **array, int a);
char	*save_words(const char *s, char c);
int		count_words(char const *str, char c);
long	ft_atol(const char *str);
int		ft_lstsize(t_list *lst);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
#endif
