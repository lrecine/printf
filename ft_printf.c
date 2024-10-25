/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:17:14 by lrecine-          #+#    #+#             */
/*   Updated: 2024/10/25 14:44:26 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_search(const char *format, va_list args)
{
	if (format == 'c')
		ft_putchar_fd(va_arg(args, char), 1);
	else if (format == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (format == 'p')
		ft_hexa(va_arg(args, unsigned long), 'p');
	else if (format == 'd')
		ft_hexa(va_arg(args, int), 'd');
	else if (format == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (format == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (format == 'x')
		ft_hexa(va_arg(args, unsigned int), 'x');
	else if (format == 'X')
		ft_hexa(va_arg(args, unsigned int), 'X');
	else if (format == '%')
		ft_putchar_fd('%', 1);
	return ;
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	va_start (args, format);
	int i;
	char	*str;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_search(format[i + 1], args);
		str[i] = format[i];
		i++;
	}
	str[i] = '\0';
	ft_putstr_fd(str, 1);
	return (0);
}
