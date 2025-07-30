/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:35:14 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/16 13:06:45 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	**matrix;
	int		word;

	if (ac > 1)
	{
		matrix = av;
		if (checks(ac, matrix, &word) == 1)
			return (1);
		a = (t_list *)malloc(sizeof(t_list));
		if (a == NULL)
			return (1);
		main_2(&a, ac, word, matrix);
		if (main_special_cases(&a, ac, word) == 1)
			return (free_list(a), 1);
		if (how_many_zero(a) > 1)
			return (free_list(a), ft_putstr_fd("Error\n", 2), 0);
		indexing(&a, ac);
		if (is_in_order(a) == 1)
			return (free_list(a), 0);
		main_3(&a, ac);
	}
	return (0);
}

void	main_2(t_list **a, int ac, int word, char **matrix)
{
	if (ac == 2)
	{
		initialize_from_matrix(a, ac, matrix);
		free_matrix(matrix);
		update_cost(a, word);
	}
	else
	{
		(*a)->value = ft_atoi(matrix[1]);
		(*a)->next = NULL;
		initialize(a, ac, matrix);
		update_cost(a, (ac - 1));
	}
}

// print_list_cost_a(*a);
void	main_3(t_list **a, int ac)
{
	t_list	*b;

	b = ft_calloc(1, sizeof(t_list));
	algorithm(a, &b, (ac - 1));
	while (count_end_list(b) != 0)
		push_on_a(a, &b, ac);
	order_list(a);
	free_list(*a);
	free_list(b);
}

int	main_special_cases(t_list **a, int ac, int word)
{
	int	flag;

	flag = 0;
	if (ac == 2)
		flag = special_cases(word, a);
	else
		flag = special_cases(ac, a);
	return (flag);
}
