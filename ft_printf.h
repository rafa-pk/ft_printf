/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz-da- <rvaz-da-@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:09:20 by rvaz-da-          #+#    #+#             */
/*   Updated: 2025/10/27 20:28:55 by rvaz-da-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define HEX_LC "0123456789abcdef"
# define HEX_UC "0123456789ABCDEF"
# define DEC "0123456789"

int	ft_printf(const char *str, ...);
int	format_spec(char fmt, va_list *ap);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_base(long long nbr, int base, char *new_base, int flag);

#endif
