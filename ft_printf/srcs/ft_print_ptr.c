/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:57:41 by anmassy           #+#    #+#             */
/*   Updated: 2022/11/21 16:17:05 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	len_ptr(unsigned long nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

static void	convert_ptr(unsigned long nb)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		convert_ptr(nb / 16);
		convert_ptr(nb % 16);
	}
	else
		ft_printchar(base[nb]);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	nb;
	int				len;

	nb = (unsigned long)ptr;
	len = len_ptr(nb);
	if (nb == 0)
		return (write(1, "(nil)", 5));
	else
	{
		len += write (1, "0x", 2);
		convert_ptr(nb);
	}
	return (len);
}
