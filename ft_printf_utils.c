/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:52:46 by lrecine-          #+#    #+#             */
/*   Updated: 2024/10/29 19:52:37 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(unsigned long args, char c, int *count)
{
	char			*base;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (c == 'p')
	{
		ft_putchar('0', count);
		ft_putchar('x', count);
		c = 'x';
	}
	if (args >= 16)
		ft_hexa(args / 16, c, count);
	ft_putchar(base[args % 16], count);
}

void	ft_putnbr(int args, int *count)
{
	long	nb;

	nb = args;
	if (nb < 0)
	{
		ft_putchar('-', count);
		nb = args * (-1);
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, count);
	ft_putchar((nb % 10) + '0', count);
}
