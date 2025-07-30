/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 10:25:33 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 12:32:26 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//	oltre ad inserire gli index, gli inizializzo a zero, e rete
void	indexing(t_list **a, int ac)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
	tmp = *a;
	ac = count_end_list(*a);
	ac--;
	if (lowest_node(tmp)->value == tmp->value)
		sa_sb(*a, 0);
	bigger_with_no_index(tmp, ac, 1);
	while (ac > 0)
	{
		tmp = *a;
		bigger_with_no_index(tmp, ac - 1, 0);
		ac--;
	}
	tmp = *a;
	while (tmp->index == 0)
		tmp = tmp->next;
	tmp->index = ac;
	(*a)->index = count_bigger(*a);
}

// funzione che controlla se sono presenti tutti gli index
int	complete_index(t_list *a)
{
	t_list	*tmp;
	int		counter;

	tmp = a;
	counter = 0;
	while (tmp != NULL)
	{
		if (tmp->index == 0)
			counter++;
		if (tmp->index == 0 && counter == 2)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

//	mi cerca il numero piu' grande che non e' 
//	stato ancora indicizzato
void	bigger_with_no_index(t_list *a, int ac, int trip)
{
	t_list	*change_node;
	t_list	*tmp;

	tmp = a;
	change_node = lowest_node(a);
	if (trip == 0)
	{
		while (tmp != NULL)
		{
			if (change_node->value < tmp->value && tmp->index == 0)
				change_node = tmp;
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp != NULL)
		{
			if (change_node->value < tmp->value)
				change_node = tmp;
			tmp = tmp->next;
		}
	}
	change_node->index = ac;
}

t_list	*lowest_node(t_list *a)
{
	t_list	*tmp;
	t_list	*ret_node;

	tmp = a;
	ret_node = a;
	while (tmp != NULL)
	{
		if (ret_node->value > tmp->value)
			ret_node = tmp;
		tmp = tmp->next;
	}
	return (ret_node);
}

int	count_bigger(t_list *a)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = a;
	while (tmp != NULL)
	{
		if (a->value > tmp->value)
			count++;
		tmp = tmp->next;
	}
	return (count);
}
