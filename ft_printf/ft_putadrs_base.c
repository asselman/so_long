/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrs_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:12:35 by aasselma          #+#    #+#             */
/*   Updated: 2022/11/01 15:28:20 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_adrslen(unsigned long num)
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

void	ft_put_adress(char *hex, unsigned long num)
{
	if (num < 16)
	{
		write(1, &hex[num], 1);
	}
	else
	{
		ft_put_adress(hex, (num / 16));
		ft_put_adress(hex, (num % 16));
	}	
}

int	ft_putadrs_base(unsigned long num)
{
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	len = ft_adrslen(num);
	write(1, "0x", 2);
	ft_put_adress(hex, num);
	return (len + 2);
}
