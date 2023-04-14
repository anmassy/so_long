/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:54:19 by anmassy           #+#    #+#             */
/*   Updated: 2022/11/21 10:54:50 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	len_hex(unsigned int nb)
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

static void	convert_hex(unsigned int nb, char format)
{
	char	*base;

	base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		convert_hex(nb / 16, format);
		convert_hex(nb % 16, format);
	}
	else
		ft_printchar(base[nb]);
}

int	ft_print_hex(unsigned int nb, char format)
{
	if (nb == 0)
		return (write(1, "0", 1));
	else
		convert_hex(nb, format);
	return (len_hex(nb));
}
