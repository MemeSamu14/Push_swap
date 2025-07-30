/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:11:53 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/09 10:53:24 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	all_checks(int ac, char **matrix)
{
	if (input_checks(ac, matrix) == 1)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (check_dup(ac, matrix) == 1)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (exced_int(ac, matrix) == 1)
		return (ft_putstr_fd("Error\n", 2), 1);
	return (0);
}

int	input_checks(int ac, char **av)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		count = 0;
		while (av[i][j])
		{
			while (av[i][j] == '-' || av[i][j] == '+' || \
			av[i][j] == ' ')
			{
				j++;
				count++;
			}
			if (count > 1)
				return (1);
			if (ft_isdigit(av[i][j]) == 0)
				return (1);
			j++;
		}
	}
	return (0);
}

int	check_dup(int ac, char **av)
{
	int		i;
	int		j;
	long	tmp;

	i = 0;
	j = 0;
	while (i < ac)
	{
		j = i + 1;
		tmp = atol(av[i]);
		while (av[j])
		{
			if (tmp == atol(av[j]) && tmp != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	exced_int(int ac, char **av)
{
	int		i;
	int		j;
	long	tmp;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		tmp = atol(av[i]);
		while (av[j])
		{
			if (atol(av[j]) > 2147483647 || atol(av[j]) < -2147483648)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	checks(int ac, char **matrix, int *word)
{
	if (all_checks(ac, matrix) == 1)
		return (1);
	if (ac == 2)
	{
		if (check_spaces(matrix[1]) == 0)
			return (ft_putstr_fd("Error\n", 2), 1);
		matrix = ft_split(matrix[1], ' ', word);
	}
	if (all_checks(ac, matrix) == 1)
		return (free_matrix(matrix), 1);
	return (0);
}
