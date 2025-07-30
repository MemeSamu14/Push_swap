/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:51:39 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 14:02:27 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize(t_list **a, int ac, char **av)
{
	t_list	*new_node;
	t_list	*tmp;
	int		i;

	i = 2;
	tmp = *a;
	while (i < ac)
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

void	update_cost(t_list	**a, int tot)
{
	int		count;
	int		second_counter;
	int		mid_point;
	int		check;
	t_list	*tmp;

	tmp = *a;
	mid_point = find_mid_point(tot, &check, &count);
	while (count < mid_point)
	{
		tmp->cost = count;
		tmp = tmp->next;
		count++;
	}
	count = (count * (-1));
	if (check == 1)
		count++;
	second_counter = 0;
	while (second_counter++ < (tot - mid_point))
	{
		tmp->cost = count;
		if (tmp->next != NULL)
			tmp = tmp->next;
		count++;
	}
}

int	find_mid_point(int tot, int *check, int *count)
{
	int	mid_point;

	*count = 0;
	if (tot % 2 == 0)
	{
		mid_point = tot / 2;
		*check = 0;
	}
	else
	{
		mid_point = tot / 2 + 1;
		*check = 1;
	}
	return (mid_point);
}

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
