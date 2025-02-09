/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:19 by raica-ba          #+#    #+#             */
/*   Updated: 2025/01/24 16:15:35 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	conversion_cases(char format_specifier, va_list ap)
{
	int	print;

	print = 0;
	if (format_specifier == 'c')
		print += ft_putchar(va_arg(ap, int));
	else if (format_specifier == 's')
		print += ft_putstr(va_arg(ap, char *));
	else if (format_specifier == 'p')
		print += ft_put_ptr(va_arg(ap, uintptr_t));
	else if (format_specifier == 'd' || format_specifier == 'i')
		print += ft_putnbr(va_arg(ap, int));
	else if (format_specifier == 'u')
		print += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	else if (format_specifier == 'x')
		print += ft_putnbr_base(va_arg(ap, unsigned int), HEX_LC);
	else if (format_specifier == 'X')
		print += ft_putnbr_base(va_arg(ap, unsigned int), HEX_UC);
	else if (format_specifier == '%')
		print += ft_percentage();
	return (print);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count_printed;

	va_start(ap, str);
	i = 0;
	count_printed = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count_printed += conversion_cases(str[i + 1], ap);
			i++;
		}
		else
			count_printed += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count_printed);
}
/*
int	main(void)
{
	char				c = 'r';
	char				*str = "nique chat gpt";
	void				*p = &str;
	int					n = INT_MIN;
	unsigned int		u = UINT_MAX;
	unsigned int		x = 123;
	unsigned int		X = 123;
	
	printf("real char: %c\n", c);
	ft_printf("my char: %c\n", c);

	printf("real *str: %s\n", str);
	ft_printf("my *str: %s\n", str);

	printf("real pointer: %p\n", p);
	ft_printf("my pointer: %p\n", p);

	printf("real int: %i\n", n);
	ft_printf("my int: %i\n", n);

	printf("real digit: %d\n", n);
	ft_printf("my digit: %d\n", n);

	printf("real unsigned int: %u\n", u);
	ft_printf("my unsigned int: %u\n", u);

	printf("real hexadecimal lc: %x\n", x);
	ft_printf("my hexadecimal lc: %x\n", x);

	printf("real hexadecimal uc: %X\n", X);
	ft_printf("my hexadecimal uc: %X\n", X);

	printf("real percentage: %%\n");
	ft_printf("my percentage: %%\n");	
	return (0);
}*/
