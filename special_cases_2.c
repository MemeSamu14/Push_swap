/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:22:17 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 13:49:50 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_3_decr(t_list **b)
{
	if ((*b)->value < (*b)->next->value && \
		(*b)->next->value < (*b)->next->next->value)
	{
		sa_sb(*b, 1);
		rra_rrb(b, 1);
	}
	else if ((*b)->value < (*b)->next->value && \
		(*b)->next->value > (*b)->next->next->value && \
		(*b)->value > (*b)->next->next->value)
		sa_sb(*b, 1);
	else if ((*b)->value < (*b)->next->value && \
		(*b)->next->value > (*b)->next->next->value)
		ra_rb(b, 1);
	else if ((*b)->value > (*b)->next->value && \
		(*b)->next->value < (*b)->next->next->value && \
		(*b)->value > (*b)->next->next->value)
	{
		rra_rrb(b, 1);
		sa_sb(*b, 1);
	}
	else if ((*b)->value > (*b)->next->value && \
		(*b)->next->value < (*b)->next->next->value)
		rra_rrb(b, 1);
}

void	case_5(t_list ***a)
{
	t_list	*b;
	t_list	*lst;
	int		big;
	int		second_big;

	big = bigger_element(**a);
	second_big = second_bigger_element(**a, big);
	b = NULL;
	while (1)
	{
		lst = **a;
		if ((lst->value == big) || (lst->value == second_big) && \
		(lst->next->value == big) || (lst->next->value == second_big))
			if (lst->next->next == NULL)
				break ;
		while (((**a)->value == big) || ((**a)->value == second_big))
			ra_rb(*a, 0);
		pb(*a, &b);
	}
	case_3_decr(&b);
	if ((**a)->value > (**a)->next->value)
		sa_sb(**a, 0);
	big = -1;
	while (++big < 3)
		pa(*a, &b);
}
