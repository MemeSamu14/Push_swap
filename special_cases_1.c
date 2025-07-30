/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:19:48 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 13:46:03 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	special_cases(int ac, t_list **a)
{
	int	ret;

	ret = 0;
	if (ac == 3)
	{
		case_2(&a);
		ret = 1;
	}
	if (ac == 4)
	{
		ret = 1;
		case_3(&a);
	}
	if (ac == 5)
	{
		ret = 1;
		case_4(&a);
	}
	if (ac == 6)
	{
		case_5(&a);
		ret = 1;
	}
	return (ret);
}

void	case_2(t_list ***a)
{
	if ((**a)->value > (**a)->next->value)
		sa_sb(**a, 0);
}

void	case_3(t_list ***a)
{
	if ((**a)->value < (**a)->next->value && \
		(**a)->next->value > (**a)->next->next->value && \
		(**a)->value > (**a)->next->next->value)
		rra_rrb(*a, 0);
	else if ((**a)->value < (**a)->next->value && \
		(**a)->next->value > (**a)->next->next->value)
	{
		rra_rrb(*a, 0);
		sa_sb(**a, 0);
	}
	else if ((**a)->value > (**a)->next->value && \
		(**a)->next->value < (**a)->next->next->value && \
		(**a)->value > (**a)->next->next->value)
		ra_rb(*a, 0);
	else if ((**a)->value > (**a)->next->value && \
		(**a)->next->value < (**a)->next->next->value)
		sa_sb(**a, 0);
	else if ((**a)->value > (**a)->next->value && \
		(**a)->value > (**a)->next->next->value)
	{
		ra_rb(*a, 0);
		sa_sb(**a, 0);
	}
}

void	case_4(t_list ***a)
{
	t_list	*lst;
	t_list	*b;
	int		tmp;

	tmp = bigger_element(**a);
	while (last_element(**a)->value != tmp)
	{
		lst = **a;
		while (lst->value != tmp)
			lst = lst->next;
		if (lst->cost >= 0)
			ra_rb(*a, 0);
		else
			rra_rrb(*a, 0);
	}
	if (all_in_order(**a) == 1)
		return ;
	case4_last_part(a, b);
}

void	case4_last_part( t_list ***a, t_list *b)
{
	int	i;

	b = NULL;
	i = -1;
	while (++i < 3)
		pb(*a, &b);
	case_3_decr(&b);
	i = 0;
	while (i < 3)
	{
		pa(*a, &b);
		i++;
	}
	free_list(b);
}
