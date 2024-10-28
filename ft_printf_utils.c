/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:52:46 by lrecine-          #+#    #+#             */
/*   Updated: 2024/10/28 16:48:30 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(unsigned long n, char c)
{
	char	*base;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		c = 'x';
	}
	if (n >= 16)
		ft_hexa(n / 16, c);
	ft_putchar_fd(base[n % 16], 1);
}

int	ft_hexa_aux(va_list args, char *format)
{
	unsigned long	n;
	int				i;

	n = va_arg(args, unsigned long);
	i = 0;
	while (n > 16)
	{
		n /= 16;
		i++;
	}
	n = va_arg(args, unsigned long);
	ft_hexa(n, format[+1]);
	return (i);
}

int	ft_pointer_aux(va_list args, char *format)
{
	unsigned long	n;

	n = va_arg(args, unsigned long);
	ft_hexa(n, format[+1]);
	return (1);
}

int	ft_unsigned_aux(va_list args, char *format)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ft_putnbr_fd(n, 1);
	return (1);
}

int	ft_int_aux(va_list args, char *format)
{
	int	n;

	n = va_arg(args, int);
	ft_putnbr_fd(n, 1);
	return (1);
}
