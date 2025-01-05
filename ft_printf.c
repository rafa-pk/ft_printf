/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:02:19 by raica-ba          #+#    #+#             */
/*   Updated: 2025/01/05 07:50:08 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int	printf(char *str, ...)
{
	va_list	ap;
	int		i;
	int		print_count;

	va_start(ap, str);
	i = 0;
	printed_count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			print_count += conversion_cases();
			i++;
		}
		else
		{
			print_count += putchar();
			i++;
		}
	
	}
	va_end(ap);
	return (printed_count);
}
