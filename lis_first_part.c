/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_first_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:32:03 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 12:38:20 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	ottieni il numero dei valori della sequenza di numeri piu' 
//	grande nello stack a;
//	int lis = contatore finale che deve essere returnato
int	lis(t_list **a, int tot)
{
	t_list	*lst;
	int		count;
	int		value;
	int		j;

	lst = *a;
	count = 0;
	value = count_return(&lst, tot, j);
	if (count < value)
		count = value;
	return (count);
}

int	count_return(t_list **lst, int tot, int j)
{
	t_list	*tmp;
	int		count;
	int		lis;
	int		i;
	int		first_value;

	lis = 1;
	i = 0;
	tmp = (*lst);
	while (tmp != NULL)
	{
		first_value = tmp->value;
		j = -1;
		count = 1;
		while (++j < i && tmp->next != NULL)
			tmp = tmp->next;
		count = correct_count(tmp, bigger_number(tmp, first_value), \
		first_value, &i);
		if (lis < count)
			lis = count;
		tmp = tmp->next;
	}
	return (lis);
}

int	correct_count(t_list *a, int bigs, int first_value, int *i_lis)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		count_ret;
	int		count;

	i = 0;
	count_ret = 1;
	while (i < bigs)
	{
		tmp = a;
		count = count_sequential(first_value, tmp, i, bigs);
		if (count_ret < count)
		{
			count_ret = count;
			*i_lis = i;
		}
		i++;
	}
	return (count_ret);
}

int	count_sequential(int first_value, t_list *tmp, int i, int bigs)
{
	t_list	*a;
	int		count;
	int		j;
	int		k;
	int		k_2;

	k = 0;
	count = 1;
	a = tmp;
	j = 0;
	while (a != NULL)
	{
		if (j == i && a->next != NULL && j != 0)
			a = a->next;
		if (first_value < a->value)
		{
			count++;
			first_value = a->value;
		}
		a = a->next;
		j++;
	}
	return (count);
}

//	counta quanti numeri nella lista sono piu' grandi
//	a partire dal first_value
int	bigger_number(t_list *a, int first_value)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = a;
	while (tmp != NULL)
	{
		if (first_value < tmp->value)
			count++;
		tmp = tmp->next;
	}
	return (count);
}
