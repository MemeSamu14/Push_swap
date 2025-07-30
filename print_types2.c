/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_types2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:25:39 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 11:02:46 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_int(int nb)
{
	int		i;
	long	n;

	i = 0;
	n = nb;
	ft_putnbr_fd(n, 1);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_str(char	*str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}

int	print_per(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	print_udecimal(unsigned int nb)
{
	int			i;

	i = 0;
	ft_unsigned_print(nb, 1);
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
