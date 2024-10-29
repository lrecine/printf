/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:42:45 by lrecine-          #+#    #+#             */
/*   Updated: 2024/10/29 14:00:29 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_search(char *format, va_list args, size_t i, int *count);
void	ft_ispercent(char *format, va_list args, int *count);
void	ft_hexa(va_list args, char c, int *count);
void	ft_putnbr_fd(va_list args, int fd, int *count);
void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putstr_fd(va_list args, int fd, int *count);
void	ft_putstr(char *str, int *count);

#endif