/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:32:27 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/05 11:32:05 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_check(char c, va_list lst)
{
	int	value;

	value = 0;
	if (c == 'c')
		value = print_char(va_arg(lst, int));
	if (c == 's')
		value = print_str(va_arg(lst, char *));
	if (c == 'd' || c == 'i')
		value = print_int(va_arg(lst, int));
	if (c == 'u')
		value = print_udecimal(va_arg(lst, int));
	if (c == 'p')
		value = ft_print_pointer(va_arg(lst, void *));
	if (c == 'X')
		value = print_hexadecimal_x_upper(va_arg(lst, unsigned int));
	if (c == 'x')
		value = print_hexadecimal_x_lower(va_arg(lst, unsigned int));
	if (c == '%')
		value = print_per();
	return (value);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	lst;

	if (str == NULL)
		return (-1);
	count = 0;
	i = 0;
	va_start(lst, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += arg_check(str[i + 1], lst);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

/* int	main(void)
{
	int	value;
	char	*a;

	a = NULL;

	ft_printf("ft_printf: \n");
	value = ft_printf("ciao %u\n", -3);
	ft_printf("Return value: %u\n", value);

	ft_printf("\nprintf: \n");
	value = ft_printf("ciao %u\n", -3);
	ft_printf("Return value: %u\n", value);
	
	return (0);
} 
 */
