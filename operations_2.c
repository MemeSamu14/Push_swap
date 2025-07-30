/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:25:46 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 13:43:44 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements of stack a by 1.
// The first element becomes the last one
void	ra_rb(t_list **a, int stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*a == NULL)
		return ;
	tmp = *a;
	tmp2 = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = tmp2;
	*a = tmp2->next;
	tmp2->next = NULL;
	if (stack == 0)
		ft_printf("ra\n");
	else if (stack == 1)
		ft_printf("rb\n");
}

//  ra and rb at the same time
void	rr(t_list **a, t_list **b)
{
	ra_rb(a, 2);
	ra_rb(b, 2);
	ft_printf("rr\n");
}

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
void	rra_rrb(t_list **a, int stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*a == NULL)
		return ;
	tmp = *a;
	while (tmp->next != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp2->next = NULL;
	tmp->next = *a;
	*a = tmp;
	if (stack == 0)
		ft_printf("rra\n");
	else if (stack == 1)
		ft_printf("rrb\n");
}

//rra and rrb at the same time.
void	rrr(t_list **a, t_list **b)
{
	rra_rrb(a, 2);
	rra_rrb(b, 2);
	ft_printf("rrr\n");
}
