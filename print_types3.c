/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_types3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:28:42 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 11:02:53 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print(long c, int fd)
{
	int	n;

	n = c % 10;
	if (c == 0)
		return ;
	c = c / 10;
	ft_print(c, fd);
	n = n + 48;
	write(fd, &n, 1);
}

void	ft_putnbr_fd(long n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_print(n * -1, fd);
	}
	else
		ft_print(n, fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
