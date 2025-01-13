/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:22:00 by raica-ba          #+#    #+#             */
/*   Updated: 2025/01/13 15:22:17 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char				c = 'r';
	char				*str = NULL;
	void				*p = NULL;
	int					n = 0;
	unsigned int		u = 0;
	unsigned int		x = 123;
	unsigned int		X = 123;
	
	printf("real char: %c\n", c);
	ft_printf("my char: %c\n", c);

	printf("real *str: %s\n", str);
	ft_printf("my *str: %s\n", str);

	printf("real pointer: %p\n", p);
	ft_printf("my pointer: %p\n", p);

	printf("real int: %i\n", n);
	ft_printf("my int: %i\n", n);

	printf("real digit: %d\n", n);
	ft_printf("my digit: %d\n", n);

	printf("real unsigned int: %u\n", u);
	ft_printf("my unsigned int: %u\n", u);

	printf("real hexadecimal lc: %x\n", x);
	ft_printf("my hexadecimal lc: %x\n", x);

	printf("real hexadecimal uc: %X\n", X);
	ft_printf("my hexadecimal uc: %X\n", X);

	printf("real percentage: %%\n");
	ft_printf("my percentage: %%\n");	
	return (0);
}
