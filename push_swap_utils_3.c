/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:51:39 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 14:02:42 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_from_matrix(t_list **a, int ac, char **av)
{
	t_list	*new_node;
	t_list	*tmp;
	int		i;

	i = 1;
	(*a)->value = ft_atoi(av[0]);
	tmp = *a;
	while (av[i])
	{
		new_node = (t_list *)malloc(sizeof(t_list));
		if (new_node == NULL)
			return ;
		tmp->next = new_node;
		new_node->value = ft_atoi(av[i]);
		new_node->next = NULL;
		tmp = tmp->next;
		i++;
	}
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	all_in_order(t_list *a)
{
	t_list	*lst;
	int		tmp;

	if (a == NULL || a->next == NULL)
		return (1);
	lst = a;
	while (a->next != NULL)
	{
		tmp = a->value;
		a = a->next;
		if (tmp > a->value)
			return (0);
	}
	return (1);
}
