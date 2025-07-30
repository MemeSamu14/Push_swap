/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:08:52 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 12:49:26 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_cost_push(t_list ***a, t_list ***b, int index, int ac)
{
	t_list	*tmp;
	int		is_present;
	int		i;

	i = 1;
	is_present = 0;
	while (i < ac)
	{
		tmp = **a;
		while (tmp != NULL)
		{
			if (tmp->index == (index + i))
			{
				is_present = 1;
				break ;
			}
			tmp = tmp->next;
		}
		if (is_present == 1)
			break ;
		i++;
	}
	if (is_present == 1)
		return (tmp->cost);
	return (count_cost_push_2(&a, is_present, index, ac));
}

int	count_cost_push_2(t_list ****a, int is_present, int index, int ac)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (i < ac)
	{
		tmp = ***a;
		while (tmp != NULL)
		{
			if (tmp->index == (index - i))
			{
				is_present = 1;
				break ;
			}
			tmp = tmp->next;
		}
		if (is_present == 1)
			break ;
		i++;
	}
	return (tmp->cost + 1);
}

void	execute_moves(t_list ***a, t_list ***b, t_cost cost)
{
	while (cost.cost_stack_a != 0 || cost.cost_stack_b != 0)
	{
		if (execute_moves_2(&a, &b, &cost) != 0)
			a = a;
		else if (cost.cost_stack_a < 0)
		{
			rra_rrb(*a, 0);
			cost.cost_stack_a++;
		}
		else if (cost.cost_stack_b > 0)
		{
			ra_rb(*b, 1);
			cost.cost_stack_b--;
		}
		else if (cost.cost_stack_b < 0)
		{
			rra_rrb(*b, 1);
			cost.cost_stack_b++;
		}
	}
	pa(*a, *b);
	update_all_cost(*a, *b, count_end_list(**a), count_end_list(**b));
}

int	execute_moves_2(t_list ****a, t_list ****b, t_cost *cost)
{
	if (cost->cost_stack_a > 0 && cost->cost_stack_b > 0)
	{
		rr(**a, **b);
		cost->cost_stack_a--;
		cost->cost_stack_b--;
		return (1);
	}
	else if (cost->cost_stack_a < 0 && cost->cost_stack_b < 0)
	{
		rrr(**a, **b);
		cost->cost_stack_a++;
		cost->cost_stack_b++;
		return (1);
	}
	else if (cost->cost_stack_a > 0)
	{
		ra_rb(**a, 0);
		cost->cost_stack_a--;
		return (1);
	}
	return (0);
}
