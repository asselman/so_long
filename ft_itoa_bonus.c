/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:54:05 by aasselma          #+#    #+#             */
/*   Updated: 2023/02/15 01:31:02 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_cal_len(long long num)
{
	int	i;

	i = 0;
	if (num <= 0)
		i++;
	while (num)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long		i;
	char		*alcmmry;
	long long	num;

	num = n;
	i = ft_cal_len(num);
	alcmmry = malloc(i + 1);
	alcmmry[i] = '\0';
	while (i - 1 >= 0)
	{
		alcmmry[i - 1] = num % 10 + '0';
		num = num / 10;
		if (num == 0)
			break ;
		i--;
	}
	return (alcmmry);
}
