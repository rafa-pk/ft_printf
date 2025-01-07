/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:19 by raica-ba          #+#    #+#             */
/*   Updated: 2025/01/07 17:38:51 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

type	conversion_cases(char format_specifier, va_list ap)
{
	int	print;

	print = 0;
	if (format_specifier == c)
		
	else if (format_specifier == s)
	else if (format_specifier == p)
	else if (format_specifier == d || format_specifier == i)
	else if (format_specifier == u)
	else if (format_specifier == x)
	else if (format_specifier == X)
	else if (format_specifier == %)
	else
}

int	printf(const char *str, ...)
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
