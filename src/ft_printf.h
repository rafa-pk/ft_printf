/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:51:19 by raica-ba          #+#    #+#             */
/*   Updated: 2025/05/26 16:51:30 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H 
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

# define HEX_LC "0123456789abcdef"
# define HEX_UC "0123456789ABCDEF"

int	ft_printf(const char *str, ...);
int	conversions(char format_specifier, va_list *ap);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putptr(unsigned long long int n, char *base, int flag);
int	ft_putnbr_base(long nbr, int lbase, char *base);

#endif
