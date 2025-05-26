/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:50:39 by raica-ba          #+#    #+#             */
/*   Updated: 2025/05/26 16:50:47 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putptr(unsigned long long int n, char *base, int flag)
{
	int	count;
	int	remainder;

	count = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	if (flag != 1)
	{
		write(1, "0x", 2);
		count = 2;
		flag = 1;
	}
	if (n >= 16)
		count += ft_putptr(n / 16, base, flag);
	remainder = (n % 16);
	write(1, &base[remainder], 1);
	count++;
	return (count);
}

int	ft_putnbr_base(long nbr, int lbase, char *base)
{
	int	count;
	int	remainder;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= lbase)
		count += ft_putnbr_base(nbr / lbase, lbase, base);
	remainder = nbr % lbase;
	write(1, &base[remainder], 1);
	count++;
	return (count);
}
