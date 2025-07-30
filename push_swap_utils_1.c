/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:35:14 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 11:32:53 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigger_element(t_list *lst)
{
	t_list	*ptr;
	int		tmp;

	ptr = lst;
	tmp = ptr->value;
	while (ptr != NULL)
	{
		if (tmp < ptr->value)
			tmp = ptr->value;
		ptr = ptr->next;
	}
	return (tmp);
}

int	second_bigger_element(t_list *lst, int big)
{
	t_list	*ptr;
	int		tmp;

	ptr = lst;
	while (ptr->value == big)
		ptr = ptr->next;
	tmp = ptr->value;
	while (ptr != NULL)
	{
		if (tmp < ptr->value && ptr->value != big)
			tmp = ptr->value;
		ptr = ptr->next;
	}
	return (tmp);
}
