/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:48:03 by anmassy           #+#    #+#             */
/*   Updated: 2022/11/21 10:54:44 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_strlen_nbr(long nb)
{
	size_t	len;

	len = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*string;

	nb = n;
	len = ft_strlen_nbr(nb);
	string = (char *)malloc((len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	string[len--] = '\0';
	if (nb == 0)
		string[0] = '0';
	if (nb < 0)
	{
		string[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		string[len] = (nb % 10) + 48;
		nb = nb / 10;
		len--;
	}
	return (string);
}

int	ft_printnbr(int nb)
{
	int		size;
	char	*number;

	size = 0;
	number = ft_itoa(nb);
	size += ft_printstr(number);
	free(number);
	return (size);
}
