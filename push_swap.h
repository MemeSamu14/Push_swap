/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:50:06 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 14:04:38 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				cost;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_cost
{
	int	cost_stack_a;
	int	cost_stack_b;
	int	tmp_cost_stack_a;
	int	tmp_cost_stack_b;
	int	total_cost;
}	t_cost;

//printf
int		ft_printf(const char *str, ...);
int		arg_check(char c, va_list lst);
int		print_int(int nb);
int		print_char(int c);
int		print_str(char *str);
int		print_per(void);
int		print_udecimal(unsigned int nb);
int		print_hexadecimal_x_lower(unsigned int nb);
int		print_hexadecimal_x_upper(unsigned int nb);
int		ft_print_pointer(void *point);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(long n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_unsigned_print(unsigned int nb, int fd);
//	operations_1
void	sa_sb(t_list *a, int stack);
void	ss(t_list *a, t_list *b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
//	operations_2
void	ra_rb(t_list **a, int stack);
void	rr(t_list **a, t_list **b);
void	rra_rrb(t_list **a, int stack);
void	rrr(t_list **a, t_list **b);
//	push_swap_utils_1
int		bigger_element(t_list *lst);
int		second_bigger_element(t_list *lst, int big);
//	push_swap_utils_2
void	initialize(t_list **a, int ac, char **av);
void	update_cost(t_list	**a, int tot);
int		find_mid_point(int tot, int *check, int *count);
int		check_spaces(char *str);
//	push_swap_utils_3
void	initialize_from_matrix(t_list **a, int ac, char **av);
void	free_matrix(char **matrix);
int		all_in_order(t_list *a);
//	libft_utils
int		ft_atoi(char *ptr);
int		ft_atol(char *ptr);
int		ft_isdigit(int c);
int		ft_abs(int n);
void	*ft_calloc(size_t nmemb, size_t size);
//	input_checks
int		all_checks(int ac, char **matrix);
int		check_dup(int ac, char **av);
int		input_checks(int ac, char **av);
int		exced_int(int ac, char **av);
int		checks(int ac, char **matrix, int *word);
//	special cases
int		special_cases(int ac, t_list **a);
void	case_2(t_list ***a);
void	case_3(t_list ***a);
void	case_4(t_list ***a);
void	case4_last_part( t_list ***a, t_list *b);
//special cases 2
void	case_3_decr(t_list **b);
void	case_5(t_list ***a);
//split
char	**ft_split(char *s, char c, int *word);
// list utils
t_list	*last_element(t_list *a);
void	print_list(t_list *ptr, int stack);
void	free_list(t_list *ptr);
void	print_list_cost_a(t_list *ptr);
void	print_list_cost_b(t_list *ptr);
//	algorithm
void	algorithm(t_list **a, t_list **b, int tot);
void	non_listed_on_b(t_list ***a, t_list ***b, int *array, int count);
int		count_end_list(t_list *a);
void	lis_initialize(t_list *a, int tot, int *array, int count);
void	initialize_array(t_list *tmp, int *array, int count, int i_lis);
// lis_first_part
int		bigger_number(t_list *a, int first_value);
int		lis(t_list **a, int tot);
int		count_return(t_list **lst, int tot, int j);
int		count_sequential(int first_value, t_list *tmp, int i, int bigs);
void	algorithm(t_list **a, t_list **b, int tot);
int		correct_count(t_list *a, int bigs, int first_value, int *i_lis);
//	algorithm_2
void	push_on_a(t_list **a, t_list **b, int ac);
int		final_list_value(t_list *a);
int		count_cost_push(t_list ***a, t_list ***b, int index, int ac);
void	execute_moves(t_list ***a, t_list ***b, t_cost cost);
void	update_all_cost(t_list **a, t_list **b, int tot_a, int tot_b);
void	order_list(t_list **a);
int		is_in_order(t_list *a);
//	algorithm 3
void	indexing(t_list **a, int ac);
int		complete_index(t_list *a);
void	bigger_with_no_index(t_list *a, int ac, int trip);
t_list	*lowest_node(t_list *a);
int		count_bigger(t_list *a);
int		how_many_zero(t_list *a);
int		is_in_a(int value, int *array, int count);
int		execute_moves_2(t_list ****a, t_list ****b, t_cost *cost);
int		count_cost_push_2(t_list ****a, int is_present, int index, int ac);
void	order_list_2(t_list ***a, int *cost);
void	ft_putstr_fd(char *s, int fd);
void	main_2(t_list **a, int ac, int word, char **matrix);
int		main_special_cases(t_list **a, int ac, int word);
void	main_3(t_list **a, int ac);

#endif