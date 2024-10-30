/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:17:14 by lrecine-          #+#    #+#             */
/*   Updated: 2024/10/30 18:31:42 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *args, int *count)
{
	int	i;

	i = 0;
	if (args == NULL)
	{
		ft_putstr("(null)", count);
		return ;
	}
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
	if (format[i] == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (format[i] == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (format[i] == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), count);
	else if (format[i] == 'x' || format[i] == 'X')
		ft_hexa(va_arg(args, unsigned long), format[i], count);
	else if (format[i] == 'p')
		ft_hexa_p(va_arg(args, unsigned long), format[i], count);
	else
		ft_putchar('%', count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	size_t	i;

	if (!format)
		return (-1);
	va_start (args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_search((char*)format, args, i, &count);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>
int    main(void)
{
	char *a = (void*)-1;
	printf("valor que deveria retornar : %d\n", printf("%p\n", a));
	ft_printf("valor que deveria retornar : %d\n", ft_printf("%p\n", a));
	
	char *c = NULL;
	char *d = 0;
	//%, d
	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
	printf("valor que deveria retornar : %d\n", printf("vou colocar o porcentagem aqui %% e o numero 42 %d\n", 42));
	printf("valor retornado : %d\n", ft_printf("vou colocar o porcentagem aqui %% e o numero 42 %d\n", 42));
	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
	//s
	printf("valor que deveria retornar : %d\n", printf("iscreve %s, %s, NULL %s\n", "çerto", "", c));
	printf("valor retornado : %d\n", ft_printf("iscreve %s, %s, NULL %s\n", "çerto", "", c));
	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
	//p
	printf("valor que deveria retornar : %d\n", printf("com o p: %p, %p\n", "oi", ""));
	printf("valor retornado : %d\n", ft_printf("com o p: %p, %p\n", "oi", ""));
	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
	//x, X
	printf("valor que deveria retornar : %d\n", printf("o tal do hexadecimal em minusculo, %x, e em maiusculo? %X\n", 30, 30));
	printf("valor retornado : %d\n", ft_printf("o tal do hexadecimal em minusculo, %x, e em maiusculo? %X\n", 30, 30));
	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    //u, i, c, s
	printf("valor retornado : %d\n", printf("%i-2%u01%u45%i89%cbc%s\n", -3, -1, 23, 67, 'a', "def"));
    ft_printf("valor retornado : %d\n", ft_printf("%i-2%u01%u45%i89%cbc%s\n", -3, -1, 23, 67, 'a', "def"));
	ft_printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    printf("valor retornado : %d\n", printf("%p%p\n", c, d));
	ft_printf("valor retornado : %d\n", ft_printf("%p%p\n", c, d));
	
	return (0);
}*/
