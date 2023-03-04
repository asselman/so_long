/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:48:30 by aasselma          #+#    #+#             */
/*   Updated: 2022/11/01 15:28:26 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex(char	*hex, unsigned int n)
{
	if (n < 0)
	{
		n = n * (-1);
		write(1, "-", 1);
	}
	if (n < 16)
	{
		write(1, &hex[n], 1);
	}
	else
	{
		ft_put_hex(hex, (n / 16));
		ft_put_hex(hex, (n % 16));
	}
}

static int	ft_hexlen(unsigned int num)
{
	int	x;

	x = 0;
	if (num <= 0)
		x++;
	while (num != 0)
	{
		num = num / 16;
		x++;
	}
	return (x);
}

int	ft_putnbr_base(unsigned int num, char c)
{
	char	*lowerhex;
	char	*uphex;
	int		len;

	len = ft_hexlen(num);
	lowerhex = "0123456789abcdef";
	uphex = "0123456789ABCDEF";
	if (c == 'x')
		ft_put_hex(lowerhex, num);
	if (c == 'X')
		ft_put_hex(uphex, num);
	return (len);
}
