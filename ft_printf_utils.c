/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:52:46 by lrecine-          #+#    #+#             */
/*   Updated: 2024/10/28 14:31:54 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(unsigned long n, char c)
{
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
	}
	if (n >= 16)
		ft_hexa(n / 16, c);
	if (n % 16 < 10)
		ft_putchar_fd(n % 16 + '0', 1);
	else
	{
		if (c == 'x' || c == 'p')
			ft_putchar_fd(n % 16 + 'a' - 10, 1);
		else if (c == 'X')
			ft_putchar_fd(n % 16 + 'A' - 10, 1);
	}
}

int	ft_hexa_aux(va_list args, char *format)
{
	unsigned long	n;
	int				i;

	n = va_arg(args, unsigned long);
	i = 0;
	ft_hexa(n, format[ft_strlen(format) - 1]);
	return (i);
}

int	ft_pointer_aux(va_list args, char *format)
{
	unsigned long	n;
	int				i;

	n = va_arg(args, unsigned long);
	i = 0;
	ft_hexa(n, 'p');
	return (i);
}

int	ft_unsigned_aux(va_list args, char *format)
{
	unsigned int	n;
	int				i;

	n = va_arg(args, unsigned int);
	i = 0;
	ft_putnbr_fd(n, 1);
	return (i);
}

int	ft_int_aux(va_list args, char *format)
{
	int	n;
	int	i;

	n = va_arg(args, int);
	i = 0;
	ft_putnbr_fd(n, 1);
	return (i);
}
