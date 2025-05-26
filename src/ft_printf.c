/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:51:03 by raica-ba          #+#    #+#             */
/*   Updated: 2025/05/26 16:51:05 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, str);
	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count += conversions(str[i + 1], &ap);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

int	conversions(char format_specifier, va_list *ap)
{
	int	conv_count;

	conv_count = 0;
	if (format_specifier == 'c')
		conv_count += ft_putchar(va_arg(*ap, int));
	else if (format_specifier == 's')
		conv_count += ft_putstr(va_arg(*ap, char *));
	else if (format_specifier == 'p')
		conv_count += ft_putptr(va_arg(*ap, unsigned long long), HEX_UC, 0);
	else if (format_specifier == 'd' || format_specifier == 'i')
		conv_count += ft_putnbr_base(va_arg(*ap, int), 10, "0123456789");
	else if (format_specifier == 'u')
		conv_count += ft_putnbr_base(va_arg(*ap, unsigned int), 10,
				"0123456789");
	else if (format_specifier == 'x')
		conv_count += ft_putnbr_base(va_arg(*ap, unsigned int), 16, HEX_LC);
	else if (format_specifier == 'X')
		conv_count += ft_putnbr_base(va_arg(*ap, unsigned int), 16, HEX_UC);
	else if (format_specifier == '%')
		conv_count += ft_putchar('%');
	return (conv_count);
}

/*int	main(void)
{
	char	c = 'z';
	char	*str = "zoe c'est la meilleure du monde";
	void	*ptr = &str;
	int		n = INT_MIN;
	int		age = 19;
	unsigned int	u = UINT_MAX;
	unsigned int	x = 123;
	unsigned int	code_ipad = 250900;
	unsigned int	X = 123;

	printf("real char: %c\n", c);
	ft_printf("my char: %c\n\n", c);

	printf("real str: %s\n", str);
	ft_printf("my str: %s\n\n", str);

	printf("real ptr: %p\n", ptr);
	ft_printf("my ptr: %p\n\n", ptr);

	printf("real digit: %d\n", n);
	ft_printf("my digit: %d\n\n");

	printf("real unsigned int: %u\n", u);
	ft_printf("my unsigned int: %u\n\n", u);

	printf("real hex lowercase: %x\n", x);
	ft_printf("my hex lowercase: %x\n\n", x);

	printf("real hex uppercase: %X\n", X);
	ft_printf("my hex uppercase: %X\n\n", X);

	printf("real percentage: %%\n");
	ft_printf("my percentage: %%\n\n");

	printf(" %c %c %c\n ", '0', 0, '1');
	ft_printf(" %c %c %c\n ", '0', 0, '1');

	printf("la premiere lettre dans le prenom zoe c'est: %c, elle a %d ans, et le code de son ipad en hexadecimal c'est: %x\n\n", c, age, code_ipad);
	ft_printf("la premiere lettre dans le prenom zoe c'est: %c, elle a %d ans, et le code de son ipad en hexadecimal c'est: %x\n\n", c, age, code_ipad);

	return (0);
}*/
