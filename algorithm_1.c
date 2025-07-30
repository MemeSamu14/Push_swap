/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:20:28 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 13:58:22 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_list **a, t_list **b, int tot)
{
	t_list	*tmp;
	int		count;
	int		*array;

	count = lis(a, tot);
	array = (int *)malloc(sizeof(t_list) * count);
	if (array == NULL)
		return ;
	lis_initialize(*a, tot, array, count);
	while (is_in_a((*a)->value, array, count) == 1)
		ra_rb(a, 0);
	(*b)->value = (*a)->value;
	(*b)->index = (*a)->index;
	tmp = *a;
	*a = (*a)->next;
	free(tmp);
	ft_printf("pb\n");
	non_listed_on_b(&a, &b, array, count);
	update_cost(a, count_end_list(*a));
	update_cost(b, count_end_list(*b));
	free(array);
}

void	non_listed_on_b(t_list ***a, t_list ***b, int *array, int count)
{
	t_list	*tmp;
	int		i;
	int		k;
	int		flag;

	i = 0;
	while (count_end_list(**a) != count)
	{
		tmp = **a;
		k = 0;
		flag = 0;
		while (k < count)
		{
			if (tmp->value == array[k])
				flag = 1;
			k++;
		}
		if (flag == 0)
			pb(*a,*b);
		else
			ra_rb(*a, 0);
	}
}

int	count_end_list(t_list *a)
{
	t_list	*tmp;
	int		count;

	if (a == NULL)
		return (0);
	if (a->next == NULL)
		return (1);
	count = 0;
	tmp = a;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

void	lis_initialize(t_list *a, int tot, int *array, int count)
{
	t_list	*tmp;
	int		first_value;
	int		i;
	int		value;

	i = 0;
	tmp = a;
	while (tmp != NULL)
	{
		first_value = tmp->value;
		value = correct_count(tmp, bigger_number(tmp, \
		first_value), first_value, &i);
		if (count == value)
		{
			initialize_array(tmp, array, count, i);
			return ;
		}
		tmp = tmp->next;
	}
}

void	initialize_array(t_list *tmp, int *array, int count, int i_lis)
{
	t_list	*a;
	int		i;
	int		first_value;
	int		k;

	k = 1;
	first_value = tmp->value;
	a = tmp;
	array[0] = first_value;
	i = 0;
	while (a != NULL)
	{
		if (i_lis == i && a->next != NULL)
			a = a->next;
		if (first_value < a->value)
		{
			first_value = a->value;
			array[k] = first_value;
			k++;
		}
		i++;
		a = a->next;
	}
}
