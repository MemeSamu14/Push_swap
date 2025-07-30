/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:49:16 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 12:33:27 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_a(int value, int *array, int count)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < count)
	{
		if (value == array[i])
			flag = 1;
		i++;
	}
	return (flag);
}

void	order_list(t_list **a)
{
	t_list	*tmp;
	int		value;
	int		cost;
	int		i;

	tmp = *a;
	cost = 0;
	value = 500;
	while (tmp != NULL)
	{
		if (value > tmp->value)
		{
			value = tmp->value;
			cost = tmp->cost;
		}
		tmp = tmp->next;
	}
	order_list_2(&a, &cost);
}

void	order_list_2(t_list ***a, int *cost)
{
	while (*cost != 0)
	{
		if (*cost > 0)
		{
			ra_rb(*a, 0);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra_rrb(*a, 0);
			(*cost)++;
		}
	}
}

int	is_in_order(t_list *a)
{
	t_list	*tmp;
	int		value;

	tmp = a;
	value = a->value;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (value > tmp->value)
			return (0);
		value = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}
