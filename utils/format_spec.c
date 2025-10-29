/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:40:55 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/29 11:46:00 by rvaz-da-         ###   ########.fr       */
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
		count += ft_putptr(va_arg(*ap, unsigned long long), 1);
	else if (fmt == 'd' || fmt == 'i')
		count += ft_putnbr_base(va_arg(*ap, int), 10, DEC);
	else if (fmt == 'u')
		count += ft_putnbr_base(va_arg(*ap, unsigned int), 10, DEC);
	else if (fmt == 'x')
		count += ft_putnbr_base(va_arg(*ap, unsigned int), 16, HEX_LC);
	else if (fmt == 'X')
		count += ft_putnbr_base(va_arg(*ap, unsigned int), 16, HEX_UC);
	else if (fmt == '%')
		count += ft_putchar('%');
	else
		return (-1);
	return (count);
}
