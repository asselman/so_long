/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:46:43 by aasselma          #+#    #+#             */
/*   Updated: 2022/11/01 15:28:28 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(int num)
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

int	ft_putnbr(int n)
{
	char	num;
	long	i;
	int		x;

	i = n;
	if (i < 0)
	{
		i = i * (-1);
		write(1, "-", 1);
	}
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
	x = ft_intlen(n);
	return (x);
}
