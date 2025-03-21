/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:19:54 by raica-ba          #+#    #+#             */
/*   Updated: 2025/03/21 10:33:01 by raica-ba         ###   ########.fr       */
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

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (0);
	}
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

int	ft_percentage(void)
{
	write(1, "%", 1);
	return (1);
}
