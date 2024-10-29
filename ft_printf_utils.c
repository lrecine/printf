/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:52:46 by lrecine-          #+#    #+#             */
/*   Updated: 2024/10/29 14:16:20 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(unsigned long args, char c, int *count)
{
	unsigned long	n;
	char			*base;

	n = args;
	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (c == 'p')
	{
		ft_putstr("0x", count);
		c = 'x';
	}
	if (n >= 16)
		ft_hexa(n / 16, c, count);
	ft_putchar_fd(base[n % 16], 1, count);
}
void	ft_putnbr_fd(int args, int fd, int *count)
{
	long	nb;

	nb = args;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd, count);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd, count);
	ft_putchar_fd(nb % 10 + '0', fd, count);
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], 1, count);
		i++;
	}
}
