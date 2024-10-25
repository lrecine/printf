/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:17:14 by lrecine-          #+#    #+#             */
/*   Updated: 2024/10/25 20:19:34 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search(const char *format, size_t i, va_list args)
{
	size_t	j;
	size_t	k;

	k = 1;
	while (format[i + k] != 'c' && format[i + k] != 's' && format[i + k] != 'p' 
			&& format[i + k] != 'd' && format[i + k] != 'i' && format[i + k] != 'u' 
			&& format[i + k] != 'x' && format[i + k] != 'X' && format[i + k] != '%')
		k++;
	j = 0;
	if (format[i + k] == 'c')
		j += ft_char_aux(args, &format[i]);
	else if (format[i + k] == 's')
		j += ft_string_aux(args, &format[i]);
	else if (format[i + k] == 'p')
		j += ft_pointer_aux(args, &format[i]);
	else if (format[i + k] == 'd' || format[i + k] == 'i')
		j += ft_int_aux(args, &format[i]);
	else if (format[i + k] == 'u')
		j += ft_unsigned_aux(args, &format[i]);
	else if (format[i + k] == 'x' || format[i + k] == 'X')
		j += ft_hexa_aux(args, &format[i]);
	else
		ft_putchar_fd('%', 1);
	k--;
	return (j - k);
}

int	ft_ispercent(const char *format, va_list args)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			j += ft_search(format, i, args);
			if (format[i + 1] == '%')
				j++;
			i++;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	return(i + j);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int		i;
	
	if(!format)
		return (-1);
	va_start (args, format);
	i = ft_ispercent(args, (char *)format);
	va_end(args);
	return (i);
}
#include <stdio.h>
int	main(void)
{
	//%, d
	ft_printf("vou colocar o porcentagem aqui %% e o numero 42 %d\n", 42);
	printf("R = \nvou colocar o porcentagem aqui %% e o numero 42 %d\n", 42);
	//x, X
	ft_printf("o tal do hexadecimal em minusculo, ta? %x, e em maiusculo? %X\n", 329478, 329478);
	printf("R = \no tal do hexadecimal em minusculo, ta? %x, e em maiusculo? %X\n", 329478, 329478);
	//u, i, c, s
	ft_printf("01 %u45 %i89 %cbc %s\n", 23, 67, 'a', "def");
	printf("R = \n01 %u45 %i89 %cbc %s\n", 23, 67, 'a', "def");
	//s
	ft_printf("iscreve %s\n", "çerto");
	printf("R = \niscreveu %s\n", "çerto");

	return (0);
}
