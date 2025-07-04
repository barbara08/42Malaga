/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin- <bmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:25:51 by bmartin-          #+#    #+#             */
/*   Updated: 2025/06/03 12:09:27 by bmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>

char	*ft_converse_base(unsigned long n, char *base_str);
int		ft_count_digit(unsigned long n, int base);
char	*ft_format_char(char specifier, va_list args);
int		ft_format_int(const char *format, int *i, va_list args);
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);

#endif
