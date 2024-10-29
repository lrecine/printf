/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:17:14 by lrecine-          #+#    #+#             */
/*   Updated: 2024/10/29 19:47:31 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *args, int *count)
{
	int	i;

	i = 0;
	while (args[i])
	{
		ft_putchar(args[i], count);
		i++;
	}
}

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_search(char *format, va_list args, size_t i, int *count)
{
	size_t	j;

	j = 0;
	if (args == NULL && format[i] == 's')
		ft_putstr("(null)", count);
	if (args == NULL && format[i] == 'p')
		ft_putstr("(nil)", count);
	if (format[i] == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (format[i] == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (format[i] == 'u')
		ft_putnbr(va_arg(args, unsigned int), count);
	else if (format[i] == 'x' || format[i] == 'X'
		|| format[i] == 'p')
		ft_hexa(va_arg(args, unsigned long), format[i], count);
	else
		ft_putchar('%', count);
}

void	ft_ispercent(char *format, va_list args, int *count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_search(format, args, i, count);
		}
		else
			ft_putchar(format[i], count);
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start (args, format);
	count = 0;
	ft_ispercent((char *)format, args, &count);
	va_end(args);
	return (count);
}
