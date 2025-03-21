/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:20:49 by raica-ba          #+#    #+#             */
/*   Updated: 2025/01/24 15:57:39 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	base_is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if ((base[i] >= 0 && base[i] <= 32) || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	size_t	len;
	int		result;

	len = ft_strlen(base);
	result = 0;
	if (base_is_valid(base))
	{
		if (nbr >= len)
		{
			result += ft_putnbr_base(nbr / len, base);
			result += ft_putnbr_base(nbr % len, base);
		}
		else
			result += write(1, base + nbr, 1);
	}
	return (result);
}

int	ft_putnbr_ptr(uintptr_t nbr, char *base)
{
	unsigned int	result;
	size_t			len;
	char			c;

	result = 0;
	len = ft_strlen(base);
	if (nbr >= len)
	{
		result += ft_putnbr_ptr(nbr / len, base);
		result += ft_putnbr_ptr(nbr % len, base);
	}
	else
	{
		c = base[nbr];
		result += write(1, &c, 1);
	}
	return (result);
}

int	ft_put_ptr(uintptr_t ptr)
{
	int	print;

	print = 0;
	print += write(1, "0x", 2);
	if (!ptr)
		write(1, "0", 1);
	else
	{
		print += ft_putnbr_ptr(ptr, HEX_LC);
	}
	return (print);
}
