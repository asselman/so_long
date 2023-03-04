/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:29:49 by aasselma          #+#    #+#             */
/*   Updated: 2022/11/01 15:28:31 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen2(unsigned int num)
{
	int	x;

	x = 0;
	if (num <= 0)
		x++;
	while (num != 0)
	{
		num = num / 10;
		x++;
	}
	return (x);
}

int	ft_putnbr2(unsigned int n)
{
	char			num;
	unsigned int	i;
	int				x;

	i = n;
	if (i < 10)
	{
		num = i + '0';
		write(1, &num, 1);
	}
	else
	{
		ft_putnbr((i / 10));
		ft_putnbr((i % 10));
	}
	x = ft_intlen2(n);
	return (x);
}
