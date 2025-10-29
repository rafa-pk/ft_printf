/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:25:03 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/29 11:51:18 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long nb, int flag)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (ft_putstr("(nil)"));
	if (flag)
	{
		count += ft_putstr("0x");
		flag = 0;
	}
	if (nb >= 16)
		count += ft_putptr(nb / 16, 0);
	ft_putchar(HEX_LC[nb % 16]);
	count++;
	return (count);
}
