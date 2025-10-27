/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:40:55 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/27 21:57:55 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_spec(char fmt, va_list *ap)
{
	int	count;

	count = 0;
	if (fmt == 'c')
		count = ft_putchar(va_arg(*ap, int));
	else if (fmt == 's')
		count = ft_putstr(va_arg(*ap, char *));
	else if (fmt == 'p')
		count += ft_putnbr_base(va_arg(*ap, unsigned long long), 16, HEX_LC, 1);
	else if (fmt == 'd' || fmt == 'i')
		count += ft_putnbr_base(va_arg(*ap, int), 10, DEC, 0);
	else if (fmt == 'u')
		count += ft_putnbr_base(va_arg(*ap, unsigned int), 10, DEC, 0);
	else if (fmt == 'x')
		count += ft_putnbr_base(va_arg(*ap, unsigned int), 16, HEX_LC, 0);
	else if (fmt == 'X')
		count += ft_putnbr_base(va_arg(*ap, unsigned int), 16, HEX_UC, 0);
	else if (fmt == '%')
		count += ft_putchar('%');
	else
		return (-1);
	return (count);
}
