/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:41:17 by aasselma          #+#    #+#             */
/*   Updated: 2022/11/01 15:28:12 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_ots(char frmt, va_list ap)
{
	int		x;

	x = 0;
	if (frmt == 'c')
		x += ft_putchar(va_arg(ap, int));
	if (frmt == 's')
		x += ft_putstr(va_arg(ap, char *));
	if (frmt == 'd' || frmt == 'i')
		x += ft_putnbr(va_arg(ap, int));
	if (frmt == 'u')
		x += ft_putnbr2(va_arg(ap, unsigned int));
	if (frmt == '%')
		x += ft_putchar('%');
	if (frmt == 'x' || frmt == 'X')
		x += ft_putnbr_base(va_arg(ap, unsigned int), frmt);
	if (frmt == 'p')
		x += ft_putadrs_base(va_arg(ap, unsigned long));
	return (x);
}

int	ft_printf(const char *format, ...)
{
	va_list	p;
	size_t	i;
	size_t	x;
	size_t	j;

	j = 0;
	x = 0;
	i = 0;
	va_start(p, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			j++;
			write(1, &format[i], 1);
		}
		else
		{
			i++;
			x += ft_printf_ots(format[i], p);
		}
		i++;
	}
	va_end(p);
	return (j + x);
}
