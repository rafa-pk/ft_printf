/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raica-ba <raica-ba@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:58:26 by raica-ba          #+#    #+#             */
/*   Updated: 2025/01/07 19:07:36 by raica-ba         ###   ########.fr       */
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

int		ft_printf(const char *str, ...);
int		conversion_cases(char format_specifier, va_list ap);
size_t	ft_strlen(char*);
int		ft_putchar(int c);
int		ft_putstr(char	*str);
int		ft_putnbr(int nb);
int		ft_percent(void);

#endif
