/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrecine- <lrecine-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:42:45 by lrecine-          #+#    #+#             */
/*   Updated: 2024/10/28 13:45:00 by lrecine-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_ispercent(char *format, va_list args);
int		ft_search(char *format, size_t i, va_list args);
int		ft_char_aux(va_list args, char *format);
int		ft_string_aux(va_list args, char *format);
void	ft_hexa(unsigned long n, char c);
int		ft_hexa_aux(va_list args, char *format);
int		ft_pointer_aux(va_list args, char *format);
int		ft_int_aux(va_list args, char *format);
int		ft_unsigned_aux(va_list args, char *format);

#endif