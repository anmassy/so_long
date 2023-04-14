/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:57:40 by anmassy           #+#    #+#             */
/*   Updated: 2022/11/21 10:54:29 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	len_nb(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*ft_unsigned_itoa(unsigned int nb)
{
	char	*number;
	int		len;

	len = len_nb(nb);
	number = (char *)malloc((len + 1) * sizeof(char));
	if (!number)
		return (NULL);
	number[len--] = '\0';
	while (nb > 0)
	{
		number[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (number);
}

int	ft_print_unsigned_nbr(unsigned int nb)
{
	int		size;
	char	*number;

	size = 0;
	if (nb == 0)
		size += write(1, "0", 1);
	else
	{
		number = ft_unsigned_itoa(nb);
		size += ft_printstr(number);
		free(number);
	}
	return (size);
}
