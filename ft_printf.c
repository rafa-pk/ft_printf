/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:19 by raica-ba          #+#    #+#             */
/*   Updated: 2025/01/07 19:08:00 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_cases(char format_specifier, va_list ap)
{
	int	print;

	print = 0;
	if (format_specifier == c)
		print += ft_putchar(va_arg(ap, int));
	else if (format_specifier == s)
		print += ft_putstr(va_arg(ap, char*));
	else if (format_specifier == p)
		print += function(va_arg(ap, uintptr_t));
	else if (format_specifier == d || format_specifier == i)
		print += ft_putnbr(va_arg(ap, int));
	else if (format_specifier == u)
		print += function(va_arg(ap, unsigned int));
	else if (format_specifier == x)
		print += function(va_arg(ap, unsigned int));
	else if (format_specifier == X)
		print += function(va_arg(ap, unsigned int));
	else if (format_specifier == %)
		print += ft_percentage(void);
	else
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count_printed;

	va_start(ap, str);
	i = 0;
	count_printed = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count_printed += conversion_cases(str[i + 1], ap);
			i++;
		}
		else
		{
			count_printed += putchar();
			i++;
		}
	
	}
	va_end(ap);
	return (count_printed);
}
