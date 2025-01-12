/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:58:26 by raica-ba          #+#    #+#             */
/*   Updated: 2025/01/12 22:38:11 by raica-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>

# define HEX_LC = "01233456789abcdef"
# define HEX_UC = "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
int		conversion_cases(char format_specifier, va_list ap);
size_t	ft_strlen(char *str);
int		ft_putchar(int c);
int		ft_putstr(char	*str);
int		ft_putnbr(int nb);
int		ft_percentage(void);
int		unsigned_length(unsigned int n);
int		base_is_valid(char *base);
void	ft_putnbr_base(int nbr, char *base);
int		ft_putnbr_ptr(uintptr_t nbr, char *base);
int		ft_put_ptr(uintptr_t nbr);
char	*unitoa(unsigned int nbr);
int		ft_putnbr_unsigned(int nbr);

#endif
