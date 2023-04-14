/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:04:32 by anmassy           #+#    #+#             */
/*   Updated: 2022/11/21 10:37:40 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	find_the_value(va_list args, const char format)
{
	int	value;

	value = 0;
	if (format == 'c')
		value += ft_printchar(va_arg(args, int));
	else if (format == 's')
		value += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		value += ft_print_ptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		value += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		value += ft_print_unsigned_nbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		value += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		value += ft_printpourcent();
	return (value);
}

int	ft_printf(const char *strings, ...)
{
	va_list	args;
	int		i;
	int		value;

	i = 0;
	value = 0;
	va_start(args, strings);
	while (strings[i])
	{
		if (strings[i] == '%')
		{
			value += find_the_value(args, strings[i + 1]);
			i++;
		}
		else
			value += ft_printchar(strings[i]);
		i++;
	}
	va_end(args);
	return (value);
}
