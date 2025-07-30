/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:40:54 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 12:40:13 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*last_element(t_list *a)
{
	t_list	*ptr;

	ptr = a;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

void	print_list(t_list *ptr, int stack)
{
	if (stack == 0)
		ft_printf("Lista: a\n");
	else
		ft_printf("Lista: b\n");
	if (ptr == NULL)
		return ;
	while (ptr != NULL)
	{
		ft_printf("%d\n", ptr->value);
		ptr = ptr->next;
	}
	ft_printf("\n");
}

void	free_list(t_list *ptr)
{
	t_list	*tmp;

	if (ptr == NULL)
	{
		free(ptr);
		return ;
	}
	if (ptr->next == NULL)
	{
		free(ptr);
		return ;
	}
	tmp = ptr->next;
	while (tmp != NULL)
	{
		free(ptr);
		ptr = tmp;
		tmp = ptr->next;
	}
	free(ptr);
}

void	print_list_cost_a(t_list *ptr)
{
	ft_printf("Lista: a\n");
	if (ptr == NULL)
		return ;
	while (ptr != NULL)
	{
		ft_printf("%d| cost: %d| index: %d|\n", ptr->value, \
		ptr->cost, ptr->index);
		ptr = ptr->next;
	}
	ft_printf("\n");
}

void	print_list_cost_b(t_list *ptr)
{
	ft_printf("Lista: b\n");
	if (ptr == NULL)
		return ;
	while (ptr != NULL)
	{
		ft_printf("%d| cost: %d| index: %d|\n", ptr->value, \
		ptr->cost, ptr->index);
		ptr = ptr->next;
	}
	ft_printf("\n");
}
