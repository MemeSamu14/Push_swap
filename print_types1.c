/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_types1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:02:29 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 11:02:40 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_unsigned_print(unsigned int c, int fd)
{
	unsigned int	n;

	n = c % 10;
	if (c == 0)
		return ;
	c = c / 10;
	ft_unsigned_print(c, fd);
	n = n + 48;
	write(fd, &n, 1);
}

int	print_hexadecimal_x_lower(unsigned int nb)
{
	const char	list[] = "0123456789abcdef";
	char		str[20];
	int			i;
	int			j;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	while (nb > 0)
	{
		str[i] = list[nb % 16];
		nb = nb / 16;
		i++;
	}
	j = (i - 1);
	while (j >= 0)
	{
		write(1, &str[j], 1);
		j--;
	}
	return (i);
}

int	print_hexadecimal_x_upper(unsigned int nb)
{
	const char	list[] = "0123456789ABCDEF";
	char		str[20];
	int			i;
	int			j;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	while (nb > 0)
	{
		str[i] = list[nb % 16];
		nb = nb / 16;
		i++;
	}
	j = (i - 1);
	while (j >= 0)
	{
		write(1, &str[j], 1);
		j--;
	}
	return (i);
}

static int	print_hexadecimal_addres(unsigned long long nb)
{
	const char	list[] = "0123456789abcdef";
	char		str[20];
	int			i;
	int			j;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	while (nb > 0)
	{
		str[i] = list[nb % 16];
		nb = nb / 16;
		i++;
	}
	j = (i - 1);
	while (j >= 0)
	{
		write(1, &str[j], 1);
		j--;
	}
	return (i);
}

int	ft_print_pointer(void *point)
{
	unsigned long long	c;

	c = (unsigned long long)point;
	if (c == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (print_hexadecimal_addres(c) + 2);
}
