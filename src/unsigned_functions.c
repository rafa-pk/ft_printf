/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 23:15:29 by raica-ba          #+#    #+#             */
/*   Updated: 2025/01/12 23:17:13 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_length(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		n++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*unitoa(unsigned int nbr)
{
	int		len;
	char	*conversion;

	len = unsigned_length(nbr);
	conversion = (char *)malloc(sizeof(char) * (len + 1));
	if (!conversion)
		return (NULL);
	conversion[len] = '\0';
	if (nbr == 0)
	{
		conversion[0] = '0';
		return (conversion);
	}
	while (nbr != 0)
	{
		conversion[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (conversion);
}

int	ft_putnbr_unsigned(int nbr)
{
	char	*num;
	int		len;

	len = 0;
	if (nbr == 0)
	{
		len = ft_putchar('0');
	}
	else
	{
		num = ft_unitoa(nbr);
		if (num)
		{
			len = ft_putstr(num);
			free(num);
		}
	}
	return (len);
}
