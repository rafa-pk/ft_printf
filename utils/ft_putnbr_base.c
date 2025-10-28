/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:46:59 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/28 21:38:04 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long long nb, int base, char *new_base, int flag)
{
	int	count;

	count = 0;
	if (flag && nb == 0)
		return (ft_putstr("(nil)"));
	if (nb < 0 && !flag)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (flag)
	{
		ft_putstr("0x");
		count = 2;
		flag = 0;
	}
	if ((unsigned long long)nb >= (unsigned long long)base)
		count += ft_putnbr_base((unsigned long long)nb / base,
				base, new_base, flag);
	ft_putchar(new_base[(unsigned long long)nb % base]);
	count++;
	return (count);
}
