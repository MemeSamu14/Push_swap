/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:47:18 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 12:43:56 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_on_a(t_list **a, t_list **b, int ac)
{
	t_list	*tmp;
	t_cost	cost;

	tmp = *b;
	cost.total_cost = 500;
	while (tmp != NULL)
	{
		cost.tmp_cost_stack_a = count_cost_push(&a, &b, tmp->index, ac);
		cost.tmp_cost_stack_b = tmp->cost;
		if (ft_abs(cost.total_cost) > (ft_abs(cost.tmp_cost_stack_a) + \
		ft_abs(cost.tmp_cost_stack_b)))
		{
			cost.total_cost = (ft_abs(cost.tmp_cost_stack_a) + \
			ft_abs(cost.tmp_cost_stack_b));
			cost.cost_stack_a = cost.tmp_cost_stack_a;
			cost.cost_stack_b = cost.tmp_cost_stack_b;
		}
		tmp = tmp->next;
	}
	execute_moves(&a, &b, cost);
}

void	update_all_cost(t_list **a, t_list **b, int tot_a, int tot_b)
{
	update_cost(a, tot_a);
	update_cost(b, tot_b);
}

int	final_list_value(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->value);
}

int	how_many_zero(t_list *a)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = a;
	while (tmp != NULL)
	{
		if (tmp->value == 0)
			count++;
		tmp = tmp->next;
	}
	return (count);
}
