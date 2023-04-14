/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:58:56 by anmassy           #+#    #+#             */
/*   Updated: 2022/11/18 15:17:06 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_print_ptr(void *ptr);
int		ft_printnbr(int nb);
int		ft_printpourcent(void);
int		ft_print_unsigned_nbr(unsigned int nb);
int		ft_print_hex(unsigned int nb, char format);
int		ft_printf(const char *format, ...);

#endif