/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:40:46 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 12:36:24 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *ptr)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || \
	*ptr == '\v' || *ptr == '\f' || *ptr == '\r')
		ptr++;
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr >= 48 && *ptr <= 57)
	{
		res = res * 10 + (*ptr - '0');
		ptr++;
	}
	return (res * sign);
}

int	ft_atol(char *ptr)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || \
	*ptr == '\v' || *ptr == '\f' || *ptr == '\r')
		ptr++;
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr >= 48 && *ptr <= 57)
	{
		res = res * 10 + (*ptr - '0');
		ptr++;
	}
	return (res * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_abs(int n)
{
	if (n < 0)
		n = (n * -1);
	return (n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*a;
	int		i;
	char	*d;

	a = malloc(size * nmemb);
	if (a == NULL)
		return (NULL);
	d = (char *)a;
	i = 0;
	while (i < (int)size * nmemb)
	{
		d[i] = 0;
		i++;
	}
	return (a);
}
