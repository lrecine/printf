/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:52:46 by lrecine-          #+#    #+#             */
/*   Updated: 2024/10/25 16:54:50 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexa(unsigned long n, char c)
{
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_fd(n, 1);
	}
	else if (c == 'd')
		ft_putnbr_fd(n, 1);
	else if (c == 'x')
	{
		if (n >= 16)
			ft_hexa(n / 16, c);
		if (n % 16 < 10)
			ft_putchar_fd(n % 16 + '0', 1);
		else
			ft_putchar_fd(n % 16 + 'a' - 10, 1);
	}
	else if (c == 'X')
	{
		if (n >= 16)
			ft_hexa(n / 16, c);
		if (n % 16 < 10)
			ft_putchar_fd(n % 16 + '0', 1);
		else
			ft_putchar_fd(n % 16 + 'A' - 10, 1);
	}
}
