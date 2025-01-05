/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:19 by raica-ba          #+#    #+#             */
/*   Updated: 2025/01/05 08:14:06 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

type	conversion_cases(char format_specifier, va_list ap)
{
	if (format_specifier == c)
	{
		va_arg(ap, char);
	}
	else if (format_specifier == s)
	{
		va_arg(ap, char*)
	}
	else if (format_specifier == p)
	{

	}
	else if (format_specifier == d || format_specifier == i)
	{
		va_arg(ap, int);
	}
	else if (format_specifier == u)
	{

	}
	else if (format_specifier == x)
	{

	}
	else if (format_specifier == X)
	{

	}
	else if (format_specifier == %)
	{

	}
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
			count_printed += conversion_cases(str[i + 1]);
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
