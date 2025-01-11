/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:19:54 by raica-ba          #+#    #+#             */
/*   Updated: 2025/01/11 18:07:56 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putchar(char *str)
{
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	long int	bnb;
	int			count;

	bnb = nb;
	count = 0;
	if (bnb < 0)
	{
		count += ft_putchar('-');
		bnb = -bnb;
	}
	if (bnb >= 10)
		count += ft_putnbr(bnb / 10);
	count += ft_putchar((bnb % 10) + '0');
	return (count);
}

int	unsigned_lenght(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		n++;
	while (n != 0)
	{
		len /= 10;
		len++;
	}
	return (len);
}

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}
