/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:55:25 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 14:02:10 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack 
// Do nothing if there is only one or no elements.
// stack a = 0; stack b = 1;
void	sa_sb(t_list *a, int stack)
{
	int	tmp;

	if (a == NULL)
		return ;
	if (a->next == NULL)
		return ;
	tmp = a->value;
	a->value = a->next->value;
	a->next->value = tmp;
	if (stack == 0)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	ss(t_list *a, t_list *b)
{
	sa_sb(a, 0);
	sa_sb(b, 1);
}

//pa (push a): Take the first element at the top of b 
//and put it at the top of a.
//Do nothing if b is empty.
void	pa(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*b == NULL)
		return ;
	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp == NULL)
		return ;
	tmp->value = (*b)->value;
	tmp->index = (*b)->index;
	tmp->next = (*a);
	tmp2 = *b;
	*b = (*b)->next;
	free(tmp2);
	(*a) = tmp;
	ft_printf("pa\n");
}

//pb (push b): Take the first element at the top 
//of a and put it at the top of b.
//Do nothing if a is empty.
void	pb(t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*a == NULL)
		return ;
	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp == NULL)
		return ;
	tmp->value = (*a)->value;
	tmp->index = (*a)->index;
	tmp->next = (*b);
	tmp2 = *a;
	*a = (*a)->next;
	free(tmp2);
	(*b) = tmp;
	ft_printf("pb\n");
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/* int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*node_a;

	a = (t_list *)malloc(sizeof(t_list));
	b = (t_list *)malloc(sizeof(t_list));
	node_a = (t_list *)malloc(sizeof(t_list));
	//node_b = (t_list *)malloc(sizeof(t_list));

//	b = NULL;

	// b->value = 7;
	// b->next = node_b;

	b = NULL;
	//node_b->value = 8;
	//node_b->next = NULL;

	a->value = 5;
	a->next = node_a;
	
	node_a->value = 6;
	node_a->next = NULL;
	print_list_a(a);
	//print_list_b(b);
	
	pa(&a, &b);

	print_list_a(a);
	//print_list_b(b);

	free_list(a);
	//free_list(b);

	return (0);
} */