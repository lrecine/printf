/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:17:14 by lrecine-          #+#    #+#             */
/*   Updated: 2024/10/29 14:18:25 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(va_list args, int fd, int *count)
{
	char	*str;
	int	i;

	i = 0;
	str = va_arg(args, char *);
	while (str[i])
	{
		ft_putchar_fd(str[i], fd, count);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd, int *count)
{
	write(fd, &c, 1);
	*count += 1;
}

int	ft_search(char *format, va_list args, size_t i, int *count)
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
		ft_putstr_fd(args, 1, count);
	else if (format[i + k] == 's')
		ft_putstr_fd(args, 1, count);
	else if (format[i + k] == 'p')
		ft_hexa(va_arg(args, unsigned long), format[i], count);
	else if (format[i + k] == 'd' || format[i + k] == 'i')
		ft_putnbr_fd(va_arg(args, int), 1, count);
	else if (format[i + k] == 'u')
		ft_putnbr_fd(va_arg(args, int), 1, count);
	else if (format[i + k] == 'x' || format[i + k] == 'X')
		ft_hexa(va_arg(args, unsigned long), format[i], count);
	else
		ft_putchar_fd('%', 1, count);
	return (j + k);
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
			ft_search(format, args, i, count);
			i++;
		}
		else
			ft_putchar_fd(format[i], 1, count);
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int		count;
	
	if(!format)
		return (-1);
	va_start (args, format);
	count = 0;
	ft_ispercent((char *)format, args, &count);
	va_end(args);
	return (count);
}
#include <stdio.h>
int	main(void)
{
	//%, d
	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
	printf("valor que deveria retornar : %d\n", printf("vou colocar o porcentagem aqui %% e o numero 42 %d\n", 42));
	printf("valor retornado : %d\n", ft_printf("vou colocar o porcentagem aqui %% e o numero 42 %d\n", 42));
	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
	//x, X
	printf("valor que deveria retornar : %d\n", printf("o tal do hexadecimal em minusculo, %x, e em maiusculo? %X\n", 30, 30));
	printf("valor retornado : %d\n", ft_printf("o tal do hexadecimal em minusculo, %x, e em maiusculo? %X\n", 30, 30));
	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
	//u, i, c, s
	printf("valor que deveria retornar : %d\n", printf("01%u45%i89%cbc%s\n", 23, 67, 'a', "def"));
	printf("valor retornado : %d\n", ft_printf("01%u45%i89%cbc%s\n", 23, 67, 'a', "def"));
	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
	//s
	printf("valor que deveria retornar : %d\n", printf("iscreve %s\n", "çerto"));
	printf("valor retornado : %d\n", ft_printf("iscreve %s\n", "çerto"));
	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
	//p
	printf("valor que deveria retornar : %d\n", printf("com o p: %p\n", "oi"));
	printf("valor retornado : %d\n", ft_printf("com o p: %p\n", "oi"));
	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
	return (0);
}
