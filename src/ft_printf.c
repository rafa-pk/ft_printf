/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:11:16 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/27 23:20:23 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ap;

	if (!str)
		return (-1);
	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			count += format_spec(str[++i], &ap);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
